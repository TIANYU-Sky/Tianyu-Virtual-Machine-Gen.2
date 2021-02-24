/**
 * ������������ϵͳ�Ļ����
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

#define __TYLASM_LEXICAL_TYPE_UNKNOWN__         0x00    // ���������� �ʷ��������Ͷ��� δ֪����
#define __TYLASM_LEXICAL_TYPE_INSTRUCTION__     0x01    // ���������� �ʷ��������Ͷ��� ָ����ţ�ʹ��GetInstruction��
#define __TYLASM_LEXICAL_TYPE_REGISTER__        0x02    // ���������� �ʷ��������Ͷ��� �Ĵ������ţ�����GetInstruction��
#define __TYLASM_LEXICAL_TYPE_INTEGER__         0x03    // ���������� �ʷ��������Ͷ��� ����
#define __TYLASM_LEXICAL_TYPE_LABEL__           0x04    // ���������� �ʷ��������Ͷ��� ��ǩ����
#define __TYLASM_LEXICAL_TYPE_FLOAT__           0x05    // ���������� �ʷ��������Ͷ��� ��������

#define __TYLASM_LEXICAL_TYPE_LBRACKET__        0x06    // ���������� �ʷ��������Ͷ��� �������
#define __TYLASM_LEXICAL_TYPE_RBRACKET__        0x07    // ���������� �ʷ��������Ͷ��� �Ҵ�����
#define __TYLASM_LEXICAL_TYPE_COLON__           0x08    // ���������� �ʷ��������Ͷ��� ð��
#define __TYLASM_LEXICAL_TYPE_COMMA__           0x09    // ���������� �ʷ��������Ͷ��� ����

#define __TYLASM_LEXICAL_TYPE_DATATYPE_B__      0x10    // ���������� �ʷ��������Ͷ��� �������ͣ��ֽ�
#define __TYLASM_LEXICAL_TYPE_DATATYPE_W__      0x11    // ���������� �ʷ��������Ͷ��� �������ͣ���
#define __TYLASM_LEXICAL_TYPE_DATATYPE_D__      0x12    // ���������� �ʷ��������Ͷ��� �������ͣ�˫��
#define __TYLASM_LEXICAL_TYPE_DATATYPE_Q__      0x13    // ���������� �ʷ��������Ͷ��� �������ͣ�����

#define __TYLASM_LEXICAL_TYPE_STATE_LOCK__      0x20    // ���������� �ʷ��������Ͷ��� ִ��״̬����

#define __TYLASM_LEXICAL_TYPE_DESCRIBE_START__  0x30    // ���������� �ʷ��������Ͷ��� ���������������
#define __TYLASM_LEXICAL_TYPE_DESCRIBE_PSTART__ 0x31    // ���������� �ʷ��������Ͷ��� �����������̿�ʼ
#define __TYLASM_LEXICAL_TYPE_DESCRIBE_PEND__   0x32    // ���������� �ʷ��������Ͷ��� �����������̽���
#define __TYLASM_LEXICAL_TYPE_DESCRIBE_END__    0x33    // ���������� �ʷ��������Ͷ��� ���������ν���

#define __TYLASM_LEXICAL_TYPE_SEGMENT_DATA__    0x40    // ���������� �ʷ��������Ͷ��� ���ݶ�
#define __TYLASM_LEXICAL_TYPE_SEGMENT_STACK__   0x41    // ���������� �ʷ��������Ͷ��� ��ջ��
#define __TYLASM_LEXICAL_TYPE_SEGMENT_EXPAND__  0x42    // ���������� �ʷ��������Ͷ��� ��չ��
#define __TYLASM_LEXICAL_TYPE_SEGMENT_CODE__    0x43    // ���������� �ʷ��������Ͷ��� �����

//
// �������Ի�����ʷ������ṹԤ����
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
    basetylasmvocabulary_GetIdentify       __VAR__ GetIdentify;        // ��ȡ��ǰ��ǩ��ָ������������ã�
    basetylasmvocabulary_GetInteger        __VAR__ GetInteger;         // ��ȡ��ǰ���ŵ��������ݣ�������ã�
    basetylasmvocabulary_GetFloat          __VAR__ GetFloat;           // ��ȡ��ǰ���ŵĸ������ݣ�������ã�
    basetylasmvocabulary_GetType           __VAR__ GetType;            // ��ȡ��ǰ���ʷ��ŵ����ͣ�������ã�
    basetylasmvocabulary_GetInstruction    __VAR__ GetInstruction;     // ��ȡ��ǰ���ʷ�������ʾ��ָ�������ã�
}BaseTYLAsmVocabulary;

//
// �������Ի����ָ��ṹԤ����
//
__Predefine__ struct interfacetylasminstruction;


#define __TYLASM_COMPILE_ERROR_UNKNOW__         0x00

//
// �������Ի�����ṹԤ����
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
    tylasm_openfile __VAR__ Open;       // ��������ļ�����
    tylasm_compile  __VAR__ Compile;    // �������࿪ʼ����
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