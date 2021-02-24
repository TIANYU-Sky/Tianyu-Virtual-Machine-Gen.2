/**
 * �������������ϵͳ��CPU���Ķ���ģ��
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
// ��ȡ������ַ
//
typedef uint64 __VAR__ (__PTR__ cpu_method_getmemaddress)
(
    struct cpu  __PTR__ cpu_dev,            // CPU����
    int8        __VAR__ segment,            // ָ���ĶμĴ���
    int8        __VAR__ reg,                // ָ���ļĴ���
    bool        __VAR__ base_state,         // ָʾ��ַ�Ĵ����Ƿ���Ч
    int8        __VAR__ base_reg,           // ָ����ַ�Ĵ���
    int8        __VAR__ base_times,         // ָʾ��ַ����
    bool        __VAR__ offset_state,       // ָʾ�Ƿ����ƫ����
    uint64      __VAR__ offset              // �ṩƫ����
);

//
// CPU���
//
typedef struct cpu
{
    uint64 __VAR__ ThreadCode;      // ��ǰ�̺߳�
    uint64 __VAR__ ProgressCode;    // ��ǰ���̺�
    uint64 __VAR__ StackTop;        // ��ǰ����Ķ�ջ���ջ��
    uint64 __VAR__ StackBottom;     // ��ǰ����Ķ�ջ��Сջ��

    uint64 __VAR__ CS;          // ����μĴ���
    uint64 __VAR__ SS;          // ��ջ�μĴ���
    uint64 __VAR__ DS;          // ���ݶμĴ�����������
    uint64 __VAR__ ES;          // ��չ�μĴ�����������
    uint64 __VAR__ GS;          // ��չ�μĴ�����������

    uint64 __VAR__ FLAGREG;     // ��־�Ĵ���

    uint64 __VAR__ IP;          // ָ��ָ�루��CS��

    uint64 __VAR__ GREG[__GENERAL_REGISTER_SIZE__]; // ͨ�üĴ�����

    double __VAR__ ST[__FPU_REGISTER_SIZE__];       // ����Ĵ�����ջ
    byte   __VAR__ STP;                             // ����Ĵ�����ջָ��
    
    TVMSystem __PTR__ System;       // ϵͳ���ָ��

    cpu_method_getmemaddress __VAR__ CalculateMemory;    // ����ָ��������ڴ�λ��
}CPU;

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMCPUCORE__