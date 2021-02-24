/**
 * �������������ϵͳ��CPU����
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMCPU__
#define __TIANYUVM_C_CPP_TVMCPU__

#include"../define.h"
#include"../basedatatype.h"
#include"tvmsystem.h"
#include"tvmcpucore.h"

#ifdef __cplusplus
__C__
{
#endif

//
// ����һ����������ִ�е�CPU����
// ����һ��CPU����
//
CPU __PTR__ CreateCPU
(
	TVMSystem __PTR__ system,				// ϵͳ�ӿ�
	uint64    __VAR__ thread_code,			// �̺߳�
	uint64    __VAR__ progress_code,		// ���̺�
	uint64    __VAR__ instruction_pointer,	// ָ��ָ��Ĵ���Ӧ��װ�ص�ֵ
	uint64    __VAR__ stack_pointer,		// ��ջ�Ĵ���ָ��
	uint64    __VAR__ stack_size			// ��ջ��С
);

//
// ����ִ�е��̵߳������
// ����ϵͳ���ý���ֵ
//
object __VAR__ __stdcall ExcuteEnter
(
	object __VAR__ obj	// ����ĳ�ʼ����
);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMCPU__