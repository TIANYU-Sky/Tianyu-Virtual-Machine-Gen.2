#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

//
// CMPXCHG指令操作方法
// 返回执行状态标志
// 
byte __VAR__ CMPXCHG(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne && null != instruct->_OPTwo)
	{
		switch (instruct->_OPOne->_Addressing)
		{
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
			switch (instruct->_OPTwo->_OPType)
			{
			case __INSTRUCTION_SECOND_OPTYPE_REG__:
				cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->IP);
				(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
				return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
			case __INSTRUCTION_SECOND_OPTYPE_IMM__:
					if (cpu->GREG[__TYVM_REGISTER_RAX__] == cpu->GREG[instruct->_OPOne->_Reg_Expand])	// 判断目标操作数与累加器是否相等
					{
						// 相等：将源操作数传递给目标操作数 并置ZF=1
						cpu->GREG[instruct->_OPOne->_Reg_Expand] = instruct->_OPTwo->_Reg_Imm;
						cpu->FLAGREG |= __TYVM_SIGNREGISTER_ZERO_FLAG__;
					}
					else
					{
						// 不相等：将目的操作数传递给累加寄存器 并置ZF=0
						cpu->GREG[__TYVM_REGISTER_RAX__] = cpu->GREG[instruct->_OPOne->_Reg_Expand];
						cpu->FLAGREG &= ~__TYVM_SIGNREGISTER_ZERO_FLAG__;
					}
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
			uint64 __VAR__ data = BytesToUint64((byte __PTR__)mem, instruct->_OPNumber);
			switch (instruct->_OPTwo->_OPType)
			{
			case __INSTRUCTION_SECOND_OPTYPE_REG__:
				cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->IP);
				(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
				return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
			case __INSTRUCTION_SECOND_OPTYPE_IMM__:
				if (cpu->GREG[__TYVM_REGISTER_RAX__] == data)	// 判断目标操作数与累加器是否相等
				{
					// 相等：将源操作数传递给目标操作数 并置ZF=1
					Uint64ToBytes(instruct->_OPTwo->_Reg_Imm, (byte __PTR__)mem, instruct->_OPNumber);
					cpu->FLAGREG |= __TYVM_SIGNREGISTER_ZERO_FLAG__;
				}
				else
				{
					// 不相等：将目的操作数传递给累加寄存器 并置ZF=0
					cpu->GREG[__TYVM_REGISTER_RAX__] = data;
					cpu->FLAGREG &= ~__TYVM_SIGNREGISTER_ZERO_FLAG__;
				}
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