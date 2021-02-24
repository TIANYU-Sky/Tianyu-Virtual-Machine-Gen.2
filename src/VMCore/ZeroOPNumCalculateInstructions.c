#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>
#include<math.h>

extern byte __VAR__ STP_PUSH(byte __VAR__ stp);
extern byte __VAR__ STP_POP(byte __VAR__ stp);
extern byte __VAR__ STP_INDEX(byte __VAR__ stp, byte __VAR__ index);

extern uint64 __VAR__ fsin_asm(double __PTR__ op);
extern uint64 __VAR__ fcos_asm(double __PTR__ op);
extern uint64 __VAR__ fchs_asm(double __PTR__ op);
extern uint64 __VAR__ fabs_asm(double __PTR__ op);
extern uint64 __VAR__ fsqrt_asm(double __PTR__ op);
extern uint64 __VAR__ fcmp_asm(double __PTR__ op1, double __PTR__ op2);
extern uint64 __VAR__ fadd_asm(double __PTR__ op1, double __PTR__ op2, double __PTR__ result);
extern uint64 __VAR__ fsub_asm(double __PTR__ op1, double __PTR__ op2, double __PTR__ result);
extern uint64 __VAR__ fsubr_asm(double __PTR__ op1, double __PTR__ op2, double __PTR__ result);
extern uint64 __VAR__ fmul_asm(double __PTR__ op1, double __PTR__ op2, double __PTR__ result);
extern uint64 __VAR__ fdiv_asm(double __PTR__ op1, double __PTR__ op2, double __PTR__ result);
extern uint64 __VAR__ fdivr_asm(double __PTR__ op1, double __PTR__ op2, double __PTR__ result);

byte __VAR__ FSIN(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fsin_asm(__V_To_P__ cpu->ST[cpu->STP]);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FCOS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fcos_asm(__V_To_P__ cpu->ST[cpu->STP]);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

byte __VAR__ FCHS_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fchs_asm(__V_To_P__ cpu->ST[cpu->STP]);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FABS_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fabs_asm(__V_To_P__ cpu->ST[cpu->STP]);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FSQRT_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fsqrt_asm(__V_To_P__ cpu->ST[cpu->STP]);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}


byte __VAR__ FXCH_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	
	double temp = cpu->ST[cpu->STP];
	cpu->ST[cpu->STP] = cpu->ST[STP_INDEX(cpu->STP, 1)];
	cpu->ST[STP_INDEX(cpu->STP, 1)] = temp;
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FCMP_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fcmp_asm
	(
		__V_To_P__ cpu->ST[cpu->STP], 
		__V_To_P__ cpu->ST[STP_INDEX(cpu->STP, 1)]
	);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FADD_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fadd_asm
	(
		__V_To_P__ cpu->ST[cpu->STP], 
		__V_To_P__ cpu->ST[STP_INDEX(cpu->STP, 1)], 
		__V_To_P__ cpu->ST[cpu->STP]
	);

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FSUB_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fsub_asm
	(
		__V_To_P__ cpu->ST[cpu->STP],
		__V_To_P__ cpu->ST[STP_INDEX(cpu->STP, 1)],
		__V_To_P__ cpu->ST[cpu->STP]
	);

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FSUBR_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fsubr_asm
	(
		__V_To_P__ cpu->ST[cpu->STP],
		__V_To_P__ cpu->ST[STP_INDEX(cpu->STP, 1)],
		__V_To_P__ cpu->ST[cpu->STP]
	);

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FMUL_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fmul_asm
	(
		__V_To_P__ cpu->ST[cpu->STP],
		__V_To_P__ cpu->ST[STP_INDEX(cpu->STP, 1)],
		__V_To_P__ cpu->ST[cpu->STP]
	);

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FDIV_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fdiv_asm
	(
		__V_To_P__ cpu->ST[cpu->STP],
		__V_To_P__ cpu->ST[STP_INDEX(cpu->STP, 1)],
		__V_To_P__ cpu->ST[cpu->STP]
	);

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}
byte __VAR__ FDIVR_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->FLAGREG = fdivr_asm
	(
		__V_To_P__ cpu->ST[cpu->STP],
		__V_To_P__ cpu->ST[STP_INDEX(cpu->STP, 1)],
		__V_To_P__ cpu->ST[cpu->STP]
	);

	return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}