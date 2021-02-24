#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

//
// INT指令操作方法
// 返回执行状态标志
// 
byte __VAR__ INT_INST(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne)
	{
		switch (instruct->_OPOne->_Addressing)
		{
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
			cpu->System->SysInterrupt
			(
				cpu->System,
				cpu->GREG[instruct->_OPOne->_Reg_Expand],
				cpu->GREG[__TYVM_REGISTER_RBX__],
				__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
			);
			break;
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_IMM__:
			cpu->System->SysInterrupt
			(
				cpu->System,
				instruct->_OPOne->_Imm_Offset,
				cpu->GREG[__TYVM_REGISTER_RBX__],
				__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
			);
			break;
		default:
			cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->IP);
			(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
			return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
		}
	}
	else
	{
		cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->IP);
		(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
		return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
	}

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}