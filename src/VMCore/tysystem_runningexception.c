#include<tianyuvm/tvmsystem.h>
#include<stdio.h>

void __VAR__ TYSystem_RunningException
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ ecode,
	uint64		__VAR__ memory
)
{
	switch (ecode)
	{
	case __TYVM_RUNNING_EXCEPTION_CPU_DECODER_ERROR__:
		printf_s("���أ����ڴ� %llu �д���ָ���������", memory);
		break;
	case __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__:
		printf_s("���أ����ڴ� %llu �д���ָ����� �޷�ִ�е�ָ��", memory);
		break;
	case __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__:
		printf_s("���أ����ڴ� %llu ��ִ�ж�ջԽ��", memory);
		break;
	case __TYVM_RUNNING_EXCEPTION_NULL_POINTER__:
		printf_s("���أ������ڴ� %llu �����ڳ��Է��ʷǷ����ڴ�", memory);
		break;
	case __TYVM_RUNNING_EXCEPTION_UNKNOWN_ERROR__:
	default:
		printf_s("���أ����ڴ� %llu �д���δ֪", memory);
		break;
	}
}