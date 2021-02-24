#include"tvmcpureal.h"

//
// ��ȡ������ַ
//
uint64 __VAR__ GetCPUAddressOther
(
	struct cpu  __PTR__ cpu_dev,            // CPU����
	int8        __VAR__ segment,            // ָ���ĶμĴ���
	int8        __VAR__ reg,                // ָ���ļĴ���
	bool        __VAR__ base_state,         // ָʾ��ַ�Ĵ����Ƿ���Ч
	int8        __VAR__ base_reg,           // ָ����ַ�Ĵ���
	int8        __VAR__ base_times,         // ָʾ��ַ����
	bool        __VAR__ offset_state,       // ָʾ�Ƿ����ƫ����
	uint64      __VAR__ offset              // �ṩƫ����
)
{
	uint64 __VAR__ seg = 0;
	switch (segment)
	{
	case __INSTRUCTION_SEGMENT_CODESEG__:
		seg = cpu_dev->CS;
		break;
	case __INSTRUCTION_SEGMENT_DATASEG__:
		seg = cpu_dev->DS;
		break;
	case __INSTRUCTION_SEGMENT_STACKSEG__:
		seg = cpu_dev->SS;
		break;
	case __INSTRUCTION_SEGMENT_EXPANDSEG__:
		seg = cpu_dev->ES;
		break;
	case __INSTRUCTION_SEGMENT_DEFAULTSEG__:
		switch (reg)
		{
		case __TYVM_REGISTER_RSP__:
			seg = cpu_dev->SS;
			break;
		case __TYVM_REGISTER_RAX__:
		case __TYVM_REGISTER_RBX__:
		case __TYVM_REGISTER_RCX__:
		case __TYVM_REGISTER_RDX__:
		case __TYVM_REGISTER_RBP__:
		case __TYVM_REGISTER_RSI__:
		case __TYVM_REGISTER_RDI__:
			seg = cpu_dev->DS;
			break;
		case __TYVM_REGISTER_R8__:
		case __TYVM_REGISTER_R9__:
		case __TYVM_REGISTER_R10__:
		case __TYVM_REGISTER_R11__:
		case __TYVM_REGISTER_R12__:
		case __TYVM_REGISTER_R13__:
		case __TYVM_REGISTER_R14__:
		case __TYVM_REGISTER_R15__:
			seg = cpu_dev->ES;
			break;
		}
		break;
	case __INSTRUCTION_SEGMENT_NULL__:
	default:
		break;
	}

	return seg +
		cpu_dev->GREG[reg] +
		((base_state ? cpu_dev->GREG[reg] : 0) << base_times) +
		(offset_state ? offset : 0);
}

//
// ָ��������
// ���ؽ�����ָ�����
//
extern InstructionPackage __VAR__ InstructionDecoder
(
	CPU __PTR__ cpu_dev,		// ���ڽ�����CPU����
	bool __PTR__ excuter_flag	// ִ������ִ��״̬��־
);

//
// CPUִ����
//
void __VAR__ CPUExcuter
(
	CPU __PTR__ cpu_dev // CPU����
)
{
	bool excuter_flag = __TYVM_CPU_EXCUTE__;	// ����ִ��״̬��־

	while (excuter_flag)	// ִ��״̬��Чʱִ��
	{
		// ����һ��ָ��
		InstructionPackage instruction = InstructionDecoder(cpu_dev, __V_To_P__ excuter_flag);
		// ����ִ��ָ���
		instruction.Run(__V_To_P__ instruction, cpu_dev, __V_To_P__ excuter_flag);
		// �ͷŵ�һ��������Դ��������ڣ�
		if (null != instruction._OPOne)
			free(instruction._OPOne);
		// �ͷŵڶ���������Դ��������ڣ�
		if (null != instruction._OPTwo)
			free(instruction._OPTwo);
	}
}

//
// ����һ����������ִ�е�CPU����
// ����һ��CPU����
//
CPU __PTR__ CreateCPU
(
	TVMSystem __PTR__ system,				// ϵͳ�ӿ�
	uint64    __VAR__ thread_code,			// �̺߳�
	uint64    __VAR__ progress_code,		// ���̺�
	uint64    __VAR__ instruction_pointer,	// ָ��ָ��Ĵ���Ӧ��װ�ص�ֵ
	uint64    __VAR__ stack_pointer,		// ��ջ�Ĵ���ָ��
	uint64    __VAR__ stack_size			// ��ջ��С
)
{
	TVMCPU __PTR__ cpu = (TVMCPU __PTR__)malloc(sizeof(TVMCPU));
	if (null != cpu)
	{
		cpu->Base.System = system;

		cpu->Base.ThreadCode = thread_code;
		cpu->Base.ProgressCode = progress_code;
		cpu->Base.IP = instruction_pointer;
		cpu->Base.StackBottom = stack_pointer;
		cpu->Base.StackTop = stack_pointer + stack_size + 1;
		cpu->Base.GREG[__TYVM_REGISTER_RSP__] = cpu->Base.StackBottom;

		cpu->Base.GREG[__TYVM_REGISTER_RAX__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_RBX__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_RCX__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_RDX__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_R8__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_R9__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_R10__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_R11__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_R12__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_R13__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_R14__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_R15__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_RBP__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_RSI__] = __Unsigned_Int64_Min__;
		cpu->Base.GREG[__TYVM_REGISTER_RDI__] = __Unsigned_Int64_Min__;

		cpu->Base.CS = __Unsigned_Int64_Min__;
		cpu->Base.SS = __Unsigned_Int64_Min__;
		cpu->Base.DS = __Unsigned_Int64_Min__;
		cpu->Base.ES = __Unsigned_Int64_Min__;

		cpu->Base.CalculateMemory = GetCPUAddressOther;
	}
	return (CPU __PTR__)cpu;
}

//
// ����ִ�е��̵߳������
// ����ϵͳ���ý���ֵ
//
object __VAR__ __stdcall ExcuteEnter
(
	object __VAR__ obj	// ����ĳ�ʼ����
)
{
	if (null != obj)
	{
		CPU __PTR__ cpu = (CPU __PTR__)obj;	// ����ת��
		CPUExcuter(cpu);	// ����CPU��ִ��
		// ����ִ�к��ͷ�CPU��Դ
		byte __PTR__ stack = (byte __PTR__)(cpu->StackBottom);
		free(stack);
		free(obj);
	}
	return null;
}