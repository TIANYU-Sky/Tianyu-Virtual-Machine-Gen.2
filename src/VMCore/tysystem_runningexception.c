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
		printf_s("严重：在内存 %llu 中存在指令译码错误", memory);
		break;
	case __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__:
		printf_s("严重：在内存 %llu 中存在指令错误 无法执行的指令", memory);
		break;
	case __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__:
		printf_s("严重：在内存 %llu 处执行堆栈越界", memory);
		break;
	case __TYVM_RUNNING_EXCEPTION_NULL_POINTER__:
		printf_s("严重：正在内存 %llu 处正在尝试访问非法的内存", memory);
		break;
	case __TYVM_RUNNING_EXCEPTION_UNKNOWN_ERROR__:
	default:
		printf_s("严重：在内存 %llu 中存在未知", memory);
		break;
	}
}