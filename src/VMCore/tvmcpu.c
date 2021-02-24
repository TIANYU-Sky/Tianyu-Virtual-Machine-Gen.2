#include"tvmcpureal.h"

//
// 获取操作地址
//
uint64 __VAR__ GetCPUAddressOther
(
	struct cpu  __PTR__ cpu_dev,            // CPU对象
	int8        __VAR__ segment,            // 指定的段寄存器
	int8        __VAR__ reg,                // 指定的寄存器
	bool        __VAR__ base_state,         // 指示基址寄存器是否有效
	int8        __VAR__ base_reg,           // 指定基址寄存器
	int8        __VAR__ base_times,         // 指示基址倍率
	bool        __VAR__ offset_state,       // 指示是否存在偏移量
	uint64      __VAR__ offset              // 提供偏移量
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
// 指令译码器
// 返回解析的指令对象
//
extern InstructionPackage __VAR__ InstructionDecoder
(
	CPU __PTR__ cpu_dev,		// 用于解析的CPU对象
	bool __PTR__ excuter_flag	// 执行器的执行状态标志
);

//
// CPU执行器
//
void __VAR__ CPUExcuter
(
	CPU __PTR__ cpu_dev // CPU对象
)
{
	bool excuter_flag = __TYVM_CPU_EXCUTE__;	// 创建执行状态标志

	while (excuter_flag)	// 执行状态有效时执行
	{
		// 解析一个指令
		InstructionPackage instruction = InstructionDecoder(cpu_dev, __V_To_P__ excuter_flag);
		// 调用执行指令方法
		instruction.Run(__V_To_P__ instruction, cpu_dev, __V_To_P__ excuter_flag);
		// 释放第一操作数资源（如果存在）
		if (null != instruction._OPOne)
			free(instruction._OPOne);
		// 释放第二操作数资源（如果存在）
		if (null != instruction._OPTwo)
			free(instruction._OPTwo);
	}
}

//
// 创建一个可以用于执行的CPU对象
// 返回一个CPU对象
//
CPU __PTR__ CreateCPU
(
	TVMSystem __PTR__ system,				// 系统接口
	uint64    __VAR__ thread_code,			// 线程号
	uint64    __VAR__ progress_code,		// 进程号
	uint64    __VAR__ instruction_pointer,	// 指令指针寄存器应该装载的值
	uint64    __VAR__ stack_pointer,		// 堆栈寄存器指针
	uint64    __VAR__ stack_size			// 堆栈大小
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
// 用于执行的线程调用入口
// 返回系统调用结束值
//
object __VAR__ __stdcall ExcuteEnter
(
	object __VAR__ obj	// 传入的初始参数
)
{
	if (null != obj)
	{
		CPU __PTR__ cpu = (CPU __PTR__)obj;	// 参数转换
		CPUExcuter(cpu);	// 启动CPU并执行
		// 结束执行后释放CPU资源
		byte __PTR__ stack = (byte __PTR__)(cpu->StackBottom);
		free(stack);
		free(obj);
	}
	return null;
}