#pragma once

#ifndef __TIANYUSL_C_CPP_TOOLS__
#define __TIANYUSL_C_CPP_TOOLS__

#include"basedatatype.h"
#include"define.h"

#ifdef __cplusplus
__C__
{
#endif

void   __VAR__ Uint64ToBytes
(
    uint64 __VAR__ data,
    byte   __PTR__ buffer,
    int32  __VAR__ count
);
uint64 __VAR__ BytesToUint64
(
    byte   __PTR__ buffer,
    int32  __VAR__ count
);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUSL_C_CPP_TOOLS__