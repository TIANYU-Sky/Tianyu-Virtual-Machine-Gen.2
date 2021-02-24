#pragma once

#ifndef __TIANYUSL_C_CPP_TYEXCEPTION_UNREALIZED__
#define __TIANYUSL_C_CPP_TYEXCEPTION_UNREALIZED__

#include"../define.h"
#include"../basedatatype.h"

namespace __TIANYU__
{
    namespace __EXCEPTION__
    {
        class MethodNotImplementedException : public Exception
        {
            _Public static const error __VAR__ Exception_MethodNotImp;

            _Private CStructString __PTR__ ErrorMessage;

            _Public obscure  MethodNotImplementedException();
            _Public obscure  MethodNotImplementedException
            (
                __IN_Param__ CStructString __PTR__ err_mess
            );
            _Public obscure  MethodNotImplementedException
            (
                __IN_Param__ char __PTR__ err_mess
            );
            _Public virtual ~MethodNotImplementedException();

            _Public virtual CStructString __PTR__ GetMessage();
        };
        const error __VAR__ MethodNotImplementedException::Exception_MethodNotImp = 0x30;
    }
}


#endif // !__TIANYUSL_C_CPP_TYEXCEPTION_UNREALIZED__