#pragma once

#ifndef __TIANYUSL_C_CPP_TYEXCEPTION_OUTBOUNDARY__
#define __TIANYUSL_C_CPP_TYEXCEPTION_OUTBOUNDARY__

#include"../define.h"
#include"../basedatatype.h"

namespace __TIANYU__
{
    namespace __EXCEPTION__
    {
        class OutOfBoundaryException : public Exception
        {
            _Public static const error __VAR__ Exception_OutBoundary;

            _Private CStructString __PTR__ ErrorMessage;

            _Public obscure  OutOfBoundaryException();
            _Public obscure  OutOfBoundaryException
            (
                __IN_Param__ CStructString __PTR__ err_mess
            );
            _Public obscure  OutOfBoundaryException
            (
                __IN_Param__ char __PTR__ err_mess
            );
            _Public virtual ~OutOfBoundaryException();

            _Public virtual CStructString __PTR__ GetMessage();
        };
        const error __VAR__ OutOfBoundaryException::Exception_OutBoundary = 0x20;

        class ArgumentOutOfBoundaryException final : public OutOfBoundaryException
        {
            _Public static const error __VAR__ Exception_ArgumentOutBoundary;

            _Public obscure  ArgumentOutOfBoundaryException();
            _Public obscure  ArgumentOutOfBoundaryException
            (
                __IN_Param__ CStructString __PTR__ err_mess
            );
            _Public obscure  ArgumentOutOfBoundaryException
            (
                __IN_Param__ char __PTR__ err_mess
            );
            _Public virtual ~ArgumentOutOfBoundaryException();
        };
        const error __VAR__ ArgumentOutOfBoundaryException::Exception_ArgumentOutBoundary = 0x21;

        class ArrayOutOfBoundaryException final : public OutOfBoundaryException
        {
            _Public static const error __VAR__ Exception_ArrayOutBoundary;

            _Public obscure  ArrayOutOfBoundaryException();
            _Public obscure  ArrayOutOfBoundaryException
            (
                __IN_Param__ CStructString __PTR__ err_mess
            );
            _Public obscure  ArrayOutOfBoundaryException
            (
                __IN_Param__ char __PTR__ err_mess
            );
            _Public virtual ~ArrayOutOfBoundaryException();
        };
        const error __VAR__ ArrayOutOfBoundaryException::Exception_ArrayOutBoundary = 0x22;
    }
}


#endif // !__TIANYUSL_C_CPP_TYEXCEPTION_OUTBOUNDARY__