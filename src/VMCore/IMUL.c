#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>


extern uint64 __VAR__ imul_asm(uint64 __VAR__ op1, uint64 __VAR__ op2, uint64 __PTR__ consult, uint64 __PTR__ remainder);

//
// IMUL指令操作方法
// 返回执行状态标志
// 
byte __VAR__ IMUL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne && null != instruct->_OPTwo)
	{
		switch (instruct->_OPOne->_Addressing)
		{
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
			switch (instruct->_OPTwo->_OPType)
			{
			case __INSTRUCTION_SECOND_OPTYPE_REG__:
				if (instruct->_OPDirect)
					cpu->FLAGREG = imul_asm
					(
						cpu->GREG[instruct->_OPTwo->_Reg_Imm],
						cpu->GREG[cpu, instruct->_OPOne->_Reg_Expand],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RDX__],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
					);
				else
					cpu->FLAGREG = imul_asm
					(
						cpu->GREG[instruct->_OPOne->_Reg_Expand],
						cpu->GREG[instruct->_OPTwo->_Reg_Imm],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RDX__],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
					);
				break;
			case __INSTRUCTION_SECOND_OPTYPE_IMM__:
				if (instruct->_OPDirect)
					cpu->FLAGREG = imul_asm
					(
						instruct->_OPTwo->_Reg_Imm,
						cpu->GREG[instruct->_OPOne->_Reg_Expand],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RDX__],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
					);
				else
					cpu->FLAGREG = imul_asm
					(
						cpu->GREG[instruct->_OPOne->_Reg_Expand],
						instruct->_OPTwo->_Reg_Imm,
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RDX__],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
					);
				break;
			default:
				break;
			}
			break;
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
			switch (instruct->_OPTwo->_OPType)
			{
			case __INSTRUCTION_SECOND_OPTYPE_REG__:
				if (instruct->_OPDirect)
					cpu->FLAGREG = imul_asm
					(
						cpu->GREG[instruct->_OPTwo->_Reg_Imm],
						BytesToUint64((byte __PTR__)mem, instruct->_OPNumber),
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RDX__],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
					);
				else
					cpu->FLAGREG = imul_asm
					(
						BytesToUint64((byte __PTR__)mem, instruct->_OPNumber),
						cpu->GREG[instruct->_OPTwo->_Reg_Imm],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RDX__],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
					);
				break;
			case __INSTRUCTION_SECOND_OPTYPE_IMM__:
				if (instruct->_OPDirect)
					cpu->FLAGREG = imul_asm
					(
						instruct->_OPTwo->_Reg_Imm,
						BytesToUint64((byte __PTR__)mem, instruct->_OPNumber),
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RDX__],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
					);
				else
					cpu->FLAGREG = imul_asm
					(
						BytesToUint64((byte __PTR__)mem, instruct->_OPNumber),
						instruct->_OPTwo->_Reg_Imm,
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RDX__],
						__V_To_P__ cpu->GREG[__TYVM_REGISTER_RAX__]
					);
				break;
			default:
				break;
			}
			if (instruct->_Lock)
				cpu->System->UnLock(cpu->System);
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