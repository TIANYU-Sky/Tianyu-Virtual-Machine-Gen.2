#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

extern byte __VAR__ STP_INDEX(byte __VAR__ stp, byte __VAR__ index);

extern uint64 __VAR__ fidiv_asm(double __PTR__ op1, uint64 __PTR__ op2, double __PTR__ result);

byte __VAR__ FIDIV(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne)
	{
		switch (instruct->_OPOne->_Addressing)
		{
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_IMM__:
			cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->IP);
			(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
			return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_MEM__:
		{
			uint64 __VAR__ mem = cpu->CalculateMemory
			(
				cpu,
				instruct->_Segment,
				instruct->_OPOne->_Reg_Expand,
				instruct->_OPOne->_BaseAddrState,
				instruct->_OPOne->_BaseAddrReg,
				instruct->_OPOne->_BaseAddrTimes,
				instruct->_OPOne->_BaseAddrOffsetFlag,
				instruct->_OPOne->_Imm_Offset
			);
			if (null == mem)
			{
				cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_NULL_POINTER__, cpu->IP);
				(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
				return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
			}
			if (instruct->_Lock)
				cpu->System->Lock(cpu->System);
			uint64 __VAR__ temp = BytesToUint64
			(
				(byte __PTR__)mem,
				instruct->_OPNumber
			);
			if (instruct->_Lock)
				cpu->System->UnLock(cpu->System);
			cpu->FLAGREG = fidiv_asm
			(
				__V_To_P__ cpu->ST[cpu->STP],
				__V_To_P__ temp,
				__V_To_P__ cpu->ST[cpu->STP]
			);
		}
		break;
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