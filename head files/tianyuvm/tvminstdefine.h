/**
 * 用于天宇虚拟机系统的系统调用块
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMINSTDEFINE__
#define __TIANYUVM_C_CPP_TVMINSTDEFINE__

#include"../define.h"

#define __INSTRUCTION_LOCK_STATE_TEST__                 0b01        // 测试指令锁状态
#define __INSTRUCTION_LOCK_STATE_LOCK__                 true        // 指定当前指令启动内存锁
#define __INSTRUCTION_LOCK_STATE_UNLOCK__               false       // 指定当前指定不开启内存锁

#define __INSTRUCTION_OPDIRECT_TEST__                   0b10        // 测试指令运算方向
#define __INSTRUCTION_OPDIRECT_ONE_TO_TWO__             false       // 指定当前指令运算方向为 第一操作数→第二操作数
#define __INSTRUCTION_OPDIRECT_TWO_TO_ONE__             true        // 指定当前指令运算方向为 第二操作数→第一操作数

#define __INSTRUCTION_SEGMENT_DEFAULTSEG__              0b111       // 指令段寄存器编码 默认寄存器
#define __INSTRUCTION_SEGMENT_CODESEG__                 0b001       // 指令段寄存器编码 CS
#define __INSTRUCTION_SEGMENT_DATASEG__                 0b010       // 指令段寄存器编码 DS
#define __INSTRUCTION_SEGMENT_STACKSEG__                0b011       // 指令段寄存器编码 SS
#define __INSTRUCTION_SEGMENT_EXPANDSEG__               0b100       // 指令段寄存器编码 ES
#define __INSTRUCTION_SEGMENT_NULL__                    0x000       // 指令段寄存器编码 无段寄存器

#define __INSTRUCTION_OPNUMBER_64__                     0b00        // 指定操作数大小64位
#define __INSTRUCTION_OPNUMBER_32__                     0b01        // 指定操作数大小32位
#define __INSTRUCTION_OPNUMBER_16__                     0b10        // 指定操作数大小16位
#define __INSTRUCTION_OPNUMBER_8__                      0b11        // 指定操作数大小8位

#define __INSTRUCTION_ADDRESSING_OTHER__                0b00        // 指定指令寻址方式 其他寻址
#define __INSTRUCTION_ADDRESSING_REG_DIRECT__           0b01        // 指定指令寻址方式 寄存器直接寻址
#define __INSTRUCTION_ADDRESSING_IMM_INDIRECT__         0b10        // 指定指令寻址方式 立即数间接寻址
#define __INSTRUCTION_ADDRESSING_IMM_DIRECT__           0b11        // 指定指令寻址方式 直接立即数

#define __INSTRUCTION_OPNUM_IMM_SIZE_64__               0b1000      // 指定立即操作数后缀的长度 64位
#define __INSTRUCTION_OPNUM_IMM_SIZE_32__               0b0100      // 指定立即操作数后缀的长度 32位
#define __INSTRUCTION_OPNUM_IMM_SIZE_16__               0b0010      // 指定立即操作数后缀的长度 16位
#define __INSTRUCTION_OPNUM_IMM_SIZE_8__                0b0001      // 指定立即操作数后缀的长度 8位

#define __INSTRUCTION_OPONE_BASE_ADDR_STATE_VAILD__     true        // 在寻址模式为其他寻址时 指示基址寄存器有效
#define __INSTRUCTION_OPONE_BASE_ADDR_STATE_INVAILD__   false       // 在寻址模式为其他寻址时 指示基址寄存器无效

#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_1__         0b00        // 在寻址模式为其他寻址时 指示基址寄存器相对倍率1倍
#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_2__         0b01        // 在寻址模式为其他寻址时 指示基址寄存器相对倍率2倍
#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_4__         0b10        // 在寻址模式为其他寻址时 指示基址寄存器相对倍率4倍
#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_8__         0b11        // 在寻址模式为其他寻址时 指示基址寄存器相对倍率8倍
#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_TEST__      0b11        // 在寻址模式为其他寻址时 测试相对倍率

#define __INSTRUCTION_OPONE_BASE_ADDR_OFFSET_VAILD__    true        // 在寻址模式为其他寻址时 指示基址寄存器相对偏移量有效
#define __INSTRUCTION_OPONE_BASE_ADDR_OFFSET_INVAILD__  false       // 在寻址模式为其他寻址时 指示基址寄存器相对偏移量无效

#define __INSTRUCTION_SECOND_OPTYPE_NONE__              0b00        // 指定第二操作数类型 无第二操作数
#define __INSTRUCTION_SECOND_OPTYPE_REG__               0b01        // 指定第二操作数类型 寄存器操作数
#define __INSTRUCTION_SECOND_OPTYPE_IMM__               0b10        // 指定第二操作数类型 立即数
#define __INSTRUCTION_SECOND_OPTYPE_EXP__               0b11        // 指定第二操作数类型 拓展类型（当前不使用）
#define __INSTRUCTION_SECOND_OPTYPE_TEST__              0b11        // 指定第二操作数类型 测试

#define __TYVM_SIGNREGISTER_CARRY_FLAG__    0b0000000000000001   // 天宇虚拟机 标志寄存器 进位标志位
#define __TYVM_SIGNREGISTER_PARITY_FLAG__   0b0000000000000100   // 天宇虚拟机 标志寄存器 奇偶标志位
#define __TYVM_SIGNREGISTER_ZERO_FLAG__     0b0000000001000000   // 天宇虚拟机 标志寄存器 零标志定位
#define __TYVM_SIGNREGISTER_SIGN_FLAG__     0b0000000010000000   // 天宇虚拟机 标志寄存器 符号标志定位
#define __TYVM_SIGNREGISTER_OVERFLOW_FLAG__ 0b0000100000000000   // 天宇虚拟机 标志寄存器 溢出标志位

#define __TYVM_SIGN_DISTINGUISH_NUM__   0x8000000000000000 // 天宇虚拟机 符号判别符

#define __TYVM_REGISTER_RAX__   0b0000  // 天宇虚拟机指令集 寄存器编码 RAX 累加寄存器
#define __TYVM_REGISTER_RBX__   0b0001  // 天宇虚拟机指令集 寄存器编码 RBX 基址寄存器
#define __TYVM_REGISTER_RCX__   0b0010  // 天宇虚拟机指令集 寄存器编码 RCX 计数寄存器
#define __TYVM_REGISTER_RDX__   0b0011  // 天宇虚拟机指令集 寄存器编码 RDX 数据寄存器
#define __TYVM_REGISTER_RSP__   0b0100  // 天宇虚拟机指令集 寄存器编码 RSP 栈指针寄存器
#define __TYVM_REGISTER_RBP__   0b0101  // 天宇虚拟机指令集 寄存器编码 RBP 基址指针寄存器
#define __TYVM_REGISTER_RSI__   0b0110  // 天宇虚拟机指令集 寄存器编码 RSI 源址寄存器
#define __TYVM_REGISTER_RDI__   0b0111  // 天宇虚拟机指令集 寄存器编码 RDI 目的地址寄存器
#define __TYVM_REGISTER_R8__    0b1000  // 天宇虚拟机指令集 寄存器编码 R8 通用寄存器
#define __TYVM_REGISTER_R9__    0b1001  // 天宇虚拟机指令集 寄存器编码 R9 通用寄存器
#define __TYVM_REGISTER_R10__   0b1010  // 天宇虚拟机指令集 寄存器编码 R10 通用寄存器
#define __TYVM_REGISTER_R11__   0b1011  // 天宇虚拟机指令集 寄存器编码 R11 通用寄存器
#define __TYVM_REGISTER_R12__   0b1100  // 天宇虚拟机指令集 寄存器编码 R12 通用寄存器
#define __TYVM_REGISTER_R13__   0b1101  // 天宇虚拟机指令集 寄存器编码 R13 通用寄存器
#define __TYVM_REGISTER_R14__   0b1110  // 天宇虚拟机指令集 寄存器编码 R14 通用寄存器
#define __TYVM_REGISTER_R15__   0b1111  // 天宇虚拟机指令集 寄存器编码 R15 通用寄存器

#define __TYVM_REGISTER_ST_TEST__ 0x07  // 天宇虚拟机指令集 寄存器编码 ST浮点堆栈寄存器测试

#define __TYVM_REGISTER_ST0__   0b0000  // 天宇虚拟机指令集 寄存器编码 ST(0)浮点堆栈寄存器
#define __TYVM_REGISTER_ST1__   0b0001  // 天宇虚拟机指令集 寄存器编码 ST(1)浮点堆栈寄存器
#define __TYVM_REGISTER_ST2__   0b0010  // 天宇虚拟机指令集 寄存器编码 ST(2)浮点堆栈寄存器
#define __TYVM_REGISTER_ST3__   0b0011  // 天宇虚拟机指令集 寄存器编码 ST(3)浮点堆栈寄存器
#define __TYVM_REGISTER_ST4__   0b0100  // 天宇虚拟机指令集 寄存器编码 ST(4)浮点堆栈寄存器
#define __TYVM_REGISTER_ST5__   0b0101  // 天宇虚拟机指令集 寄存器编码 ST(5)浮点堆栈寄存器
#define __TYVM_REGISTER_ST6__   0b0110  // 天宇虚拟机指令集 寄存器编码 ST(6)浮点堆栈寄存器
#define __TYVM_REGISTER_ST7__   0b0111  // 天宇虚拟机指令集 寄存器编码 ST(7)浮点堆栈寄存器

#define __TYVM_REGISTER_MMX0__   0b1000  // 天宇虚拟机指令集 寄存器编码 MMX(0)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TYVM_REGISTER_MMX1__   0b1001  // 天宇虚拟机指令集 寄存器编码 MMX(1)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TYVM_REGISTER_MMX2__   0b1010  // 天宇虚拟机指令集 寄存器编码 MMX(2)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TYVM_REGISTER_MMX3__   0b1011  // 天宇虚拟机指令集 寄存器编码 MMX(3)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TYVM_REGISTER_MMX4__   0b1100  // 天宇虚拟机指令集 寄存器编码 MMX(4)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TYVM_REGISTER_MMX5__   0b1101  // 天宇虚拟机指令集 寄存器编码 MMX(5)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TYVM_REGISTER_MMX6__   0b1110  // 天宇虚拟机指令集 寄存器编码 MMX(6)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TYVM_REGISTER_MMX7__   0b1111  // 天宇虚拟机指令集 寄存器编码 MMX(7)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）

#define __TYVM_REG_IMM_TEST__   0b1111  // 天宇虚拟机指令集 寄存器测试

#define __TYVM_INSTRUCTION_PREFIX_TEST__        0xF0    // 天宇虚拟机指令集 前缀测试编码
#define __TYVM_INSTRUCTION_PREFIX_FUNCTION__    0x90    // 天宇虚拟机指令集 功能前缀（包含Lock功能、操作数方向、操作数大小）
#define __TYVM_INSTRUCTION_PREFIX_REGISTER__    0x60    // 天宇虚拟机指令集 寄存器前缀 指示当前指令所参照的段寄存器


#define _USE_MATH_DEFINES
#define M_LOG10_2   0.30102999566398119521373889472449 // log10(2)
#define M_LOG2_10   3.3219280948873623478703194294894  // log2(10) 


/**
 * 天宇虚拟机指令集及其编码
*/

#define __TYVM_INSTRUCTION_OPNUM_TEST__     0xF0    // 天宇虚拟机操作数测试
#define __TYVM_INSTRUCTION_OPNUM_ZERO_A__   0x00
#define __TYVM_INSTRUCTION_OPNUM_ZERO_B__   0x10
#define __TYVM_INSTRUCTION_OPNUM_ZERO_C__   0xD0
#define __TYVM_INSTRUCTION_OPNUM_ONE_A__    0x20
#define __TYVM_INSTRUCTION_OPNUM_ONE_B__    0x30
#define __TYVM_INSTRUCTION_OPNUM_ONE_C__    0x40
#define __TYVM_INSTRUCTION_OPNUM_ONE_D__    0x50
#define __TYVM_INSTRUCTION_OPNUM_ONE_E__    0xE0
#define __TYVM_INSTRUCTION_OPNUM_ONE_F__    0xF0
#define __TYVM_INSTRUCTION_OPNUM_TWO_A__    0xA0
#define __TYVM_INSTRUCTION_OPNUM_TWO_B__    0xB0
#define __TYVM_INSTRUCTION_OPNUM_TWO_C__    0xC0

#define __TYVM_INSTRUCTION_NOP__        0x00    // 天宇虚拟机指令集编码 空指令
#define __TYVM_INSTRUCTION_STC__        0x01    // 天宇虚拟机指令集编码 设置标志寄存器 进位标志位为1
#define __TYVM_INSTRUCTION_CLC__        0x02    // 天宇虚拟机指令集编码 设置标志寄存器 进位标志位为0
#define __TYVM_INSTRUCTION_CMC__        0x03    // 天宇虚拟机指令集编码 设置标志寄存器 进位标志位取反
#define __TYVM_INSTRUCTION_RET__        0x04    // 天宇虚拟机指令集编码 过程返回
#define __TYVM_INSTRUCTION_IRET__       0x05    // 天宇虚拟机指令集编码 中断返回（当前为空指令）
#define __TYVM_INSTRUCTION_PUSHF__      0x06    // 天宇虚拟机指令集编码 将64位标志寄存器推入栈中
#define __TYVM_INSTRUCTION_POPF__       0x07    // 天宇虚拟机指令集编码 将栈顶64位数据弹出至标志寄存器
#define __TYVM_INSTRUCTION_PUSHA__      0x08    // 天宇虚拟机指令集编码 将RAX、RBX、RDX、RCX、RSP、RBP、RSI、RDI依次压入栈中
#define __TYVM_INSTRUCTION_POPA__       0x09    // 天宇虚拟机指令集编码 将RDI、RSI、RBP、RSP、RCX、RDX、RBX、RAX依次弹出堆栈
#define __TYVM_INSTRUCTION_LAIP__       0x0A    // 天宇虚拟机指令集编码 将RIP寄存器传送至RAX寄存器
#define __TYVM_INSTRUCTION_SAIP__       0x0B    // 天宇虚拟机指令集编码 从RAX寄存器更新RIP寄存器

#define __TYVM_INSTRUCTION_PUSH__       0x20    // 天宇虚拟机指令集编码 将指定元素压入堆栈
#define __TYVM_INSTRUCTION_POP__        0x21    // 天宇虚拟机指令集编码 将栈顶元素弹出
#define __TYVM_INSTRUCTION_IN__         0x22    // 天宇虚拟机指令集编码 IO输入指令
#define __TYVM_INSTRUCTION_LDS__        0x23    // 天宇虚拟机指令集编码 将指针装入DS
#define __TYVM_INSTRUCTION_LES__        0x24    // 天宇虚拟机指令集编码 将指针装入ES
#define __TYVM_INSTRUCTION_LCS__        0x25    // 天宇虚拟机指令集编码 将指针装入CS
#define __TYVM_INSTRUCTION_LGS__        0x26    // 天宇虚拟机指令集编码 将指针装入GS（当前为空指令）
#define __TYVM_INSTRUCTION_LSS__        0x27    // 天宇虚拟机指令集编码 将指针装入SS
#define __TYVM_INSTRUCTION_LAF__        0x28    // 天宇虚拟机指令集编码 将标志寄存器内容传送至RAX
#define __TYVM_INSTRUCTION_SAF__        0x29    // 天宇虚拟机指令集编码 将RAX内容传送至标志寄存器
#define __TYVM_INSTRUCTION_INC__        0x2A    // 天宇虚拟机指令集编码 自增1
#define __TYVM_INSTRUCTION_DEC__        0x2B    // 天宇虚拟机指令集编码 自减1
#define __TYVM_INSTRUCTION_NEG__        0x2C    // 天宇虚拟机指令集编码 求补
#define __TYVM_INSTRUCTION_JMP__        0x2D    // 天宇虚拟机指令集编码 无条件跳转指令
#define __TYVM_INSTRUCTION_CALL__       0x2E    // 天宇虚拟机指令集编码 无条件调用指令（涉及CS/RIP入栈）
#define __TYVM_INSTRUCTION_JE__         0x2F    // 天宇虚拟机指令集编码 相等时转移
#define __TYVM_INSTRUCTION_JZ__         0x30    // 天宇虚拟机指令集编码 等于0时转移
#define __TYVM_INSTRUCTION_JNE__        0x31    // 天宇虚拟机指令集编码 不等时转移
#define __TYVM_INSTRUCTION_JNZ__        0x32    // 天宇虚拟机指令集编码 不等于0时转移
#define __TYVM_INSTRUCTION_JC__         0x33    // 天宇虚拟机指令集编码 有进位时转移
#define __TYVM_INSTRUCTION_JNC__        0x34    // 天宇虚拟机指令集编码 无进位时转移
#define __TYVM_INSTRUCTION_JO__         0x35    // 天宇虚拟机指令集编码 溢出时转移
#define __TYVM_INSTRUCTION_JNO__        0x36    // 天宇虚拟机指令集编码 未溢出时转移
#define __TYVM_INSTRUCTION_JS__         0x37    // 天宇虚拟机指令集编码 符号位为1时转移（负数时转移）
#define __TYVM_INSTRUCTION_JNS__        0x38    // 天宇虚拟机指令集编码 符号位为0时转移（正数时转移）
#define __TYVM_INSTRUCTION_JP__         0x39    // 天宇虚拟机指令集编码 偶数时转移
#define __TYVM_INSTRUCTION_JNP__        0x3A    // 天宇虚拟机指令集编码 奇数时转移
#define __TYVM_INSTRUCTION_JPO__        0x3B    // 天宇虚拟机指令集编码 奇数时转移
#define __TYVM_INSTRUCTION_JPE__        0x3C    // 天宇虚拟机指令集编码 偶数时转移
#define __TYVM_INSTRUCTION_LOOP__       0x3D    // 天宇虚拟机指令集编码 RCX不为0时循环
#define __TYVM_INSTRUCTION_JCXZ__       0x3E    // 天宇虚拟机指令集编码 RCX为0时转移
#define __TYVM_INSTRUCTION_INT__        0x3F    // 天宇虚拟机指令集编码 中断指令（引发数据保存并跳转）
#define __TYVM_INSTRUCTION_NOT__        0xE0    // 天宇虚拟机指令集编码 非

#define __TYVM_INSTRUCTION_MOV__        0xA0    // 天宇虚拟机指令集编码 传送指令
#define __TYVM_INSTRUCTION_MOVW__       0xA1    // 天宇虚拟机指令集编码 传送指令（当前为空指令）
#define __TYVM_INSTRUCTION_MOVDW__      0xA2    // 天宇虚拟机指令集编码 传送指令（当前为空指令）
#define __TYVM_INSTRUCTION_MOVQW__      0xA3    // 天宇虚拟机指令集编码 传送指令（当前为空指令）
#define __TYVM_INSTRUCTION_CMPXCHG__    0xA4    // 天宇虚拟机指令集编码 比较并交换（自动包含Lock锁）
#define __TYVM_INSTRUCTION_OUT__        0xA5    // 天宇虚拟机指令集编码 IO输出指令
#define __TYVM_INSTRUCTION_LEA__        0xA6    // 天宇虚拟机指令集编码 装入有效地址
#define __TYVM_INSTRUCTION_ADD__        0xA7    // 天宇虚拟机指令集编码 加法
#define __TYVM_INSTRUCTION_SUB__        0xA8    // 天宇虚拟机指令集编码 减法
#define __TYVM_INSTRUCTION_CMP__        0xA9    // 天宇虚拟机指令集编码 比较指令
#define __TYVM_INSTRUCTION_MUL__        0xAA    // 天宇虚拟机指令集编码 无符号乘法
#define __TYVM_INSTRUCTION_IMUL__       0xAB    // 天宇虚拟机指令集编码 有符号乘法
#define __TYVM_INSTRUCTION_DIV__        0xAC    // 天宇虚拟机指令集编码 无符号除法
#define __TYVM_INSTRUCTION_IDIV__       0xAD    // 天宇虚拟机指令集编码 有符号除法
#define __TYVM_INSTRUCTION_AND__        0xAE    // 天宇虚拟机指令集编码 与
#define __TYVM_INSTRUCTION_OR__         0xAF    // 天宇虚拟机指令集编码 或
#define __TYVM_INSTRUCTION_XOR__        0xB1    // 天宇虚拟机指令集编码 异或
#define __TYVM_INSTRUCTION_SHR__        0xB2    // 天宇虚拟机指令集编码 逻辑右移
#define __TYVM_INSTRUCTION_SAR__        0xB3    // 天宇虚拟机指令集编码 算术右移
#define __TYVM_INSTRUCTION_SHL__        0xB4    // 天宇虚拟机指令集编码 逻辑左移
#define __TYVM_INSTRUCTION_SAL__        0xB5    // 天宇虚拟机指令集编码 算数左移
#define __TYVM_INSTRUCTION_ROL__        0xB6    // 天宇虚拟机指令集编码 循环左移（当前为空指令）
#define __TYVM_INSTRUCTION_ROR__        0xB7    // 天宇虚拟机指令集编码 循环右移（当前为空指令）
#define __TYVM_INSTRUCTION_RCL__        0xB8    // 天宇虚拟机指令集编码 带进位的循环左移（当前为空指令）
#define __TYVM_INSTRUCTION_RCR__        0xB9    // 天宇虚拟机指令集编码 带进位的循环右移（当前为空指令）


/**
 * 浮点指令区
*/
#define __TYVM_INSTRUCTION_FINIT__      0x10    // 天宇虚拟机指令集编码 初始化浮点部件（浮点寄存器清零、寄存器指针清零）
#define __TYVM_INSTRUCTION_FCLEX__      0x11    // 天宇虚拟机指令集编码 清除异常
#define __TYVM_INSTRUCTION_FNOP__       0x12    // 天宇虚拟机指令集编码 浮点空指令
#define __TYVM_INSTRUCTION_FLDZ__       0x13    // 天宇虚拟机指令集编码 将0.0装入ST(0)
#define __TYVM_INSTRUCTION_FLD1__       0x14    // 天宇虚拟机指令集编码 将1.0装入ST(0)
#define __TYVM_INSTRUCTION_FLDPI__      0x15    // 天宇虚拟机指令集编码 将PI装入ST(0)
#define __TYVM_INSTRUCTION_FLDL2T__     0x16    // 天宇虚拟机指令集编码 将log2(10)装入ST(0)
#define __TYVM_INSTRUCTION_FLDL2E__     0x17    // 天宇虚拟机指令集编码 将log2(e)装入ST(0)
#define __TYVM_INSTRUCTION_FLDLG2__     0x18    // 天宇虚拟机指令集编码 将log10(2)装入ST(0)
#define __TYVM_INSTRUCTION_FLDLN2__     0x19    // 天宇虚拟机指令集编码 将ln2装入ST(0)
#define __TYVM_INSTRUCTION_FDECSTP__    0x1A    // 天宇虚拟机指令集编码 减少栈指针
#define __TYVM_INSTRUCTION_FINCSTP__    0x1B    // 天宇虚拟机指令集编码 增加栈指针

#define __TYVM_INSTRUCTION_FCHS__       0xD1    // 天宇虚拟机指令集编码 改变ST(0)的正负至
#define __TYVM_INSTRUCTION_FABS__       0xD2    // 天宇虚拟机指令集编码 将ST(0)取绝对值保存
#define __TYVM_INSTRUCTION_FSQRT__      0xD3    // 天宇虚拟机指令集编码 将ST(0)取根号后保存
#define __TYVM_INSTRUCTION_FSIN__       0xD4    // 天宇虚拟机指令集编码 将ST(0)取正弦值后保存
#define __TYVM_INSTRUCTION_FCOS__       0xD5    // 天宇虚拟机指令集编码 将ST(0)取余弦值后保存
#define __TYVM_INSTRUCTION_FXCH_A__     0xD6    // 天宇虚拟机指令集编码 交换ST(0)与ST(1)
#define __TYVM_INSTRUCTION_FCMP_A__     0xD7    // 天宇虚拟机指令集编码 比较ST(0)与ST(1)
#define __TYVM_INSTRUCTION_FADD_A__     0xD8    // 天宇虚拟机指令集编码 浮点加法 ST(0)+ST(1)
#define __TYVM_INSTRUCTION_FSUB_A__     0xD9    // 天宇虚拟机指令集编码 浮点减法 ST(0)-ST(1)
#define __TYVM_INSTRUCTION_FSUBR_A__    0xDA    // 天宇虚拟机指令集编码 浮点减法 ST(1)-ST(0)
#define __TYVM_INSTRUCTION_FMUL_A__     0xDB    // 天宇虚拟机指令集编码 浮点乘法 ST(0)*ST(1)
#define __TYVM_INSTRUCTION_FDIV_A__     0xDC    // 天宇虚拟机指令集编码 浮点除法 ST(0)/ST(1)
#define __TYVM_INSTRUCTION_FDIVR_A__    0xDD    // 天宇虚拟机指令集编码 浮点除法 ST(1)/ST(0)

#define __TYVM_INSTRUCTION_FXCH__       0x40    // 天宇虚拟机指令集编码 交换ST(0)与ST(1)
#define __TYVM_INSTRUCTION_FLD__        0x41    // 天宇虚拟机指令集编码 将浮点数装入ST(0)
#define __TYVM_INSTRUCTION_FILD__       0x42    // 天宇虚拟机指令集编码 将64为整数装入ST(0)
#define __TYVM_INSTRUCTION_FST__        0x43    // 天宇虚拟机指令集编码 保存浮点数ST(0)
#define __TYVM_INSTRUCTION_FIST__       0x44    // 天宇虚拟机指令集编码 保存整数ST(0)
#define __TYVM_INSTRUCTION_FCMP__       0x45    // 天宇虚拟机指令集编码 比较ST(0)与ST(1)
#define __TYVM_INSTRUCTION_FADD__       0x46    // 天宇虚拟机指令集编码 浮点加法 ST(0)+ST(1)
#define __TYVM_INSTRUCTION_FIADD__      0x47    // 天宇虚拟机指令集编码 浮点加法 ST(0)+整数
#define __TYVM_INSTRUCTION_FSUB__       0x48    // 天宇虚拟机指令集编码 浮点减法 ST(0)-ST(1)
#define __TYVM_INSTRUCTION_FSUBR__      0x49    // 天宇虚拟机指令集编码 浮点减法 ST(1)-ST(0)
#define __TYVM_INSTRUCTION_FISUB__      0x4A    // 天宇虚拟机指令集编码 浮点减法 ST(0)-整数
#define __TYVM_INSTRUCTION_FISUBR__     0x4B    // 天宇虚拟机指令集编码 浮点减法 整数-ST(0)
#define __TYVM_INSTRUCTION_FMUL__       0x4C    // 天宇虚拟机指令集编码 浮点乘法 ST(0)*ST(1)
#define __TYVM_INSTRUCTION_FIMUL__      0x4D    // 天宇虚拟机指令集编码 浮点乘法 ST(0)*整数
#define __TYVM_INSTRUCTION_FDIV__       0x4E    // 天宇虚拟机指令集编码 浮点除法 ST(0)/ST(1)
#define __TYVM_INSTRUCTION_FDIVR__      0x4F    // 天宇虚拟机指令集编码 浮点除法 ST(i)/ST(0)
#define __TYVM_INSTRUCTION_FIDIV__      0x50    // 天宇虚拟机指令集编码 浮点除法 ST(0)/整数
#define __TYVM_INSTRUCTION_FIDIVR__     0x51    // 天宇虚拟机指令集编码 浮点除法 整数/ST(0)

#define __TYVM_INSTRUCTION_INVAILD__    0xFF    // 天宇虚拟机指令集编码 无效编码

#endif // !__TIANYUVM_C_CPP_TVMINSTDEFINE__