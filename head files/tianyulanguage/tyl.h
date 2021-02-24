# pragma once

#ifndef __TIANYULANGUAGE_C_CPP_TYL__
#define __TIANYULANGUAGE_C_CPP_TYL__

#include"../define.h"
#include"../basedatatype.h"

#define __Lex_Error_String_NotEnd__             0x00011     // 词法分析器 错误：字符串没有期待的结束

#define __Lex_Error_Char_NotEnd__               0x00021     // 词法分析器 错误：字符没有期待的结束
#define __Lex_Error_Char_MulChar__              0x00022     // 词法分析器 错误：包含多个字符
#define __Lex_Error_Char_NotChar__              0x00022     // 词法分析器 错误：没有包含字符

#define __Lex_Error_Integer_CharInvaild__       0x00031     // 词法分析器 错误：整数出现异常字符

#define __Lex_Error_Float_CharInvaild__         0x00041     // 词法分析器 错误：浮点数出现异常字符
#define __Lex_Error_Float_FormatInvaild__       0x00042     // 词法分析器 错误：浮点数格式错误
#define __Lex_Error_Float_ExponeInvaild__       0x00043     // 词法分析器 错误：浮点数指数无效
#define __Lex_Error_Float_ExpCharInvaild__      0x00044     // 词法分析器 错误：浮点数指数出现异常字符


#define __Lex_Warning_Char_Remean__             0x10021     // 词法分析器 警告：无效的转义字符
#define __Lex_Warning_Integer_Large__           0x10031     // 词法分析器 警告：整数太大 超过最大整数可表示的最大值
#define __Lex_Warning_Float_ExpOver__           0x10041     // 词法分析器 错误：浮点数指数太大

#ifdef __cplusplus
__C__
{
#endif // !__cplusplus

typedef void __VAR__ (__PTR__ ibasetyl_info)
(
    byte            __VAR__ info_level,
    byte            __VAR__ info_code,
    CStructString   __PTR__ message
);

__Predefine__ struct ibasetyl;

typedef void __VAR__ (__PTR__ ibasetyl_compile)
(
    struct ibasetyl __PTR__ tyl,
    CStructString   __PTR__ file
);

typedef struct ibasetyl
{
    ibasetyl_compile __VAR__ Compile;
}IBaseTYL;

IBaseTYL __PTR__ CreateTYL
(
    ibasetyl_info __VAR__ info_delegate
);
void __VAR__ DestroyTYL
(
    IBaseTYL __PTR__ tyl
);

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__TIANYULANGUAGE_C_CPP_TYL__