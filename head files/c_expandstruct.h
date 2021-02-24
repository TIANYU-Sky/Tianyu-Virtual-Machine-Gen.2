#pragma once
#ifndef __TIANYU_C_EXPAND_STRUCT__
#define __TIANYU_C_EXPAND_STRUCT__

#include"define.h"
#include"basedatatype.h"

#ifdef __cplusplus

namespace __TIANYU__
{
    class IntegerPoint final
    {
        _Private uint64 __VAR__ _X;
        _Private uint64 __VAR__ _Y;

        _Public IntegerPoint
        (
            __IN_Param__ uint64 __VAR__ _x,
            __IN_Param__ uint64 __VAR__ _y
        ) :_X(_x), _Y(_y)
        {

        }
        _Public ~IntegerPoint() {  }

        _Public uint64 __VAR__ X() { return _X; }
        _Public uint64 __VAR__ Y() { return _Y; }
    };

    class Point final
    {
        _Private double __VAR__ _X;
        _Private double __VAR__ _Y;

        _Public Point
        (
            __IN_Param__ double __VAR__ _x,
            __IN_Param__ double __VAR__ _y
        ) :_X(_x), _Y(_y)
        {

        }
        _Public ~Point() {  }

        _Public double __VAR__ X() { return _X; }
        _Public double __VAR__ Y() { return _Y; }
    };
}

#else

typedef struct ipoint
{
    uint64  __VAR__ X;
    uint64  __VAR__ Y;
}IntegerPoint;

typedef struct fpoint
{
    double  __VAR__ X;
    double  __VAR__ Y;
}Point, FloatPoint;

#endif

#endif // !__TIANYU_C_EXPAND_STRUCT__