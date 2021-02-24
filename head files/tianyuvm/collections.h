#pragma once

#ifndef __TIANYUVM_C_CPP_DICTIONARY__
#define __TIANYUVM_C_CPP_DICTIONARY__

#include"../define.h"
#include"../basedatatype.h"

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

/**
 * 设备表
 * 用于保存当前系统中可用的设备
*/

#define __DEVICE_ADD_RESULT_SECCUSS__   true
#define __DEVICE_ADD_RESULT_FAILED__    false

#define __DEVICE_REMOVE_RESULT_SECCUSS__   true
#define __DEVICE_REMOVE_RESULT_FAILED__    false

__Predefine__ struct iodevice;
__Predefine__ struct iocontroller;

__Predefine__ struct devicelistnode;
__Predefine__ struct devicelist;

typedef struct iodevice __PTR__ (__PTR__ devicelist_getiodevice)
(
    struct devicelist   __PTR__ device_list,
    uint64              __VAR__ device_code
);
typedef bool            __VAR__ (__PTR__ devicelist_addiodevice)
(
    struct devicelist   __PTR__ device_list,
    uint64              __VAR__ device_code,
    struct iodevice     __PTR__ device
);
typedef bool            __VAR__ (__PTR__ devicelist_removedevice)
(
    struct devicelist   __PTR__ device_list,
    uint64              __VAR__ device_code
);
typedef uint64          __VAR__ (__PTR__ devicelist_devicecount)
(
    struct devicelist   __PTR__ device_list
);

typedef struct devicelist
{   
    devicelist_addiodevice  __VAR__ AddDevice;
    devicelist_getiodevice  __VAR__ GetDevice;
    devicelist_removedevice __VAR__ RemoveDevice;
    devicelist_devicecount  __VAR__ Count;
}DeviceList;

DeviceList __PTR__ CreateDeviceList();
void       __VAR__ DestroyDeviceList
(
    DeviceList __PTR__ device_list
);

/**
 * 网络表
 * 用于保存当前进程所分配的所有堆中的内存
*/

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_DICTIONARY__