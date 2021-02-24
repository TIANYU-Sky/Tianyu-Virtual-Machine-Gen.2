# pragma once

#ifndef __TIANYULANGUAGE_C_CPP_TYL__
#define __TIANYULANGUAGE_C_CPP_TYL__

#include"../define.h"
#include"../basedatatype.h"

#define __Lex_Error_String_NotEnd__             0x00011     // �ʷ������� �����ַ���û���ڴ��Ľ���

#define __Lex_Error_Char_NotEnd__               0x00021     // �ʷ������� �����ַ�û���ڴ��Ľ���
#define __Lex_Error_Char_MulChar__              0x00022     // �ʷ������� ���󣺰�������ַ�
#define __Lex_Error_Char_NotChar__              0x00022     // �ʷ������� ����û�а����ַ�

#define __Lex_Error_Integer_CharInvaild__       0x00031     // �ʷ������� �������������쳣�ַ�

#define __Lex_Error_Float_CharInvaild__         0x00041     // �ʷ������� ���󣺸����������쳣�ַ�
#define __Lex_Error_Float_FormatInvaild__       0x00042     // �ʷ������� ���󣺸�������ʽ����
#define __Lex_Error_Float_ExponeInvaild__       0x00043     // �ʷ������� ���󣺸�����ָ����Ч
#define __Lex_Error_Float_ExpCharInvaild__      0x00044     // �ʷ������� ���󣺸�����ָ�������쳣�ַ�


#define __Lex_Warning_Char_Remean__             0x10021     // �ʷ������� ���棺��Ч��ת���ַ�
#define __Lex_Warning_Integer_Large__           0x10031     // �ʷ������� ���棺����̫�� ������������ɱ�ʾ�����ֵ
#define __Lex_Warning_Float_ExpOver__           0x10041     // �ʷ������� ���󣺸�����ָ��̫��

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