/**
 * 用于天宇虚拟机系统的系统调用块
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMSYSTEM__
#define __TIANYUVM_C_CPP_TVMSYSTEM__

#include"../define.h"
#include"../basedatatype.h"
#include"tvmmemory.h"
#include"tvmio.h"
#include"tvmsysinterrupt.h"

#ifdef __cplusplus
__C__
{
#endif

__Predefine__ struct tvmsystem;

typedef uint64 __VAR__ (__PTR__ tvmsystem_device_access_in)
(
    struct tvmsystem    __PTR__ sys,
    uint64              __VAR__ dev
);
typedef void   __VAR__ (__PTR__ tvmsystem_device_access_out)
(
    struct tvmsystem    __PTR__ sys,
    uint64              __VAR__ dev,
    uint64              __VAR__ data
);
typedef void   __VAR__ (__PTR__ tvmsystem_interrupt)
(
    struct tvmsystem    __PTR__ sys,
    uint64              __VAR__ int_code,
    uint64              __VAR__ parms,
    uint64              __PTR__ result
);
typedef void   __VAR__ (__PTR__ tvmsystem_runningexception)
(
    struct tvmsystem    __PTR__ sys,
    uint64              __VAR__ exception,
    uint64              __VAR__ memory
);
typedef void   __VAR__ (__PTR__ tvmsystem_lock)
(
    struct tvmsystem    __PTR__ sys
);
typedef void   __VAR__ (__PTR__ tvmsystem_Unlock)
(
    struct tvmsystem    __PTR__ sys
);

typedef struct tvmsystem
{
    tvmsystem_lock              __VAR__ Lock;
    tvmsystem_Unlock            __VAR__ UnLock;

    tvmsystem_device_access_in  __VAR__ DeviceIn;
    tvmsystem_device_access_out __VAR__ DeviceOut;

    tvmsystem_interrupt         __VAR__ SysInterrupt;
    tvmsystem_runningexception  __VAR__ SysException;
}TVMSystem;

#define __TYVM_RUNNING_EXCEPTION_UNKNOWN_ERROR__            0x00
#define __TYVM_RUNNING_EXCEPTION_CPU_DECODER_ERROR__        0x01
#define __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__    0x02
#define __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__           0x10
#define __TYVM_RUNNING_EXCEPTION_NULL_POINTER__             0x11

TVMSystem __PTR__ CreateTVMSystem
(
    Memory          __PTR__ memory,
    IOController    __PTR__ controller
);
void      __VAR__ DestroyTVMSystem
(
    TVMSystem __PTR__ sys
);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMSYSTEM__