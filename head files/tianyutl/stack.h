#pragma once

#ifndef __C_CPP_TIANYUTL_STACK__
#define __C_CPP_TIANYUTL_STACK__

#ifdef __cplusplus

#include"../define.h"
#include"../basedatatype.h"
#include"../icollections.h"

namespace __TIANYU__
{
    template<typename T>
    class Stack final : public virtual Object, public virtual ICollections<T>
    {
        __Predefine__ _Private struct StackNode;

        _Private int32      __VAR__ _Count;
        _Private StackNode  __PTR__ _Head;
        _Private StackNode  __PTR__ _End;

        _Public Stack();
        _Public virtual ~Stack();

        _Public void __VAR__ Push
        (
            __IN_Param__ T __VAR__ elem
        );
        _Public T    __VAR__ Pop();
        _Public T    __VAR__ Peek();

        _Public virtual int32   __VAR__ Count();
        _Public virtual bool    __VAR__ IsReadOnly();

        _Public virtual void    __VAR__ Add
        (
            __IN_Param__ T __VAR__ elem
        );
        _Public virtual void    __VAR__ Clear();
        _Public virtual bool    __VAR__ Contains
        (
            __IN_Param__ T __VAR__ elem
        );
        _Public virtual void    __VAR__ CopyTo
        (
            __IN_Param__ T      __PTR__ array,
            __IN_Param__ int32  __VAR__ len,
            __IN_Param__ int32  __VAR__ index
        );
        _Public virtual void    __VAR__ Remove
        (
            __IN_Param__ T __VAR__ elem
        );
    };
}

#endif

#endif // !__C_CPP_TIANYUTL_STACK__