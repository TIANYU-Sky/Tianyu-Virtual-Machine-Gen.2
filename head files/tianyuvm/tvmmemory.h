/**
 * 用于天宇虚拟机系统的内存模块
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMMEMORY__
#define __TIANYUVM_C_CPP_TVMMEMORY__

#include"../define.h"
#include"../basedatatype.h"
#include<process.h>
#include<windows.h>

#define __MEMORY_ACCESS_READONLY__  1
#define __MEMORY_ACCESS_READWRITE__ 2
#define __MEMORY_ACCESS_NOACCESS__  3

#define __MEMORY_DEVICE_CACHE_SIZE__ 16

#ifdef __cplusplus
__C__
{
#endif

__Predefine__ struct memorydevice;

typedef uint64 __VAR__ (__PTR__ memorydevicefun_apply)
(
    struct memorydevice __PTR__ mem_dev,
    int32               __VAR__ size
);
typedef void   __VAR__ (__PTR__ memorydevicefun_destroy)
(
    struct memorydevice __PTR__ mem_dev,
    uint64              __VAR__ addr
);

// 内存模块
typedef struct memorydevice
{
    memorydevicefun_apply   __VAR__ Apply;      // 内存分配方法
    memorydevicefun_destroy __VAR__ Destroy;    // 内存销毁方法
}Memory;

Memory __PTR__ CreateMemoryObject 
(
    string __VAR__ init_data, 
    int32  __VAR__ length
);
void   __VAR__ DestroyMemoryObject
(
    Memory __PTR__ memory
);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMMEMORY__