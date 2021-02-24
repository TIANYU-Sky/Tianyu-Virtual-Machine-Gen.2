#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

//
// CALL指令操作方法
// 返回执行状态标志
// 
byte __VAR__ CALL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne)
	{
		cpu->GREG[__TYVM_REGISTER_RSP__] += 8;		            // 入栈指针上移
		if (cpu->StackTop >= cpu->GREG[__TYVM_REGISTER_RSP__])
			Uint64ToBytes
			(
				cpu->IP,
				(byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 8),	// 转换栈指针
				8
			);
		else
		{
			cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__, cpu->GREG[__TYVM_REGISTER_RSP__]);
			(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
			return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
		}
		switch (instruct->_OPOne->_Addressing)
		{
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
			cpu->IP = cpu->GREG[instruct->_OPOne->_Reg_Expand];
			break;
		case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_IMM__:
			if (__INSTRUCTION_OPNUMBER_64__ == instruct->_OPNumber)
				cpu->IP = instruct->_OPOne->_Imm_Offset;
			else
				cpu->IP += instruct->_OPOne->_Imm_Offset;
			break;
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
			if (__INSTRUCTION_OPNUMBER_64__ == instruct->_OPNumber)
				cpu->IP = BytesToUint64((byte __PTR__)mem, instruct->_OPNumber);
			else
				cpu->IP += BytesToUint64((byte __PTR__)mem, instruct->_OPNumber);
			if (instruct->_Lock)
				cpu->System->UnLock(cpu->System);
		}
		break;
		}
		return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
	}
	else
	{
		cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->GREG[__TYVM_REGISTER_RSP__]);
		(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
		return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
	}
}