/**
 * 用于天宇虚拟机系统IO系统定义
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMIO__
#define __TIANYUVM_C_CPP_TVMIO__

#include"../define.h"
#include"../basedatatype.h"
#include"collections.h"

#ifdef __cplusplus
__C__
{
#endif

#define __TYVM_IO_DEVICE_STATE_RUNNING__    0x00    // 天宇虚拟机IO设备状态值：正在运行（设备正在处理数据）
#define __TYVM_IO_DEVICE_STATE_FREE__       0x01    // 天宇虚拟机IO设备状态值：空闲（设备正在运行并无数据需要处理）
#define __TYVM_IO_DEVICE_STATE_STOPED__     0x02    // 天宇虚拟机IO设备状态值：设备已经停止运行
#define __TYVM_IO_DEVICE_STATE_PAUSED__     0x03    // 天宇虚拟机IO设备状态值：设备暂停（未关闭设备）
#define __TYVM_IO_DEVICE_STATE_ERROR__      0xFF    // 天宇虚拟机IO设备状态值：设备存在错误

typedef CStructString   __VAR__ (__PTR__ iodevice_describe)
(
    struct iodevice __PTR__ device
);
typedef void            __VAR__ (__PTR__ iodevice_out)
(
    struct iodevice __PTR__ device,
    uint64          __VAR__ data
);
typedef uint64          __VAR__ (__PTR__ iodevice_in)
(
    struct iodevice __PTR__ device
);
typedef byte            __VAR__ (__PTR__ iodevice_state)
(
    struct iodevice __PTR__ device
);
typedef void            __VAR__ (__PTR__ iodevice_pause)
(
    struct iodevice __PTR__ device
);
typedef void            __VAR__ (__PTR__ iodevice_resume)
(
    struct iodevice __PTR__ device
);
typedef void            __VAR__ (__PTR__ iodevice_stop)
(
    struct iodevice __PTR__ device
);
typedef void            __VAR__ (__PTR__ iodevice_start)
(
    struct iodevice __PTR__ device
);
typedef void            __VAR__ (__PTR__ iodevice_clerror)
(
    struct iodevice __PTR__ device
);
typedef void            __VAR__ (__PTR__ iodevice_reset)
(
    struct iodevice __PTR__ device
);

typedef struct iodevice
{
    iodevice_describe   __VAR__ GetDiscribe;

    iodevice_out        __VAR__ Out;
    iodevice_in         __VAR__ In;

    iodevice_state      __VAR__ State;

    iodevice_pause      __VAR__ Pause;
    iodevice_resume     __VAR__ Resume;
    iodevice_stop       __VAR__ Stop;
    iodevice_start      __VAR__ Start;
    iodevice_clerror    __VAR__ ClearError;
    iodevice_reset      __VAR__ Reset;
}IODevice;

typedef struct iodevice __PTR__ (__PTR__ iocontroller_getiodevice)
(
    struct iocontroller __PTR__ controller,
    uint64              __VAR__ device_code
);
typedef bool            __VAR__ (__PTR__ iocontroller_addiodevice)
(
    struct iocontroller __PTR__ controller,
    uint64              __VAR__ device_code,
    struct iodevice     __PTR__ device
);
typedef bool            __VAR__ (__PTR__ iocontroller_removedevice)
(
    struct iocontroller __PTR__ controller,
    uint64              __VAR__ device_code
);
typedef uint64          __VAR__ (__PTR__ iocontroller_devicescount)
(
    struct iocontroller __PTR__ controller
);

typedef struct iocontroller
{
    iocontroller_getiodevice    __VAR__ GetDevice;
    iocontroller_addiodevice    __VAR__ AddDevice;
    iocontroller_removedevice   __VAR__ RemoveDevice;
    iocontroller_devicescount   __VAR__ Count;
}IOController;

IOController __PTR__ CreateIOController();
void         __VAR__ DestroyIOController
(
    IOController __PTR__ controller
);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMIO__