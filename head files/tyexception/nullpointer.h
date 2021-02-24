#pragma once

#ifndef __TIANYUSL_C_CPP_TYEXCEPTION_NULLPOINTER__
#define __TIANYUSL_C_CPP_TYEXCEPTION_NULLPOINTER__

#include"../define.h"
#include"../basedatatype.h"

namespace __TIANYU__
{
    namespace __EXCEPTION__
    {
        class NullPointerException : public Exception
        {
            _Public static const error __VAR__ Exception_NullPointer;

            _Private CStructString __PTR__ ErrorMessage;

            _Public obscure  NullPointerException();
            _Public obscure  NullPointerException
            (
                __IN_Param__ CStructString __PTR__ err_mess
            );
            _Public obscure  NullPointerException
            (
                __IN_Param__ char __PTR__ err_mess
            );
            _Public virtual ~NullPointerException();

            _Public virtual CStructString __PTR__ GetMessage();
        };
        const error __VAR__ NullPointerException::Exception_NullPointer = 0x10;

        class ArgumentNullPointerException final : public NullPointerException
        {
            _Public static const error __VAR__ Exception_ArgumentNullPointer;

            _Public obscure  ArgumentNullPointerException();
            _Public obscure  ArgumentNullPointerException
            (
                __IN_Param__ CStructString __PTR__ err_mess
            );
            _Public obscure  ArgumentNullPointerException
            (
                __IN_Param__ char __PTR__ err_mess
            );
            _Public virtual ~ArgumentNullPointerException();
        };
        const error __VAR__ ArgumentNullPointerException::Exception_ArgumentNullPointer = 0x11;
    }
}


#endif // !__TIANYUSL_C_CPP_TYEXCEPTION_NULLPOINTER__