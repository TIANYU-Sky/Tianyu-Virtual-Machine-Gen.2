/**
 * 用于天宇虚拟机系统的CPU核心定义模块
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMCPUCORE__
#define __TIANYUVM_C_CPP_TVMCPUCORE__

#include"../define.h"
#include"../basedatatype.h"
#include"tvmsystem.h"

#define __FPU_REGISTER_SIZE__       8
#define __GENERAL_REGISTER_SIZE__   16

#define __TYVM_CPU_EXCUTE__	true
#define __TYVM_CPU_STOP__	false

#ifdef __cplusplus
__C__
{
#endif

__Predefine__ struct cpu;

//
// 获取操作地址
//
typedef uint64 __VAR__ (__PTR__ cpu_method_getmemaddress)
(
    struct cpu  __PTR__ cpu_dev,            // CPU对象
    int8        __VAR__ segment,            // 指定的段寄存器
    int8        __VAR__ reg,                // 指定的寄存器
    bool        __VAR__ base_state,         // 指示基址寄存器是否有效
    int8        __VAR__ base_reg,           // 指定基址寄存器
    int8        __VAR__ base_times,         // 指示基址倍率
    bool        __VAR__ offset_state,       // 指示是否存在偏移量
    uint64      __VAR__ offset              // 提供偏移量
);

//
// CPU组件
//
typedef struct cpu
{
    uint64 __VAR__ ThreadCode;      // 当前线程号
    uint64 __VAR__ ProgressCode;    // 当前进程号
    uint64 __VAR__ StackTop;        // 当前程序的堆栈最大栈顶
    uint64 __VAR__ StackBottom;     // 当前程序的堆栈最小栈底

    uint64 __VAR__ CS;          // 代码段寄存器
    uint64 __VAR__ SS;          // 堆栈段寄存器
    uint64 __VAR__ DS;          // 数据段寄存器（保留）
    uint64 __VAR__ ES;          // 拓展段寄存器（保留）
    uint64 __VAR__ GS;          // 拓展段寄存器（保留）

    uint64 __VAR__ FLAGREG;     // 标志寄存器

    uint64 __VAR__ IP;          // 指令指针（段CS）

    uint64 __VAR__ GREG[__GENERAL_REGISTER_SIZE__]; // 通用寄存器组

    double __VAR__ ST[__FPU_REGISTER_SIZE__];       // 浮点寄存器堆栈
    byte   __VAR__ STP;                             // 浮点寄存器堆栈指针
    
    TVMSystem __PTR__ System;       // 系统组件指针

    cpu_method_getmemaddress __VAR__ CalculateMemory;    // 计算指令所需的内存位置
}CPU;

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMCPUCORE__