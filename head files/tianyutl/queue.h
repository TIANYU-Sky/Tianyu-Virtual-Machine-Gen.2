#pragma once

#ifndef __C_CPP_TIANYUTL_QUEUE__
#define __C_CPP_TIANYUTL_QUEUE__

#ifdef __cplusplus

#include"../define.h"
#include"../basedatatype.h"
#include"../icollections.h"

namespace __TIANYU__
{
    template<typename T>
    class Queue final : public virtual Object, public virtual ICollections<T>
    {
        __Predefine__ _Private struct QueueNode;

        _Private int32      __VAR__ _Count;
        _Private QueueNode  __PTR__ _Head;
        _Private QueueNode  __PTR__ _End;

        _Public Queue();
        _Public virtual ~Queue();

        _Public void __VAR__ Enqueue
        (
            __IN_Param__ T __VAR__ elem
        );
        _Public T    __VAR__ Dequeue();
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

#endif // !__C_CPP_TIANYUTL_QUEUE__