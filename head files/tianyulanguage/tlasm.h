/**
 * 用于天宇语言系统的汇编器
*/
# pragma once

#ifndef __TIANYULANGUAGE_C_CPP_TLASM__
#define __TIANYULANGUAGE_C_CPP_TLASM__

#include"../define.h"
#include"../basedatatype.h"

#ifdef __cplusplus
__C__
{
#endif // !__cplusplus

#define __TYLASM_LEXICAL_TYPE_UNKNOWN__         0x00    // 天宇汇编语言 词法分析类型定义 未知类型
#define __TYLASM_LEXICAL_TYPE_INSTRUCTION__     0x01    // 天宇汇编语言 词法分析类型定义 指令符号（使用GetInstruction）
#define __TYLASM_LEXICAL_TYPE_REGISTER__        0x02    // 天宇汇编语言 词法分析类型定义 寄存器符号（复用GetInstruction）
#define __TYLASM_LEXICAL_TYPE_INTEGER__         0x03    // 天宇汇编语言 词法分析类型定义 整数
#define __TYLASM_LEXICAL_TYPE_LABEL__           0x04    // 天宇汇编语言 词法分析类型定义 标签符号
#define __TYLASM_LEXICAL_TYPE_FLOAT__           0x05    // 天宇汇编语言 词法分析类型定义 浮点类型

#define __TYLASM_LEXICAL_TYPE_LBRACKET__        0x06    // 天宇汇编语言 词法分析类型定义 左大括号
#define __TYLASM_LEXICAL_TYPE_RBRACKET__        0x07    // 天宇汇编语言 词法分析类型定义 右大括号
#define __TYLASM_LEXICAL_TYPE_COLON__           0x08    // 天宇汇编语言 词法分析类型定义 冒号
#define __TYLASM_LEXICAL_TYPE_COMMA__           0x09    // 天宇汇编语言 词法分析类型定义 逗号

#define __TYLASM_LEXICAL_TYPE_DATATYPE_B__      0x10    // 天宇汇编语言 词法分析类型定义 数据类型：字节
#define __TYLASM_LEXICAL_TYPE_DATATYPE_W__      0x11    // 天宇汇编语言 词法分析类型定义 数据类型：字
#define __TYLASM_LEXICAL_TYPE_DATATYPE_D__      0x12    // 天宇汇编语言 词法分析类型定义 数据类型：双字
#define __TYLASM_LEXICAL_TYPE_DATATYPE_Q__      0x13    // 天宇汇编语言 词法分析类型定义 数据类型：四字

#define __TYLASM_LEXICAL_TYPE_STATE_LOCK__      0x20    // 天宇汇编语言 词法分析类型定义 执行状态：锁

#define __TYLASM_LEXICAL_TYPE_DESCRIBE_START__  0x30    // 天宇汇编语言 词法分析类型定义 描述符：程序入口
#define __TYLASM_LEXICAL_TYPE_DESCRIBE_PSTART__ 0x31    // 天宇汇编语言 词法分析类型定义 描述符：过程开始
#define __TYLASM_LEXICAL_TYPE_DESCRIBE_PEND__   0x32    // 天宇汇编语言 词法分析类型定义 描述符：过程结束
#define __TYLASM_LEXICAL_TYPE_DESCRIBE_END__    0x33    // 天宇汇编语言 词法分析类型定义 描述符：段结束

#define __TYLASM_LEXICAL_TYPE_SEGMENT_DATA__    0x40    // 天宇汇编语言 词法分析类型定义 数据段
#define __TYLASM_LEXICAL_TYPE_SEGMENT_STACK__   0x41    // 天宇汇编语言 词法分析类型定义 堆栈段
#define __TYLASM_LEXICAL_TYPE_SEGMENT_EXPAND__  0x42    // 天宇汇编语言 词法分析类型定义 扩展段
#define __TYLASM_LEXICAL_TYPE_SEGMENT_CODE__    0x43    // 天宇汇编语言 词法分析类型定义 代码段

//
// 天宇语言汇编器词法分析结构预定义
//
__Predefine__ struct basetylasmvocabulary;

typedef CStructString   __PTR__ (__PTR__ basetylasmvocabulary_GetIdentify)
(
    struct basetylasmvocabulary    __PTR__ vocabulary
);
typedef uint64          __VAR__ (__PTR__ basetylasmvocabulary_GetInteger)
(
    struct basetylasmvocabulary    __PTR__ vocabulary
);
typedef double          __VAR__ (__PTR__ basetylasmvocabulary_GetFloat)
(
    struct basetylasmvocabulary    __PTR__ vocabulary
);
typedef byte            __VAR__ (__PTR__ basetylasmvocabulary_GetType)
(
    struct basetylasmvocabulary    __PTR__ vocabulary
);
typedef uint32          __VAR__ (__PTR__ basetylasmvocabulary_GetInstruction)
(
    struct basetylasmvocabulary    __PTR__ vocabulary
);

typedef struct basetylasmlexical
{
    basetylasmvocabulary_GetIdentify       __VAR__ GetIdentify;        // 获取当前标签、指令名（如果可用）
    basetylasmvocabulary_GetInteger        __VAR__ GetInteger;         // 获取当前符号的整数数据（如果可用）
    basetylasmvocabulary_GetFloat          __VAR__ GetFloat;           // 获取当前符号的浮点数据（如果可用）
    basetylasmvocabulary_GetType           __VAR__ GetType;            // 获取当前单词符号的类型（如果可用）
    basetylasmvocabulary_GetInstruction    __VAR__ GetInstruction;     // 获取当前单词符号所表示的指令（如果可用）
}BaseTYLAsmVocabulary;

//
// 天宇语言汇编器指令结构预定义
//
__Predefine__ struct interfacetylasminstruction;


#define __TYLASM_COMPILE_ERROR_UNKNOW__         0x00

//
// 天宇语言汇编器结构预定义
//
__Predefine__ struct interfacetylasm;

typedef void __VAR__ (__PTR__ tylasm_openfile)
(
    struct interfacetylasm  __PTR__ tylasm,
    CStructString           __VAR__ path
);
typedef byte __VAR__ (__PTR__ tylasm_compile)
(
    struct interfacetylasm  __PTR__ tylasm
);

typedef struct interfacetylasm
{
    tylasm_openfile __VAR__ Open;       // 汇编器打开文件方法
    tylasm_compile  __VAR__ Compile;    // 汇编器汇编开始方法
}ITYLAsm;

ITYLAsm  __PTR__ CreateTYLAsm();
void    __VAR__ DestroyTYLAsm
(
    ITYLAsm __PTR__ tylasm
);

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__TIANYULANGUAGE_C_CPP_TLASM__