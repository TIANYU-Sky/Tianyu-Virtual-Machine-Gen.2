#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

//
// JMP指令操作方法子函数
// 返回执行状态标志
// 
byte __VAR__ JMP_SubFun(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	switch (instruct->_OPOne->_Addressing)
	{
	case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__:
		cpu->IP += cpu->GREG[instruct->_OPOne->_Reg_Expand];
		break;
	case __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_IMM__:
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
		cpu->IP += BytesToUint64((byte __PTR__)mem, instruct->_OPNumber);
		if (instruct->_Lock)
			cpu->System->UnLock(cpu->System);
	}
	break;
	}

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// JMP指令操作方法
// 返回执行状态标志
// 
byte __VAR__ JMP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	if (null != instruct->_OPOne)
		return JMP_SubFun(instruct, cpu, excuter_flag);
	else
	{
		cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_CPU_INSTRUCTION_ERROR__, cpu->IP);
		(__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
		return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
	}
}