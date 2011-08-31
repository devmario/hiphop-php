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
// @generated by HipHop Compiler

#include <php/classes/soapfault.h>
#include <php/classes/soapfault.fws.h>

// Dependencies
#include <php/classes/exception.h>
#include <runtime/ext/ext.h>
#include <runtime/eval/eval.h>
namespace hphp_impl_starter {}

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_;
/* preface finishes */
/* SRC: classes/soapfault.php line 3 */
IMPLEMENT_CLASS_NO_DEFAULT_SWEEP(SoapFault)
const InstanceOfInfo c_SoapFault::s_instanceof_table[] = {
  {0x47D93E6F80B66A94LL,1,"Exception",&cw_Exception},
  {0x32E5C767255D2515LL,1,"SoapFault",&cw_SoapFault},
};
const int c_SoapFault::s_instanceof_index[] = {
  3,
  0,1,-1,-1,
};
CallInfo c_SoapFault::ci___tostring((void*)&c_SoapFault::i___tostring, (void*)&c_SoapFault::ifa___tostring, 0, 4, 0x0000000000000000LL);
CallInfo c_SoapFault::ci___construct((void*)&c_SoapFault::i___construct, (void*)&c_SoapFault::ifa___construct, 6, 4, 0x0000000000000000LL);
Variant c_SoapFault::i___tostring(MethodCallPackage &mcp, CArrRef params) {
  if (UNLIKELY(mcp.obj == 0)) {
    return ObjectData::i_dummy(mcp, params, i___tostring, coo_SoapFault);
  }
  c_SoapFault *self ATTRIBUTE_UNUSED (static_cast<c_SoapFault*>(mcp.obj));
  int count ATTRIBUTE_UNUSED = params.size();
  if (UNLIKELY(count > 0)) return throw_toomany_arguments("SoapFault::__toString", 0, 1);
  return (self->t___tostring());
}
Variant c_SoapFault::i___construct(MethodCallPackage &mcp, CArrRef params) {
  if (UNLIKELY(mcp.obj == 0)) {
    return ObjectData::i_dummy(mcp, params, i___construct, coo_SoapFault);
  }
  c_SoapFault *self ATTRIBUTE_UNUSED (static_cast<c_SoapFault*>(mcp.obj));
  int count ATTRIBUTE_UNUSED = params.size();
  if (UNLIKELY(count < 2 || count > 6)) return throw_wrong_arguments("SoapFault::__construct", count, 2, 6, 2);
  {
    ArrayData *ad(params.get());
    ssize_t pos = ad ? ad->iter_begin() : ArrayData::invalid_index;
    CVarRef arg0((ad->getValue(pos)));
    CVarRef arg1((ad->getValue(pos = ad->iter_advance(pos))));
    if (count <= 2) return (self->t___construct(arg0, arg1), null);
    CVarRef arg2((ad->getValue(pos = ad->iter_advance(pos))));
    if (count <= 3) return (self->t___construct(arg0, arg1, arg2), null);
    CVarRef arg3((ad->getValue(pos = ad->iter_advance(pos))));
    if (count <= 4) return (self->t___construct(arg0, arg1, arg2, arg3), null);
    CVarRef arg4((ad->getValue(pos = ad->iter_advance(pos))));
    if (count <= 5) return (self->t___construct(arg0, arg1, arg2, arg3, arg4), null);
    CVarRef arg5((ad->getValue(pos = ad->iter_advance(pos))));
    return (self->t___construct(arg0, arg1, arg2, arg3, arg4, arg5), null);
  }
}
Variant c_SoapFault::ifa___tostring(MethodCallPackage &mcp, int count, INVOKE_FEW_ARGS_IMPL_ARGS) {
  if (UNLIKELY(mcp.obj == 0)) {
    return ObjectData::ifa_dummy(mcp, count, INVOKE_FEW_ARGS_PASS_ARGS, ifa___tostring, coo_SoapFault);
  }
  c_SoapFault *self ATTRIBUTE_UNUSED (static_cast<c_SoapFault*>(mcp.obj));
  if (UNLIKELY(count > 0)) return throw_toomany_arguments("SoapFault::__toString", 0, 1);
  return (self->t___tostring());
}
Variant c_SoapFault::ifa___construct(MethodCallPackage &mcp, int count, INVOKE_FEW_ARGS_IMPL_ARGS) {
  if (UNLIKELY(mcp.obj == 0)) {
    return ObjectData::ifa_dummy(mcp, count, INVOKE_FEW_ARGS_PASS_ARGS, ifa___construct, coo_SoapFault);
  }
  c_SoapFault *self ATTRIBUTE_UNUSED (static_cast<c_SoapFault*>(mcp.obj));
  if (UNLIKELY(count < 2)) return throw_wrong_arguments("SoapFault::__construct", count, 2, 6, 2);
  CVarRef arg0(a0);
  CVarRef arg1(a1);
  if (count <= 2) return (self->t___construct(arg0, arg1), null);
  CVarRef arg2(a2);
  if (count <= 3) return (self->t___construct(arg0, arg1, arg2), null);
  CVarRef arg3(a3);
  if (count <= 4) return (self->t___construct(arg0, arg1, arg2, arg3), null);
  CVarRef arg4(a4);
  if (count <= 5) return (self->t___construct(arg0, arg1, arg2, arg3, arg4), null);
  CVarRef arg5(a5);
  return (self->t___construct(arg0, arg1, arg2, arg3, arg4, arg5), null);
}
const MethodCallInfoTable c_SoapFault::s_call_info_table[] = {
  { 0x642C2D2994B34A13LL, 1, 10, "__toString", &c_SoapFault::ci___tostring },
  { 0x0D31D0AC229C615FLL, 0, 11, "__construct", &c_SoapFault::ci___construct },
  { 0, 1, 0, 0 }
};
const int c_SoapFault::s_call_info_index[] = {
  3,
  -1,-1,-1,0,
};
c_SoapFault *c_SoapFault::create(CVarRef v_code, CVarRef v_message, CVarRef v_actor //  = null_variant
, CVarRef v_detail //  = null_variant
, CVarRef v_name //  = null_variant
, CVarRef v_header //  = null_variant
) {
  CountableHelper h(this);
  init();
  t___construct(v_code, v_message, v_actor, v_detail, v_name, v_header);
  return this;
}
const ObjectStaticCallbacks cw_SoapFault = {
  (ObjectData*(*)(ObjectData*))coo_SoapFault,
  c_SoapFault::s_call_info_table,c_SoapFault::s_call_info_index,
  c_SoapFault::s_instanceof_table,c_SoapFault::s_instanceof_index,
  &c_SoapFault::s_class_name,
  &c_SoapFault::os_prop_table,&c_SoapFault::ci___construct,0,&cw_Exception
};
/* SRC: classes/soapfault.php line 12 */
void c_SoapFault::t___construct(Variant v_code, Variant v_message, Variant v_actor //  = null
, Variant v_detail //  = null
, Variant v_name //  = null
, Variant v_header //  = null
) {
  INSTANCE_METHOD_INJECTION_BUILTIN(SoapFault, SoapFault::__construct);
  bool oldInCtor = gasInCtor(true);
  Variant v_fault_ns;
  Variant v_fault_code;
  int64 v_SOAP_1_1 = 0;
  int64 v_SOAP_1_2 = 0;
  String v_SOAP_1_1_ENV_NAMESPACE;
  String v_SOAP_1_2_ENV_NAMESPACE;
  int64 v_soap_version = 0;

  setNull(v_fault_ns);
  setNull(v_fault_code);
  if (x_is_string(v_code)) {
    {
      v_fault_code.assignVal(v_code);
    }
  }
  else {
    bool tmp0;
    {
      bool tmp1 = (x_is_array(v_code));
      if (tmp1) {
        int tmp2((x_count(v_code)));
        tmp1 = (equal(tmp2, 2LL));
      }
      tmp0 = (tmp1);
    }
    if (tmp0) {
      {
        {
          const Variant &tmp0((x_array_values(v_code)));
          v_code.assignVal(tmp0);
        }
        {
          const Variant &tmp0((v_code.rvalAt(0LL, AccessFlags::Error)));
          v_fault_ns.assignVal(tmp0);
        }
        {
          const Variant &tmp0((v_code.rvalAt(1LL, AccessFlags::Error)));
          v_fault_code.assignVal(tmp0);
        }
        if ((!(x_is_string(v_fault_ns)) || !(x_is_string(v_fault_code)))) {
          {
            x_hphp_throw_fatal_error(NAMSTR(s_sys_ss78960b67, "Invalid fault code"));
            {
              gasInCtor(oldInCtor);
              return;
            }
          }
        }
      }
    }
    else {
      {
        x_hphp_throw_fatal_error(NAMSTR(s_sys_ss78960b67, "Invalid fault code"));
        {
          gasInCtor(oldInCtor);
          return;
        }
      }
    }
  }
  m_faultcodens.assignVal(v_fault_ns);
  m_faultcode.assignVal(v_fault_code);
  if (empty(m_faultcode)) {
    {
      x_hphp_throw_fatal_error(NAMSTR(s_sys_ss78960b67, "Invalid fault code"));
      {
        gasInCtor(oldInCtor);
        return;
      }
    }
  }
  {
    Variant tmp0((m_message.assignVal(v_message)));
    m_faultstring.assignVal(tmp0);
  }
  m_faultactor.assignVal(v_actor);
  m_detail.assignVal(v_detail);
  m__name.assignVal(v_name);
  m_headerfault.assignVal(v_header);
  v_SOAP_1_1 = 1LL;
  v_SOAP_1_2 = 2LL;
  v_SOAP_1_1_ENV_NAMESPACE = NAMSTR(s_sys_ss3f0eec1a, "http://schemas.xmlsoap.org/soap/envelope/");
  v_SOAP_1_2_ENV_NAMESPACE = NAMSTR(s_sys_ssb0600dcf, "http://www.w3.org/2003/05/soap-envelope");
  {
    int64 tmp0((x__soap_active_version()));
    v_soap_version = tmp0;
  }
  if (empty(m_faultcodens)) {
    {
      if (equal(v_soap_version, v_SOAP_1_1)) {
        {
          if ((((equal(m_faultcode, NAMSTR(s_sys_ss971ea9d1, "Client")) || equal(m_faultcode, NAMSTR(s_sys_ss95d41015, "Server"))) || equal(m_faultcode, NAMSTR(s_sys_ssb7f9ce9a, "VersionMismatch"))) || equal(m_faultcode, NAMSTR(s_sys_ssf93fc318, "MustUnderstand")))) {
            {
              m_faultcodens = v_SOAP_1_1_ENV_NAMESPACE;
            }
          }
        }
      }
      else if (equal(v_soap_version, v_SOAP_1_2)) {
        {
          if (equal(m_faultcode, NAMSTR(s_sys_ss971ea9d1, "Client"))) {
            {
              m_faultcode = NAMSTR(s_sys_ssa8d233c8, "Sender");
              m_faultcodens = v_SOAP_1_2_ENV_NAMESPACE;
            }
          }
          else if (equal(m_faultcode, NAMSTR(s_sys_ss95d41015, "Server"))) {
            {
              m_faultcode = NAMSTR(s_sys_ss47955b0c, "Receiver");
              m_faultcodens = v_SOAP_1_2_ENV_NAMESPACE;
            }
          }
          else if (((equal(m_faultcode, NAMSTR(s_sys_ssb7f9ce9a, "VersionMismatch")) || equal(m_faultcode, NAMSTR(s_sys_ssf93fc318, "MustUnderstand"))) || equal(m_faultcode, NAMSTR(s_sys_ss3ff88d3e, "DataEncodingUnknown")))) {
            {
              m_faultcodens = v_SOAP_1_2_ENV_NAMESPACE;
            }
          }
        }
      }
    }
  }
  gasInCtor(oldInCtor);
}
namespace hphp_impl_splitter {}
/* SRC: classes/soapfault.php line 73 */
String c_SoapFault::t___tostring() {
  INSTANCE_METHOD_INJECTION_BUILTIN(SoapFault, SoapFault::__toString);
  return concat4(NAMSTR(s_sys_ss5d507d08, "SoapFault exception: ["), toString(m_faultcode), NAMSTR(s_sys_ss0a81fd6d, "] "), toString(m_faultstring));
}
namespace hphp_impl_splitter {}
ObjectData *coo_SoapFault() {
  return NEWOBJ(c_SoapFault)();
}

// Class tables
static const int64 cpt_static_inits[] = {
  (int64)&null_variant,
};
static const ClassPropTableEntry cpt_table_entries[] = {
  {0x223FBAE23D3926D1LL,6,0,0,68,10,GET_PROPERTY_OFFSET(c_SoapFault, m_faultcodens),&NAMSTR(s_sys_ssb9540e00, "faultcodens") },
  {0x6AB66433A5A06842LL,1,0,0,4,10,GET_PROPERTY_OFFSET(c_SoapFault, m_faultactor),&NAMSTR(s_sys_ss5b7cf41f, "faultactor") },
  {0x3B9257D5A7BFC952LL,2,0,0,68,10,GET_PROPERTY_OFFSET(c_SoapFault, m_detail),&NAMSTR(s_sys_ss2235bf3d, "detail") },
  {0x7F0FEC816F538D87LL,0,0,0,68,10,GET_PROPERTY_OFFSET(c_SoapFault, m_headerfault),&NAMSTR(s_sys_ss40793385, "headerfault") },
  {0x6C2E2F7FE9DC8A09LL,-1,0,0,68,10,GET_PROPERTY_OFFSET(c_SoapFault, m__name),&NAMSTR(s_sys_ssee3a4fdd, "_name") },
  {0x58CB312B3F4C8D8DLL,-5,0,0,4,10,GET_PROPERTY_OFFSET(c_SoapFault, m_faultcode),&NAMSTR(s_sys_ssff0553c0, "faultcode") },
  {0x6CDD9F7B80D687ADLL,-5,0,0,68,10,GET_PROPERTY_OFFSET(c_SoapFault, m_faultstring),&NAMSTR(s_sys_ssff4490ec, "faultstring") },

};
static const int cpt_hash_entries[] = {
  // SoapFault hash
  -1,0,1,-1,-1,-1,-1,3,-1,4,-1,-1,-1,5,-1,-1,
  // SoapFault lists
  -1,
  -1,
  -1,
};
const ClassPropTable c_SoapFault::os_prop_table = {
  15,5,-1,-1,-1,-1,17,0,
  cpt_hash_entries+0,&c_Exception::os_prop_table,cpt_table_entries+0,cpt_static_inits
};

///////////////////////////////////////////////////////////////////////////////
}
