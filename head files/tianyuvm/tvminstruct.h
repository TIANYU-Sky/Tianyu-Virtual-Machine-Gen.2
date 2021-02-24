/**
 * 用于天宇虚拟机系统的指令系统
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMINSTRUCT__
#define __TIANYUVM_C_CPP_TVMINSTRUCT__

#include"../define.h"
#include"../basedatatype.h"
#include"tvminstdefine.h"
#include"tvmcpucore.h"

#define __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__    0x00    // 指令集第一操作数寻址方式：寄存器操作数
#define __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_IMM__    0x01    // 指令集第一操作数寻址方式：立即数操作数
#define __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_MEM__    0x02    // 指令集第一操作数寻址方式：内存寻址

#define __INSTRUCTION_PACKAGE_OPONE_REG_INVAILD__       0xFF   // 指令集第一操作数寄存器无效

#ifdef __cplusplus
__C__
{
#endif

//
// 指令包结构体预定义
//
__Predefine__ struct instructionpackage;

#define __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__ 0x00
#define __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__  0x02

//
// 指令执行方法委托
// 返回执行状态标志
//
typedef byte __VAR__ (__PTR__ instructionpackage_run)
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
);

//
// 指令集第一操作数结构体
//
typedef struct instructionpackageopone
{
    int8    __VAR__ _Addressing;            // 用于指定第一操作数的寻址方式
    int8    __VAR__ _Reg_Expand;            // 用于指定第一操作数中的寄存器/拓展码

    bool    __VAR__ _BaseAddrState;         // 当寻址方式为拓展时 指示基址寄存器是否有效
    int8    __VAR__ _BaseAddrReg;           // 当寻址方式为拓展且基址寄存器有效时 指定基址寄存器
    int8    __VAR__ _BaseAddrTimes;         // 当寻址方式为拓展时 指示基址倍率
    bool    __VAR__ _BaseAddrOffsetFlag;    // 当寻址方式为拓展时 指示是否存在偏移量

    uint64  __VAR__ _Imm_Offset;            // 当寻址方式为立即数（直接/间接）时 提供立即数 当寻址方式为拓展时 提供偏移量
}InstructionPackageOPOne;

//
// 指令集第二操作数结构体
//
typedef struct instructionpackageoptwo
{
    int8    __VAR__ _OPType;    // 用于指定第二操作数的类型
    uint64  __VAR__ _Reg_Imm;   // 用于指定所使用的寄存器或立即数
}InstructionPackageOPTwo;

//
// 指令集包结构体实现
//
typedef struct instructionpackage
{
    bool __VAR__ _Lock;         // 指定当前指令执行时的内存是否上锁
    bool __VAR__ _OPDirect;     // 指定当前指令执行时的操作数方向
    int8 __VAR__ _Segment;      // 指定指令执行时的段寄存器
    int8 __VAR__ _OPNumber;     // 指定当前指令的运算大小（8，16，32，64）

    instructionpackage_run  __VAR__ Run;     // 指令运行方法
    
    InstructionPackageOPOne __PTR__ _OPOne; // 指定当前第一操作数
    InstructionPackageOPTwo __PTR__ _OPTwo; // 指定当前第二操作数
}InstructionPackage;

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMINSTRUCT__