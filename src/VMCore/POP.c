#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

//
// POP指令操作方法
// 返回执行状态标志
// 
byte __VAR__ POP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne)
	{
		cpu->GREG[__TYVM_REGISTER_RSP__] -= instruct->_OPNumber;		// 出栈指针下移
		if (cpu->StackBottom <= cpu->GREG[__TYVM_REGISTER_RSP__])
		{
			switch (instruct->_OPOne->_Addressing)
			{
			case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
				cpu->GREG[instruct->_OPOne->_Reg_Expand] = BytesToUint64
				(
					(byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__]),	// 转换栈指针
					instruct->_OPNumber
				);
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
				for (int i = 0; i < instruct->_OPNumber; ++i)
					((byte __PTR__)mem)[i] = ((byte __PTR__)cpu->GREG[__TYVM_REGISTER_RSP__])[i];
				if (instruct->_Lock)
					cpu->System->UnLock(cpu->System);
			}
			break;
			}
		}
		else
		{
			cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__, cpu->GREG[__TYVM_REGISTER_RSP__]);
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