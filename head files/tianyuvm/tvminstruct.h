/**
 * �������������ϵͳ��ָ��ϵͳ
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMINSTRUCT__
#define __TIANYUVM_C_CPP_TVMINSTRUCT__

#include"../define.h"
#include"../basedatatype.h"
#include"tvminstdefine.h"
#include"tvmcpucore.h"

#define __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__    0x00    // ָ���һ������Ѱַ��ʽ���Ĵ���������
#define __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_IMM__    0x01    // ָ���һ������Ѱַ��ʽ��������������
#define __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_MEM__    0x02    // ָ���һ������Ѱַ��ʽ���ڴ�Ѱַ

#define __INSTRUCTION_PACKAGE_OPONE_REG_INVAILD__       0xFF   // ָ���һ�������Ĵ�����Ч

#ifdef __cplusplus
__C__
{
#endif

//
// ָ����ṹ��Ԥ����
//
__Predefine__ struct instructionpackage;

#define __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__ 0x00
#define __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__  0x02

//
// ָ��ִ�з���ί��
// ����ִ��״̬��־
//
typedef byte __VAR__ (__PTR__ instructionpackage_run)
(
    struct instructionpackage   __PTR__ instruct,       // ָ���
    CPU                         __PTR__ cpu,            // ����ִ��ָ���CPU����
    bool                        __PTR__ excuter_flag    // ִ��״̬��־
);

//
// ָ���һ�������ṹ��
//
typedef struct instructionpackageopone
{
    int8    __VAR__ _Addressing;            // ����ָ����һ��������Ѱַ��ʽ
    int8    __VAR__ _Reg_Expand;            // ����ָ����һ�������еļĴ���/��չ��

    bool    __VAR__ _BaseAddrState;         // ��Ѱַ��ʽΪ��չʱ ָʾ��ַ�Ĵ����Ƿ���Ч
    int8    __VAR__ _BaseAddrReg;           // ��Ѱַ��ʽΪ��չ�һ�ַ�Ĵ�����Чʱ ָ����ַ�Ĵ���
    int8    __VAR__ _BaseAddrTimes;         // ��Ѱַ��ʽΪ��չʱ ָʾ��ַ����
    bool    __VAR__ _BaseAddrOffsetFlag;    // ��Ѱַ��ʽΪ��չʱ ָʾ�Ƿ����ƫ����

    uint64  __VAR__ _Imm_Offset;            // ��Ѱַ��ʽΪ��������ֱ��/��ӣ�ʱ �ṩ������ ��Ѱַ��ʽΪ��չʱ �ṩƫ����
}InstructionPackageOPOne;

//
// ָ��ڶ��������ṹ��
//
typedef struct instructionpackageoptwo
{
    int8    __VAR__ _OPType;    // ����ָ���ڶ�������������
    uint64  __VAR__ _Reg_Imm;   // ����ָ����ʹ�õļĴ�����������
}InstructionPackageOPTwo;

//
// ָ����ṹ��ʵ��
//
typedef struct instructionpackage
{
    bool __VAR__ _Lock;         // ָ����ǰָ��ִ��ʱ���ڴ��Ƿ�����
    bool __VAR__ _OPDirect;     // ָ����ǰָ��ִ��ʱ�Ĳ���������
    int8 __VAR__ _Segment;      // ָ��ָ��ִ��ʱ�ĶμĴ���
    int8 __VAR__ _OPNumber;     // ָ����ǰָ��������С��8��16��32��64��

    instructionpackage_run  __VAR__ Run;     // ָ�����з���
    
    InstructionPackageOPOne __PTR__ _OPOne; // ָ����ǰ��һ������
    InstructionPackageOPTwo __PTR__ _OPTwo; // ָ����ǰ�ڶ�������
}InstructionPackage;

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMINSTRUCT__