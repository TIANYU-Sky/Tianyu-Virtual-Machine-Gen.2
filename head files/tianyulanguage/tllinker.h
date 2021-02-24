/**
 * ������������ϵͳ��������
*/
# pragma once

#ifndef __TIANYULANGUAGE_C_CPP_TLLINKER__
#define __TIANYULANGUAGE_C_CPP_TLLINKER__

#include"../define.h"
#include"../basedatatype.h"

#ifdef __cplusplus
__C__
{
#endif // !__cplusplus

#define __LINKER_ERROR_FILE_OPEN__  0x01
#define __LINKER_ERROR_FILE_READ__  0x02
#define __LINKER_ERROR_FILE_TYPE__  0x03
#define __LINKER_ERROR_FILE_VERS__  0x04

#define __LINKER_ERROR_SIGN_REDEF__ 0x10
#define __LINKER_ERROR_SIGN_UNDEF__ 0x11

#define __LINKER_ERROR_STACK_OVER__ 0x20

#define __LINKER_TYY_STACK_SIZE_DEFAULT__   0x200000    // Ĭ��ջ�ռ�2MB
#define __LINKER_TYY_STACK_SIZE_MAX__       0x2000000   // ���ջ�ռ�32MB

typedef void __VAR__ (__PTR__ LinkerNotify)
(
    uint32          __VAR__ err_code,
    CStructString   __PTR__ str
);

__Predefine__ struct interfacetyllinker;

typedef bool __VAR__ (__PTR__ tylinker_output_file)
(
    struct interfacetyllinker   __PTR__ linker,     // ����������
    CStructString               __VAR__ out_file,   // ����ļ�
    CStructString               __VAR__ entry_proc  // ��ʼִ�з���
);
typedef bool __VAR__ (__PTR__ tylinker_input_file)
(
    struct interfacetyllinker   __PTR__ linker,     // ����������
    CStructString               __PTR__ file        // �����ļ�
);

typedef struct interfacetyllinker
{
    tylinker_output_file __VAR__ Output;
    tylinker_input_file  __VAR__ InputFile;
}ITYLLinker;

ITYLLinker __PTR__ CreateTYLinker
(
    LinkerNotify __VAR__ notify
);
void      __VAR__ DestroyTYLinker
(
    ITYLLinker __PTR__ linker
);

#ifdef __cplusplus
}
#endif // !__cplusplus

#endif // !__TIANYULANGUAGE_C_CPP_TLLINKER__