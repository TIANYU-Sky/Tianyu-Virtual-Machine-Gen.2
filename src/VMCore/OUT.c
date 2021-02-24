#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

//
// OUT指令操作方法
// 返回执行状态标志
// 
byte __VAR__ DOUT(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne && null != instruct->_OPTwo)
	{
		switch (instruct->_OPOne->_Addressing)
		{
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
			switch (instruct->_OPTwo->_OPType)
			{
			case __INSTRUCTION_SECOND_OPTYPE_REG__:
				cpu->System->DeviceOut
				(
					cpu->System,
					cpu->GREG[instruct->_OPTwo->_Reg_Imm],
					cpu->GREG[instruct->_OPOne->_Reg_Expand]
				);
				break;
			case __INSTRUCTION_SECOND_OPTYPE_IMM__:
				cpu->System->DeviceOut
				(
					cpu->System,
					instruct->_OPTwo->_Reg_Imm,
					cpu->GREG[instruct->_OPOne->_Reg_Expand]
				);
				break;
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