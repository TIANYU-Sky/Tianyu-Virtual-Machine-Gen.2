#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>
#include<math.h>

byte __VAR__ STP_PUSH(byte __VAR__ stp)
{
	// STP_PUSH
	// STP -= 1
	return (stp + 7) & 7;
}
byte __VAR__ STP_POP(byte __VAR__ stp)
{
	return (stp + 1) & 7;
}
byte __VAR__ STP_INDEX(byte __VAR__ stp, byte __VAR__ index)
{
	return (stp + index) & 7;
}

byte __VAR__ FINIT(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = 0;
	cpu->ST[0] = 0.0;
	cpu->ST[1] = 0.0;
	cpu->ST[2] = 0.0;
	cpu->ST[3] = 0.0;
	cpu->ST[4] = 0.0;
	cpu->ST[5] = 0.0;
	cpu->ST[6] = 0.0;
	cpu->ST[7] = 0.0;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FCLEX(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = 0;
	cpu->ST[0] = 0.0;
	cpu->ST[1] = 0.0;
	cpu->ST[2] = 0.0;
	cpu->ST[3] = 0.0;
	cpu->ST[4] = 0.0;
	cpu->ST[5] = 0.0;
	cpu->ST[6] = 0.0;
	cpu->ST[7] = 0.0;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FNOP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	sleep_t(5);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FLDZ(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_PUSH(cpu->STP);
	cpu->ST[cpu->STP] = 0.0;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FLD1(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_PUSH(cpu->STP);
	cpu->ST[cpu->STP] = 1.0;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FLDPI(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_PUSH(cpu->STP);
	cpu->ST[cpu->STP] = M_PI;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FLDL2T(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_PUSH(cpu->STP);
	cpu->ST[cpu->STP] = M_LOG2_10;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FLDL2E(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_PUSH(cpu->STP);
	cpu->ST[cpu->STP] = M_LOG2E;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FLDLG2(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_PUSH(cpu->STP);
	cpu->ST[cpu->STP] = M_LOG10_2;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FLDLN2(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_PUSH(cpu->STP);
	cpu->ST[cpu->STP] = M_LN2;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FDECSTP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_PUSH(cpu->STP);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FINCSTP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->STP = STP_POP(cpu->STP);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}