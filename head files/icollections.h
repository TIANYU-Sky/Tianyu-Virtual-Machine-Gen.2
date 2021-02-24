#pragma once

#ifndef __TIANYUSL_C_CPP_ICOLLECTIONS__
#define __TIANYUSL_C_CPP_ICOLLECTIONS__

#ifdef __cplusplus

#include"define.h"
#include"basedatatype.h"

namespace __TIANYU__
{
    template<class T>
    _interface IEnumerable
    {

    };

    template<typename T>
    _interface ICollections : public virtual Object
    {
        _Public virtual int32   __VAR__ Count() = 0;
        _Public virtual bool    __VAR__ IsReadOnly() = 0;

        _Public virtual void    __VAR__ Add
        (
            __IN_Param__ T __VAR__ elem
        ) = 0;
        _Public virtual void    __VAR__ Clear() = 0;
        _Public virtual bool    __VAR__ Contains
        (
            __IN_Param__ T __VAR__ elem
        ) = 0;
        _Public virtual void    __VAR__ CopyTo
        (
            __IN_Param__ T      __PTR__ array,
            __IN_Param__ int32  __VAR__ len,
            __IN_Param__ int32  __VAR__ index
        ) = 0;
        _Public virtual void    __VAR__ Remove
        (
            __IN_Param__ T __VAR__ elem
        ) = 0;
    };
}

#endif

#endif // !__TIANYUSL_C_CPP_ICOLLECTIONS__