/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include "runtime/vm/translator/hopt/nativecalls.h"

#include "runtime/vm/runtime.h"
#include "runtime/vm/translator/targetcache.h"
#include "runtime/vm/translator/translator-runtime.h"
#include "runtime/vm/translator/hopt/ir.h"

namespace HPHP { namespace VM { namespace JIT { namespace NativeCalls {

using namespace HPHP::VM::Transl;

static const SyncOptions SNone = kNoSyncPoint;
static const SyncOptions SSync = kSyncPoint;
static const SyncOptions SSyncAdj1 = kSyncPointAdjustOne;

/*
 * The table passed to s_callMap's constructor describes helpers calls
 * used by translated code. Each row consists of the following values:
 *
 * Opcode
 *   The opcode that uses the call
 * Func
 *   A value describing the function to call:
 *     (TCA)<function pointer> - Raw function pointer
 *     {FSSA, idx} - Use a const TCA from inst->getSrc(idx)
 * Dest
 *   DestType::SSA - The helper returns a single-register value
 *   DestType::TV  - The helper returns a TypedValue in two registers
 *   DestType::None - The helper does not return a value
 * SyncPoint
 *   SNone - The helper does not need a sync point
 *   SSync - The helper needs a normal sync point
 *   SSyncAdj1 - The helper needs a sync point that skips top of stack on unwind
 * Args
 *   A list of tuples describing the arguments to pass to the helper
 *     {SSA, idx} - Pass the value in inst->getSrc(idx)
 *     {TV, idx} - Pass the value in inst->getSrc(idx) as a
 *                 TypedValue, in two registers
 *     {VecKeyS, idx} - Like TV, but Str values are passed as a raw
 *                      StringData*, in a single register
 *     {VecKeyIS, idx} - Like VecKeyS, including Int
 */
static CallMap s_callMap({
    /* Opcode, Func, Dest, SyncPoint, Args */
    {AddElemStrKey,      (TCA)addElemStringKeyHelper, DestType::SSA, SNone,
                           {{SSA, 0}, {SSA, 1}, {TV, 2}}},
    {AddElemIntKey,      (TCA)addElemIntKeyHelper, DestType::SSA, SNone,
                           {{SSA, 0}, {SSA, 1}, {TV, 2}}},
    {AddNewElem,         (TCA)&HphpArray::AddNewElemC, DestType::SSA, SNone,
                           {{SSA, 0}, {TV, 1}}},
    {ArrayAdd,           (TCA)array_add, DestType::SSA, SNone,
                           {{SSA, 0}, {SSA, 1}}},
    {Box,                (TCA)box_value, DestType::SSA, SNone, {{TV, 0}}},
    {LdObjMethod,        (TCA)TargetCache::MethodCache::lookup,
                           DestType::SSA, SSync,
                           {{SSA, 0}, {SSA, 2}, {SSA, 1}}},
    {NewArray,           (TCA)new_array, DestType::SSA, SNone, {{SSA, 0}}},
    {NewTuple,           (TCA)new_tuple, DestType::SSA, SNone,
                           {{SSA, 0}, {SSA, 1}}},
    {PrintStr,           (TCA)print_string, DestType::None, SNone, {{SSA, 0}}},
    {PrintInt,           (TCA)print_int, DestType::None, SNone, {{SSA, 0}}},
    {PrintBool,          (TCA)print_boolean, DestType::None, SNone, {{SSA, 0}}},
    {RaiseUninitLoc,     (TCA)raiseUndefVariable, DestType::None, SSync,
                           {{SSA, 0}}},

    /* Switch helpers */
    {LdSwitchDblIndex,   (TCA)switchDoubleHelper, DestType::SSA, SSync,
                           {{SSA, 0}, {SSA, 1}, {SSA, 2}}},
    {LdSwitchStrIndex,   (TCA)switchStringHelper, DestType::SSA, SSync,
                           {{SSA, 0}, {SSA, 1}, {SSA, 2}}},
    {LdSwitchObjIndex,   (TCA)switchObjHelper, DestType::SSA, SSync,
                           {{SSA, 0}, {SSA, 1}, {SSA, 2}}},

    /* Continuation support helpers */
    {CreateCont,         {FSSA, 0}, DestType::SSA, SNone,
                           {{SSA, 0}, {SSA, 1}, {SSA, 2}, {SSA, 3}, {SSA, 4}}},
    {FillContLocals, (TCA)&VMExecutionContext::fillContinuationVars,
              DestType::None, SNone,
              {{SSA, 0}, {SSA, 1}, {SSA, 2}, {SSA, 3}, {SSA, 4}}},

    /* VectorTranslator helpers */
    {BaseG,    {FSSA, 0}, DestType::SSA, SSync, {{TV, 1}, {SSA, 2}}},
    {PropX,    {FSSA, 0}, DestType::SSA, SSync,
                 {{SSA, 1}, {SSA, 2}, {VecKeyS, 3}, {SSA, 4}}},
    {CGetProp, {FSSA, 0}, DestType::TV, SSync,
                 {{SSA, 1}, {SSA, 2}, {VecKeyS, 3}, {SSA, 4}}},
    {SetProp,  {FSSA, 0}, DestType::TV, SSync,
                 {{SSA, 1}, {SSA, 2}, {VecKeyS, 3}, {TV, 4}}},
    {ElemX,    {FSSA, 0}, DestType::SSA, SSync,
                 {{SSA, 1}, {VecKeyIS, 2}, {SSA, 3}}},
    {ElemDX,   {FSSA, 0}, DestType::SSA, SSync,
                 {{SSA, 1}, {VecKeyIS, 2}, {SSA, 3}}},
    {CGetElem, {FSSA, 0}, DestType::TV, SSync,
                 {{SSA, 1}, {VecKeyIS, 2}, {SSA, 3}}},
    {SetElem,  {FSSA, 0}, DestType::TV, SSync,
                 {{SSA, 1}, {VecKeyIS, 2}, {TV, 3}}},
    {SetNewElem, (TCA)setNewElem, DestType::TV, SSync, {{SSA, 0}, {TV, 1}}},
    {IssetElem,{FSSA, 0}, DestType::SSA, SSync,
                 {{SSA, 1}, {VecKeyIS, 2}, {SSA, 3}}},
    {EmptyElem,{FSSA, 0}, DestType::SSA, SSync,
                 {{SSA, 1}, {VecKeyIS, 2}, {SSA, 3}}},

    /* debug assert helpers */
    {DbgAssertPtr, (TCA)assertTv, DestType::None, SNone, {{SSA, 0}}},
});

CallMap::CallMap(CallInfoList infos) {
  for (auto const& info : infos) {
    m_map[info.op] = info;
  }
}

bool CallMap::hasInfo(Opcode op) {
  return mapContains(s_callMap.m_map, op);
}

const CallInfo& CallMap::getInfo(Opcode op) {
  auto it = s_callMap.m_map.find(op);
  assert(it != s_callMap.m_map.end());
  return it->second;
}

} } } }
