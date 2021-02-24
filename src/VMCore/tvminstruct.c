#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

// ָ��ת������
#define POINTER(cs, ip) ((byte __PTR__)(cs + (__P_To_V__ ip)))

extern byte __VAR__ NOP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ STC(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ CLC(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ CMC(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ RET(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ PUSHF(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ POPF(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ PUSHA(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ POPA(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);

extern byte __VAR__ PUSH(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ POP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ DIN(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ LDS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ LES(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ LCS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ LSS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ LAF(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ SAF(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ LAIP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ SAIP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ INC(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ DEC(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ NEG(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JMP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ CALL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JE_Z(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JNE_Z(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JNS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JC(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JNC(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JO(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JNO(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JPO_JNP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JP_JPE(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ LOOP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ JCXZ(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ INT_INST(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ NOT(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);

extern byte __VAR__ MOV(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ CMPXCHG(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ DOUT(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ LEA(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ ADD(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ SUB(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ CMP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ MUL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ IMUL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ DIV(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ IDIV(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ AND(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ OR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ XOR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ SHR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ SAR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ SHL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ SAL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);

extern byte __VAR__ FINIT(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FCLEX(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FNOP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FLDZ(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FLD1(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FLDPI(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FLDL2T(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FLDL2E(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FLDLG2(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FLDLN2(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FDECSTP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FINCSTP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);

extern byte __VAR__ FXCH(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FLD(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FILD(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FST(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FIST(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FCMP(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FADD(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FIADD(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FSUB(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FSUBR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FISUB(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FISUBR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FMUL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FIMUL(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FDIV(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FDIVR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FIDIV(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FIDIVR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);

extern byte __VAR__ FSIN(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FCOS(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);

extern byte __VAR__ FXCH_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FCMP_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FADD_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FSUB_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FSUBR_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FMUL_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FDIV_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FDIVR_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FCHS_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FABS_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);
extern byte __VAR__ FSQRT_A(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag);

byte __VAR__ INSTRCUTION_ERROR(struct instructionpackage __PTR__ instruct, CPU __PTR__ cpu, bool __PTR__ excuter_flag)
{
	cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_UNKNOWN_ERROR__, cpu->IP);
	return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
}

// 
// ���ڻ�ȡָ��ĵ�һ������
// ���ص�һ����������
//
InstructionPackageOPOne __PTR__ GetOPOne
(
	TVMSystem			__PTR__ sys,			// ϵͳ�ӿ� �����쳣����
	uint64				__VAR__ cs,				// ָ��μĴ���
	uint64				__PTR__ ip,				// ָ��ָ��Ĵ���
	bool				__PTR__ excuter_flag,	// ϵͳָ��ִ��״̬��־
	byte				__PTR__ second			// �ڶ�����������
)
{
	// ��ȡ��һ����������1
	byte __VAR__ temp = POINTER(cs, ip)[0];
	++(__P_To_V__ ip);
	// ���µڶ�����������
	(__P_To_V__ second) = temp & __INSTRUCTION_SECOND_OPTYPE_TEST__;

	// ������һ����������
	InstructionPackageOPOne __PTR__ one = (InstructionPackageOPOne __PTR__)malloc(sizeof(InstructionPackageOPOne));
	if (null != one)
	{
		// ��ȡ�Ĵ���/��չ��
		byte __VAR__ reg_imm = (temp >> 2)& __TYVM_REG_IMM_TEST__;

		// ��ȡѰַ��ʽ ������
		switch (temp >> 6)
		{
		case __INSTRUCTION_ADDRESSING_REG_DIRECT__:	// �Ĵ���������
			// ָ���Ĵ�������������
			one->_Addressing = __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_REG__;
			// �ṩ�Ĵ���
			one->_Reg_Expand = reg_imm;	
			break;
		case __INSTRUCTION_ADDRESSING_IMM_DIRECT__:	// ������������
			// ָ������������������
			one->_Addressing = __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_IMM__;
			// ���¸��µڶ�����������һ������Ϊ������������ʱ���ڶ���������Ч
			(__P_To_V__ second) = __INSTRUCTION_SECOND_OPTYPE_NONE__;
			// ��ȡ��չ��������
			one->_Imm_Offset = BytesToUint64
			(
				POINTER(cs, ip),
				reg_imm
			);
			(__P_To_V__ ip) += reg_imm;
			break;
		case __INSTRUCTION_ADDRESSING_IMM_INDIRECT__:	// ���������Ѱַ
			// �����ڴ���ʣ�����lock״̬ȷ���Ƿ������
			one->_Addressing = __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_MEM__;
			// ���üĴ�����Ч
			one->_Reg_Expand = __INSTRUCTION_PACKAGE_OPONE_REG_INVAILD__;

			// ���û�ַ�Ĵ���״̬Ϊ��Ч
			one->_BaseAddrState = __INSTRUCTION_OPONE_BASE_ADDR_STATE_INVAILD__;
			// ���û�ַ�Ĵ�����Ч
			one->_BaseAddrReg = __INSTRUCTION_PACKAGE_OPONE_REG_INVAILD__;
			// ����ƫ������Ч
			one->_BaseAddrOffsetFlag = __INSTRUCTION_OPONE_BASE_ADDR_OFFSET_VAILD__;
			// ��ȡ��չ��ƫ����
			one->_Imm_Offset = BytesToUint64
			(
				POINTER(cs, ip),
				8
			);
			(__P_To_V__ ip) += 8;
			break;
		case __INSTRUCTION_ADDRESSING_OTHER__:	// ����Ѱַ��ʽ
			// �����ڴ���ʣ�����lock״̬ȷ���Ƿ������
			one->_Addressing = __INSTRUCTION_PACKAGE_OPONE_ADDRESSING_MEM__;
			//���üĴ���
			one->_Reg_Expand = reg_imm;

			// ��ȡ��һ����������2
			temp = POINTER(cs, ip)[0];
			++(__P_To_V__ ip);

			// ����ƫ�����Ƿ���Ч
			one->_BaseAddrOffsetFlag = temp & 0b00000001 ?
				__INSTRUCTION_OPONE_BASE_ADDR_OFFSET_VAILD__ :
				__INSTRUCTION_OPONE_BASE_ADDR_OFFSET_INVAILD__;
			if (one->_BaseAddrOffsetFlag)
			{
				// ƫ������Чʱ ��ȡ8�ֽڵ�ƫ����
				one->_Imm_Offset = BytesToUint64
				(
					POINTER(cs, ip),
					8
				);
				(__P_To_V__ ip) += 8;
			}

			// ���û�ַ�Ĵ�������
			one->_BaseAddrTimes = (temp >> 1)& __INSTRUCTION_OPONE_BASE_ADDR_TIMES_TEST__;
			// ���û�ַ�Ĵ���
			one->_BaseAddrReg = (temp >> 3)& __TYVM_REG_IMM_TEST__;
			// ���û�ַ�Ĵ����Ƿ���Ч
			one->_BaseAddrState = (temp >> 7) & 0b00000001;
			break;
		}
	}

	return one;
}

// 
// ���ڻ�ȡָ��ĵڶ�������
// ���صڶ�����������
//
InstructionPackageOPTwo __PTR__ GetOPTwo
(
	TVMSystem			__PTR__ sys,			// ϵͳ�ӿ� �����쳣����
	uint64				__VAR__ cs,				// ָ��μĴ���
	uint64				__PTR__ ip,				// ָ��ָ��Ĵ���
	bool				__PTR__ excuter_flag,	// ϵͳָ��ִ��״̬��־
	byte				__VAR__ second			// �ڶ�����������
)
{
	// ���ڶ����������� ��Ϊ�޲����� ������ϵͳCPU����ʧ���쳣
	if (__INSTRUCTION_SECOND_OPTYPE_NONE__ == second) 
	{
		sys->SysException(sys, __TYVM_RUNNING_EXCEPTION_CPU_DECODER_ERROR__, cs + (__P_To_V__ ip));
		(__P_To_V__ excuter_flag) =__TYVM_CPU_STOP__;
		return null;
	}
	// �����ڶ�����������
	InstructionPackageOPTwo __PTR__ two = (InstructionPackageOPTwo __PTR__)malloc(sizeof(InstructionPackageOPTwo));
	if (null != two)
	{
		// ���õڶ�����������
		two->_OPType = second;
		switch (second)
		{
		case __INSTRUCTION_SECOND_OPTYPE_REG__:	// �Ĵ���������
			// ���ò����Ĵ���
			two->_Reg_Imm = POINTER(cs, ip)[0] & __TYVM_REG_IMM_TEST__;
			// ָ�����
			++(__P_To_V__ ip);
			break;
		case __INSTRUCTION_SECOND_OPTYPE_IMM__:
			// ���ò���������
			switch (POINTER(cs, ip)[0] & __TYVM_REG_IMM_TEST__)
			{
			case __INSTRUCTION_OPNUM_IMM_SIZE_64__:	// ��ȡ64λ��������
				two->_Reg_Imm = BytesToUint64
				(
					POINTER(cs, ip),
					8
				);
				(__P_To_V__ ip) += 8;
				break;
			case __INSTRUCTION_OPNUM_IMM_SIZE_32__:	// ��ȡ32λ��������
				two->_Reg_Imm = BytesToUint64
				(
					POINTER(cs, ip),
					4
				);
				(__P_To_V__ ip) += 4;
				break;
			case __INSTRUCTION_OPNUM_IMM_SIZE_16__:	// ��ȡ16λ��������
				two->_Reg_Imm = BytesToUint64
				(
					POINTER(cs, ip),
					2
				);
				(__P_To_V__ ip) += 2;
				break;
			case __INSTRUCTION_OPNUM_IMM_SIZE_8__: 	// ��ȡ8λ��������
				two->_Reg_Imm = BytesToUint64
				(
					POINTER(cs, ip),
					1
				);
				(__P_To_V__ ip) += 1;
				break;
			}
			// ָ�����
			++(__P_To_V__ ip);
			break;
		case __INSTRUCTION_SECOND_OPTYPE_EXP__:	// ��չ������
			// ��ǰָ��ϵͳ��������չ������ָ��
			// ��ǰ��չ������Ϊ��
			// ������չ������ʱ�������쳣
			two->_OPType = __INSTRUCTION_SECOND_OPTYPE_IMM__;
			two->_Reg_Imm = 0;
			break;
		}
	}
	return two;
}

//
// ������
// ����ָ������
//
uint8 __VAR__ Decoder
(
	TVMSystem			__PTR__ sys,			// ϵͳ�ӿ� �����쳣����
	uint64				__VAR__ cs,				// ָ��μĴ��� 
	uint64				__PTR__ ip,				// ָ��ָ��Ĵ��� 
	InstructionPackage	__PTR__ instr,			// ָ���������
	bool				__PTR__ excuter_flag	// ϵͳָ��ִ��״̬��־
)
{
	// ������״̬
	instr->_Lock = __INSTRUCTION_LOCK_STATE_UNLOCK__;

	// ������ʱָ������
	uint8	__VAR__ instr_code = __TYVM_INSTRUCTION_INVAILD__;
	// ������ʱ�������
	byte	__VAR__ temp = 0x00;

	// �����ɶ�״̬
	bool	__VAR__ read_flag = true;
	bool	__VAR__ prefix_fun = false;	// ��������ָ��ͷ��ȡ״̬
	bool	__VAR__ prefix_reg = false; // �����Ĵ���ָ��ͷ��ȡ״̬
	while (read_flag && (__P_To_V__ excuter_flag)) // �ɶ����޴���ʱִ��
	{
		temp = POINTER(cs, ip)[0]; // ��ȡָ��ͷ
		switch (temp & __TYVM_INSTRUCTION_PREFIX_TEST__)
		{
		case __TYVM_INSTRUCTION_PREFIX_FUNCTION__:	// ��ǰΪָ��ǰ׺��0x90
			// ����ǰ׺ƥ�䣬���趨ǰ׺״̬
			// ǰ׺��ʽ��1001 [xxx] (0|1) ֻƥ��1-3λ
			if (prefix_fun) // ���ڶ��ָ��ͷ ����CPU�����쳣
			{
				sys->SysException(sys, __TYVM_RUNNING_EXCEPTION_CPU_DECODER_ERROR__, cs + (__P_To_V__ ip));
				(__P_To_V__ excuter_flag) =__TYVM_CPU_STOP__;
			}
			else 
			{
				prefix_fun = !prefix_fun;	// ���ù���ͷ�Ѷ�ȡ
				temp >>= 1;
				switch (temp & __INSTRUCTION_SEGMENT_DEFAULTSEG__)
				{
				case __INSTRUCTION_SEGMENT_CODESEG__:	// �����
				case __INSTRUCTION_SEGMENT_DATASEG__:	// ���ݶ�
				case __INSTRUCTION_SEGMENT_EXPANDSEG__:	// ��չ��
				case __INSTRUCTION_SEGMENT_STACKSEG__:	// ��ջ��
				case __INSTRUCTION_SEGMENT_NULL__:		// �޶μĴ���
					// ��ȡ�μĴ���״̬
					instr->_Segment = temp & __INSTRUCTION_SEGMENT_DEFAULTSEG__;
					break;
				default:
					// ��Ч�ĶμĴ������� ����CPU�����쳣
					sys->SysException(sys, __TYVM_RUNNING_EXCEPTION_CPU_DECODER_ERROR__, cs + (__P_To_V__ ip));
					(__P_To_V__ excuter_flag) =__TYVM_CPU_STOP__;
					break;
				}
			}
			break;
		case __TYVM_INSTRUCTION_PREFIX_REGISTER__:	// ��ǰΪָ��ǰ׺��0x60
			// ����ǰ׺ƥ�䣬���趨ǰ׺״̬
			// ǰ׺��ʽ��0110 [xx] [x] [x]
			if (prefix_reg) // ���ڶ��ָ��ͷ ����CPU�����쳣
			{
				sys->SysException(sys, __TYVM_RUNNING_EXCEPTION_CPU_DECODER_ERROR__, cs + (__P_To_V__ ip));
				(__P_To_V__ excuter_flag) =__TYVM_CPU_STOP__;
			}
			else
			{
				prefix_reg = !prefix_reg;	// ���üĴ���ָ��ͷ�Ѷ�ȡ
				// ����ָ����״̬
				instr->_Lock = temp & __INSTRUCTION_LOCK_STATE_TEST__ ?
					__INSTRUCTION_LOCK_STATE_LOCK__ :
					__INSTRUCTION_LOCK_STATE_UNLOCK__;
				// ���ò���������
				instr->_OPDirect = temp & __INSTRUCTION_OPDIRECT_TEST__ ?
					__INSTRUCTION_OPDIRECT_TWO_TO_ONE__ :
					__INSTRUCTION_OPDIRECT_ONE_TO_TWO__;
				// ���ò�������С
				switch ((temp >> 2)& __INSTRUCTION_OPNUMBER_8__)
				{
				case __INSTRUCTION_OPNUMBER_64__:
					instr->_OPNumber = __INSTRUCTION_OPNUM_IMM_SIZE_64__;
					break;
				case __INSTRUCTION_OPNUMBER_32__:
					instr->_OPNumber = __INSTRUCTION_OPNUM_IMM_SIZE_32__;
					break;
				case __INSTRUCTION_OPNUMBER_16__:
					instr->_OPNumber = __INSTRUCTION_OPNUM_IMM_SIZE_16__;
					break;
				case __INSTRUCTION_OPNUMBER_8__:
					instr->_OPNumber = __INSTRUCTION_OPNUM_IMM_SIZE_8__;
					break;
				}
			}
			break;
		default:	// ��ȡΪָ�� ����ͷ����
			instr_code = temp;
			read_flag = false;
			break;
		}
		++(__P_To_V__ ip);
	}
	if ((__P_To_V__ excuter_flag))	// ����ִ��״̬
	{
		// ���쳣״̬

		// �����ڶ�������������ʱ���� ����Ϊ�޵ڶ�������
		byte __VAR__ second_optype = __INSTRUCTION_SECOND_OPTYPE_NONE__;
		switch (instr_code & __TYVM_INSTRUCTION_OPNUM_TEST__)	// ������������Ŀ
		{
		case __TYVM_INSTRUCTION_OPNUM_ZERO_A__:
		case __TYVM_INSTRUCTION_OPNUM_ZERO_B__:	// �޲�����ָ��
		case __TYVM_INSTRUCTION_OPNUM_ZERO_C__:	// �޲�����ָ��
			break;
		case __TYVM_INSTRUCTION_OPNUM_TWO_A__:
		case __TYVM_INSTRUCTION_OPNUM_TWO_B__:
		case __TYVM_INSTRUCTION_OPNUM_TWO_C__:	// ��������ָ��
			instr->_OPOne = GetOPOne(sys, cs, ip, excuter_flag, __V_To_P__ second_optype);
			if ((__P_To_V__ excuter_flag))
				return instr_code;
			instr->_OPTwo = GetOPTwo(sys, cs, ip, excuter_flag, second_optype);
			if ((__P_To_V__ excuter_flag))
				return instr_code;
			break;
		case __TYVM_INSTRUCTION_OPNUM_ONE_A__:
		case __TYVM_INSTRUCTION_OPNUM_ONE_B__:
		case __TYVM_INSTRUCTION_OPNUM_ONE_C__:
		case __TYVM_INSTRUCTION_OPNUM_ONE_D__:
		case __TYVM_INSTRUCTION_OPNUM_ONE_E__:
		case __TYVM_INSTRUCTION_OPNUM_ONE_F__:	// һ������ָ��
			instr->_OPOne = GetOPOne(sys, cs, ip, excuter_flag, __V_To_P__ second_optype);
			if ((__P_To_V__ excuter_flag))
				return instr_code;
			break;
		default:	// �����������ڵ�ָ��� ����CPU�����쳣
			sys->SysException(sys, __TYVM_RUNNING_EXCEPTION_CPU_DECODER_ERROR__, cs + (__P_To_V__ ip));
			(__P_To_V__ excuter_flag) =__TYVM_CPU_STOP__;
			break;
		}
	}
	return instr_code;
}

//
// ָ��������
// ���ؽ�����ָ�����
//
InstructionPackage __VAR__ InstructionDecoder
(
	CPU __PTR__ cpu_dev,		// ���ڽ�����CPU����
	bool __PTR__ excuter_flag	// ִ������ִ��״̬��־
)
{
	InstructionPackage instruction;	// ����ָ�����
	instruction._Segment = __INSTRUCTION_SEGMENT_DEFAULTSEG__;		// ���öμĴ���ΪĬ�϶�
	instruction._OPDirect = __INSTRUCTION_OPDIRECT_ONE_TO_TWO__;	// ���ò���������Ϊ[1]��[2]
	instruction._OPNumber = __INSTRUCTION_OPNUM_IMM_SIZE_64__;		// ����Ĭ�ϲ�������СΪ64λ
	instruction._OPOne = null;	// ���õ�һ������Ϊ��
	instruction._OPTwo = null;	// ���õڶ�������Ϊ��

	// ���ý���������ȡָ����
	int8 __VAR__ instruct_code = Decoder
	(
		cpu_dev->System,		// ϵͳ�ӿ�
		cpu_dev->CS,			// ָ��μĴ���
		__V_To_P__ cpu_dev->IP,	// ָ��ָ��Ĵ���
		__V_To_P__ instruction,	// ��ǰ������ָ�����
		excuter_flag			// ִ������ִ��״̬
	);
	// ����ָ���� �����ö�����ִ�з���
	switch (instruct_code)
	{
	case __TYVM_INSTRUCTION_NOP__:
		instruction.Run = NOP;
		break;
	case __TYVM_INSTRUCTION_STC__:
		instruction.Run = STC;
		break;
	case __TYVM_INSTRUCTION_CLC__:
		instruction.Run = CLC;
		break;
	case __TYVM_INSTRUCTION_CMC__:
		instruction.Run = CMC;
		break;
	case __TYVM_INSTRUCTION_RET__:
		instruction.Run = RET;
		break;
	case __TYVM_INSTRUCTION_PUSHF__:
		instruction.Run = PUSHF;
		break;
	case __TYVM_INSTRUCTION_POPF__:
		instruction.Run = POPF;
		break;
	case __TYVM_INSTRUCTION_PUSHA__:
		instruction.Run = PUSHA;
		break;
	case __TYVM_INSTRUCTION_POPA__:
		instruction.Run = POPA;
		break;
	case __TYVM_INSTRUCTION_PUSH__:
		instruction.Run = PUSH;
		break;
	case __TYVM_INSTRUCTION_POP__:
		instruction.Run = POP;
		break;
	case __TYVM_INSTRUCTION_IN__:
		instruction.Run = DIN;
		break;
	case __TYVM_INSTRUCTION_LDS__:
		instruction.Run = LDS;
		break;
	case __TYVM_INSTRUCTION_LES__:
		instruction.Run = LES;
		break;
	case __TYVM_INSTRUCTION_LCS__:
		instruction.Run = LCS;
		break;
	case __TYVM_INSTRUCTION_LSS__:
		instruction.Run = LSS;
		break;
	case __TYVM_INSTRUCTION_LAF__:
		instruction.Run = LAF;
		break;
	case __TYVM_INSTRUCTION_SAF__:
		instruction.Run = SAF;
		break;
	case __TYVM_INSTRUCTION_LAIP__:
		instruction.Run = LAIP;
		break;
	case __TYVM_INSTRUCTION_SAIP__:
		instruction.Run = SAIP;
		break;
	case __TYVM_INSTRUCTION_INC__:
		instruction.Run = INC;
		break;
	case __TYVM_INSTRUCTION_DEC__:
		instruction.Run = DEC;
		break;
	case __TYVM_INSTRUCTION_NEG__:
		instruction.Run = NEG;
		break;
	case __TYVM_INSTRUCTION_JMP__:
		instruction.Run = JMP;
		break;
	case __TYVM_INSTRUCTION_CALL__:
		instruction.Run = CALL;
		break;
	case __TYVM_INSTRUCTION_JE__:
	case __TYVM_INSTRUCTION_JZ__:
		instruction.Run = JE_Z;
		break;
	case __TYVM_INSTRUCTION_JNE__:
	case __TYVM_INSTRUCTION_JNZ__:
		instruction.Run = JNE_Z;
		break;
	case __TYVM_INSTRUCTION_JS__:
		instruction.Run = JS;
		break;
	case __TYVM_INSTRUCTION_JNS__:
		instruction.Run = JNS;
		break;
	case __TYVM_INSTRUCTION_JC__:
		instruction.Run = JC;
		break;
	case __TYVM_INSTRUCTION_JNC__:
		instruction.Run = JNC;
		break;
	case __TYVM_INSTRUCTION_JO__:
		instruction.Run = JO;
		break;
	case __TYVM_INSTRUCTION_JNO__:
		instruction.Run = JNO;
		break;
	case __TYVM_INSTRUCTION_JNP__:
		break;
	case __TYVM_INSTRUCTION_JPO__:
		instruction.Run = JPO_JNP;
		break;
	case __TYVM_INSTRUCTION_JP__:
	case __TYVM_INSTRUCTION_JPE__:
		instruction.Run = JP_JPE;
		break;
	case __TYVM_INSTRUCTION_LOOP__:
		instruction.Run = LOOP;
		break;
	case __TYVM_INSTRUCTION_JCXZ__:
		instruction.Run = JCXZ;
		break;
	case __TYVM_INSTRUCTION_INT__:
		instruction.Run = INT_INST;
		break;
	case __TYVM_INSTRUCTION_MOV__:
		instruction.Run = MOV;
		break;
	case __TYVM_INSTRUCTION_CMPXCHG__:
		instruction.Run = CMPXCHG;
		break;
	case __TYVM_INSTRUCTION_OUT__:
		instruction.Run = DOUT;
		break;
	case __TYVM_INSTRUCTION_LEA__:
		instruction.Run = LEA;
		break;
	case __TYVM_INSTRUCTION_ADD__:
		instruction.Run = ADD;
		break;
	case __TYVM_INSTRUCTION_SUB__:
		instruction.Run = SUB;
		break;
	case __TYVM_INSTRUCTION_CMP__:
		instruction.Run = CMP;
		break;
	case __TYVM_INSTRUCTION_MUL__:
		instruction.Run = MUL;
		break;
	case __TYVM_INSTRUCTION_IMUL__:
		instruction.Run = IMUL;
		break;
	case __TYVM_INSTRUCTION_DIV__:
		instruction.Run = DIV;
		break;
	case __TYVM_INSTRUCTION_IDIV__:
		instruction.Run = IDIV;
		break;
	case __TYVM_INSTRUCTION_AND__:
		instruction.Run = AND;
		break;
	case __TYVM_INSTRUCTION_OR__:
		instruction.Run = OR;
		break;
	case __TYVM_INSTRUCTION_NOT__:
		instruction.Run = NOT;
		break;
	case __TYVM_INSTRUCTION_XOR__:
		instruction.Run = XOR;
		break;
	case __TYVM_INSTRUCTION_SHR__:
		instruction.Run = SHR;
		break;
	case __TYVM_INSTRUCTION_SAR__:
		instruction.Run = SAR;
		break;
	case __TYVM_INSTRUCTION_SHL__:
		instruction.Run = SHL;
		break;
	case __TYVM_INSTRUCTION_SAL__:
		instruction.Run = SAL;
		break;
	case __TYVM_INSTRUCTION_FINIT__:
		instruction.Run = FINIT;
		break;
	case __TYVM_INSTRUCTION_FNOP__:
		instruction.Run = FNOP;
		break;
	case __TYVM_INSTRUCTION_FLDZ__:
		instruction.Run = FLDZ;
		break;
	case __TYVM_INSTRUCTION_FLD1__:
		instruction.Run = FLD1;
		break;
	case __TYVM_INSTRUCTION_FLDPI__:
		instruction.Run = FLDPI;
		break;
	case __TYVM_INSTRUCTION_FLDL2T__:
		instruction.Run = FLDL2T;
		break;
	case __TYVM_INSTRUCTION_FLDL2E__:
		instruction.Run = FLDL2E;
		break;
	case __TYVM_INSTRUCTION_FLDLG2__:
		instruction.Run = FLDLG2;
		break;
	case __TYVM_INSTRUCTION_FLDLN2__:
		instruction.Run = FLDLN2;
		break;
	case __TYVM_INSTRUCTION_FDECSTP__:
		instruction.Run = FDECSTP;
		break;
	case __TYVM_INSTRUCTION_FINCSTP__:

		instruction.Run = FINCSTP;
		break;
	case __TYVM_INSTRUCTION_FXCH__:
		instruction.Run = FXCH;
		break;
	case __TYVM_INSTRUCTION_FLD__:
		instruction.Run = FLD;
		break;
	case __TYVM_INSTRUCTION_FILD__:
		instruction.Run = FILD;
		break;
	case __TYVM_INSTRUCTION_FST__:
		instruction.Run = FST;
		break;
	case __TYVM_INSTRUCTION_FIST__:
		instruction.Run = FIST;
		break;
	case __TYVM_INSTRUCTION_FCMP__:
		instruction.Run = FCMP;
		break;
	case __TYVM_INSTRUCTION_FADD__:
		instruction.Run = FADD;
		break;
	case __TYVM_INSTRUCTION_FIADD__:
		instruction.Run = FIADD;
		break;
	case __TYVM_INSTRUCTION_FSUB__:
		instruction.Run = FSUB;
		break;
	case __TYVM_INSTRUCTION_FSUBR__:
		instruction.Run = FSUBR;
		break;
	case __TYVM_INSTRUCTION_FISUB__:
		instruction.Run = FISUB;
		break;
	case __TYVM_INSTRUCTION_FISUBR__:
		instruction.Run = FISUBR;
		break;
	case __TYVM_INSTRUCTION_FMUL__:
		instruction.Run = FMUL;
		break;
	case __TYVM_INSTRUCTION_FIMUL__:
		instruction.Run = FIMUL;
		break;
	case __TYVM_INSTRUCTION_FDIV__:
		instruction.Run = FDIV;
		break;
	case __TYVM_INSTRUCTION_FIDIV__:
		instruction.Run = FIDIV;
		break;
	case __TYVM_INSTRUCTION_FDIVR__:
		instruction.Run = FDIVR;
		break;
	case __TYVM_INSTRUCTION_FIDIVR__:
		instruction.Run = FIDIVR;
		break;
	case __TYVM_INSTRUCTION_FCHS__:
		instruction.Run = FCHS_A;
		break;
	case __TYVM_INSTRUCTION_FABS__:
		instruction.Run = FABS_A;
		break;
	case __TYVM_INSTRUCTION_FSQRT__:
		instruction.Run = FSQRT_A;
		break;
	case __TYVM_INSTRUCTION_FXCH_A__:
		instruction.Run = FXCH_A;
		break;
	case __TYVM_INSTRUCTION_FCMP_A__:
		instruction.Run = FCMP_A;
		break;
	case __TYVM_INSTRUCTION_FADD_A__:
		instruction.Run = FADD_A;
		break;
	case __TYVM_INSTRUCTION_FSUB_A__:
		instruction.Run = FSUB_A;
		break;
	case __TYVM_INSTRUCTION_FSUBR_A__:
		instruction.Run = FSUBR_A;
		break;
	case __TYVM_INSTRUCTION_FMUL_A__:
		instruction.Run = FMUL_A;
		break;
	case __TYVM_INSTRUCTION_FDIV_A__:
		instruction.Run = FDIV_A;
		break;
	case __TYVM_INSTRUCTION_FDIVR_A__:
		instruction.Run = FDIVR_A;
		break;
	case __TYVM_INSTRUCTION_FSIN__:
		instruction.Run = FSIN;
		break;
	case __TYVM_INSTRUCTION_FCOS__:
		instruction.Run = FCOS;
		break;
	default:
		instruction.Run = INSTRCUTION_ERROR;
		break;
	}

	return instruction;
}