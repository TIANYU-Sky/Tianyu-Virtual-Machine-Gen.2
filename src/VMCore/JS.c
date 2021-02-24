#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

//
// JMP指令操作方法子函数
// 返回执行状态标志
// 
extern byte __VAR__ JMP_SubFun(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);

//
// JE_JZ指令操作方法
// 返回执行状态标志
// 
byte __VAR__ JS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne)
	{
		if (cpu->FLAGREG & __TYVM_SIGNREGISTER_SIGN_FLAG__)
			return JMP_SubFun(instruct, cpu, excuter_flag);
	}
	else
	{
		cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->IP);
		(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
		return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
	}

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// JE_JZ指令操作方法
// 返回执行状态标志
// 
byte __VAR__ JNS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne)
	{
		if (!(cpu->FLAGREG & __TYVM_SIGNREGISTER_SIGN_FLAG__))
			return JMP_SubFun(instruct, cpu, excuter_flag);
	}
	else
	{
		cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->IP);
		(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
		return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
	}

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}