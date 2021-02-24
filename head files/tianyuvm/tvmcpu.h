/**
 * 用于天宇虚拟机系统的CPU部分
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
// 创建一个可以用于执行的CPU对象
// 返回一个CPU对象
//
CPU __PTR__ CreateCPU
(
	TVMSystem __PTR__ system,				// 系统接口
	uint64    __VAR__ thread_code,			// 线程号
	uint64    __VAR__ progress_code,		// 进程号
	uint64    __VAR__ instruction_pointer,	// 指令指针寄存器应该装载的值
	uint64    __VAR__ stack_pointer,		// 堆栈寄存器指针
	uint64    __VAR__ stack_size			// 堆栈大小
);

//
// 用于执行的线程调用入口
// 返回系统调用结束值
//
object __VAR__ __stdcall ExcuteEnter
(
	object __VAR__ obj	// 传入的初始参数
);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_TVMCPU__