
#pragma once
#ifndef __TIANYULANGUAGE_C_CPP_TLDEFINE__
#define __TIANYULANGUAGE_C_CPP_TLDEFINE__

#define __TIANYULANGUAGE_FILE_ENCODE_UTF8__     0x00
#define __TIANYULANGUAGE_FILE_ENCODE_GB2312__   0x01
#define __TIANYULANGUAGE_FILE_ENCODE_ASCII__    0x02


#define __TIANYULANGUAGE_REGISTER_RAX__   0b000000  // 天宇汇编器 寄存器编码 RAX 累加寄存器
#define __TIANYULANGUAGE_REGISTER_RBX__   0b000001  // 天宇汇编器 寄存器编码 RBX 基址寄存器
#define __TIANYULANGUAGE_REGISTER_RCX__   0b000010  // 天宇汇编器 寄存器编码 RCX 计数寄存器
#define __TIANYULANGUAGE_REGISTER_RDX__   0b000011  // 天宇汇编器 寄存器编码 RDX 数据寄存器
#define __TIANYULANGUAGE_REGISTER_RSP__   0b000100  // 天宇汇编器 寄存器编码 RSP 栈指针寄存器
#define __TIANYULANGUAGE_REGISTER_RBP__   0b000101  // 天宇汇编器 寄存器编码 RBP 基址指针寄存器
#define __TIANYULANGUAGE_REGISTER_RSI__   0b000110  // 天宇汇编器 寄存器编码 RSI 源址寄存器
#define __TIANYULANGUAGE_REGISTER_RDI__   0b000111  // 天宇汇编器 寄存器编码 RDI 目的地址寄存器
#define __TIANYULANGUAGE_REGISTER_R8__    0b001000  // 天宇汇编器 寄存器编码 R8 通用寄存器
#define __TIANYULANGUAGE_REGISTER_R9__    0b001001  // 天宇汇编器 寄存器编码 R9 通用寄存器
#define __TIANYULANGUAGE_REGISTER_R10__   0b001010  // 天宇汇编器 寄存器编码 R10 通用寄存器
#define __TIANYULANGUAGE_REGISTER_R11__   0b001011  // 天宇汇编器 寄存器编码 R11 通用寄存器
#define __TIANYULANGUAGE_REGISTER_R12__   0b001100  // 天宇汇编器 寄存器编码 R12 通用寄存器
#define __TIANYULANGUAGE_REGISTER_R13__   0b001101  // 天宇汇编器 寄存器编码 R13 通用寄存器
#define __TIANYULANGUAGE_REGISTER_R14__   0b001110  // 天宇汇编器 寄存器编码 R14 通用寄存器
#define __TIANYULANGUAGE_REGISTER_R15__   0b001111  // 天宇汇编器 寄存器编码 R15 通用寄存器

#define __TIANYULANGUAGE_REGISTER_ST0__   0b010000  // 天宇汇编器 寄存器编码 ST(0)浮点堆栈寄存器
#define __TIANYULANGUAGE_REGISTER_ST1__   0b010001  // 天宇汇编器 寄存器编码 ST(1)浮点堆栈寄存器
#define __TIANYULANGUAGE_REGISTER_ST2__   0b010010  // 天宇汇编器 寄存器编码 ST(2)浮点堆栈寄存器
#define __TIANYULANGUAGE_REGISTER_ST3__   0b010011  // 天宇汇编器 寄存器编码 ST(3)浮点堆栈寄存器
#define __TIANYULANGUAGE_REGISTER_ST4__   0b010100  // 天宇汇编器 寄存器编码 ST(4)浮点堆栈寄存器
#define __TIANYULANGUAGE_REGISTER_ST5__   0b010101  // 天宇汇编器 寄存器编码 ST(5)浮点堆栈寄存器
#define __TIANYULANGUAGE_REGISTER_ST6__   0b010110  // 天宇汇编器 寄存器编码 ST(6)浮点堆栈寄存器
#define __TIANYULANGUAGE_REGISTER_ST7__   0b010111  // 天宇汇编器 寄存器编码 ST(7)浮点堆栈寄存器

#define __TIANYULANGUAGE_REGISTER_MMX0__  0b011000  // 天宇汇编器 寄存器编码 MMX(0)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TIANYULANGUAGE_REGISTER_MMX1__  0b011001  // 天宇汇编器 寄存器编码 MMX(1)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TIANYULANGUAGE_REGISTER_MMX2__  0b011010  // 天宇汇编器 寄存器编码 MMX(2)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TIANYULANGUAGE_REGISTER_MMX3__  0b011011  // 天宇汇编器 寄存器编码 MMX(3)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TIANYULANGUAGE_REGISTER_MMX4__  0b011100  // 天宇汇编器 寄存器编码 MMX(4)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TIANYULANGUAGE_REGISTER_MMX5__  0b011101  // 天宇汇编器 寄存器编码 MMX(5)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TIANYULANGUAGE_REGISTER_MMX6__  0b011110  // 天宇汇编器 寄存器编码 MMX(6)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）
#define __TIANYULANGUAGE_REGISTER_MMX7__  0b011111  // 天宇汇编器 寄存器编码 MMX(7)浮点堆栈寄存器（当前无SSE虚拟指令集 第四代以后虚拟机启用）

#define __TIANYULANGUAGE_REGISTER_CS__    0b100001  // 天宇汇编器 寄存器编码 RAX 累加寄存器
#define __TIANYULANGUAGE_REGISTER_DS__    0b100010  // 天宇汇编器 寄存器编码 RBX 基址寄存器
#define __TIANYULANGUAGE_REGISTER_ES__    0b100011  // 天宇汇编器 寄存器编码 RCX 计数寄存器
#define __TIANYULANGUAGE_REGISTER_SS__    0b100100  // 天宇汇编器 寄存器编码 RDX 数据寄存器

#define __TYLASM_LEXICAL_NO_ERROR__				0x00
#define __TYLASM_LEXICAL_LABEL_W_DOT__          0x11    // 天宇汇编语言 词法分析过程 以.开头的标识符
#define __TYLASM_LEXICAL_NUMBER_ERROR__         0x12    // 天宇汇编语言 词法分析过程 数字结构

#define __TYL_SIGN_LENGTH_MAX__ 1024

#ifdef __cplusplus
#endif

#ifdef __cplusplus
#endif

#endif // !__TIANYULANGUAGE_C_CPP_TLDEFINE__