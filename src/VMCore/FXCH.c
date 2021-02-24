#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

extern byte __VAR__ STP_INDEX(byte __VAR__ stp, byte __VAR__ index);

byte __VAR__ FXCH(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne)
	{
		switch (instruct->_OPOne->_Addressing)
		{
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
		{
			double temp = cpu->ST[cpu->STP];
			cpu->ST[cpu->STP] = cpu->ST[STP_INDEX(cpu->STP, instruct->_OPOne->_Reg_Expand & __TYVM_REGISTER_ST_TEST__)];
			cpu->ST[STP_INDEX(cpu->STP, 1)] = temp;
		}
			break;
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_IMM__:
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_MEM__:
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