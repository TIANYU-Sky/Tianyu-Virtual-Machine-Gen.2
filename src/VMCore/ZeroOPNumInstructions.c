#include<tianyuvm/tvmcpucore.h>
#include<tianyuvm/tvminstruct.h>
#include<tianyuvm/collections.h>

//
// NOP指令操作方法
// 返回执行状态标志
// 
byte __VAR__ NOP
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    sleep_t(5);
    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// RET指令操作方法
// 返回执行状态标志
// 
byte __VAR__ RET
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->GREG[__TYVM_REGISTER_RSP__] -= 8;
    if (cpu->StackBottom <= cpu->GREG[__TYVM_REGISTER_RSP__])
        cpu->IP = BytesToUint64
        (
        (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__]),
            8
        );
    else
    {
        cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__, cpu->GREG[__TYVM_REGISTER_RSP__]);
        (__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
        return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
    }

    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// STC指令操作方法
// 返回执行状态标志
// 
byte __VAR__ STC
(
    struct instructionpackage __PTR__ instruct, 
    CPU __PTR__ cpu, 
    bool __PTR__ excuter_flag
)
{
    cpu->FLAGREG |= __TYVM_SIGNREGISTER_CARRY_FLAG__;

    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// CLC指令操作方法
// 返回执行状态标志
// 
byte __VAR__ CLC
(
    struct instructionpackage __PTR__ instruct, 
    CPU __PTR__ cpu, 
    bool __PTR__ excuter_flag
)
{

    cpu->FLAGREG &= (~__TYVM_SIGNREGISTER_CARRY_FLAG__);

    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// CMC指令操作方法
// 返回执行状态标志
// 
byte __VAR__ CMC
(
    struct instructionpackage __PTR__ instruct, 
    CPU __PTR__ cpu, 
    bool __PTR__ excuter_flag
)
{
    if (cpu->FLAGREG & __TYVM_SIGNREGISTER_CARRY_FLAG__)
        cpu->FLAGREG &= (~__TYVM_SIGNREGISTER_CARRY_FLAG__);
    else
        cpu->FLAGREG |= __TYVM_SIGNREGISTER_CARRY_FLAG__;

    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// PUSHF指令操作方法
// 返回执行状态标志
// 
byte __VAR__ PUSHF
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->GREG[__TYVM_REGISTER_RSP__] += 8;		            // 入栈指针上移
    if (cpu->StackTop >= cpu->GREG[__TYVM_REGISTER_RSP__])
        Uint64ToBytes
        (
            cpu->FLAGREG,
            (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 8),	// 转换栈指针
            8
        );
    else
    {
        cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__, cpu->GREG[__TYVM_REGISTER_RSP__]);
        (__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
        return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
    }

    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// POPF指令操作方法
// 返回执行状态标志
// 
byte __VAR__ POPF
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->GREG[__TYVM_REGISTER_RSP__] -= 8;		// 出栈指针下移
    if (cpu->StackBottom <= cpu->GREG[__TYVM_REGISTER_RSP__])
        cpu->FLAGREG = BytesToUint64
        (
        (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__]),	// 转换栈指针
            8
        );
    else
    {
        cpu->System->SysException
        (
            cpu->System,
            __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__, 
            cpu->GREG[__TYVM_REGISTER_RSP__]
        );
        (__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
        return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
    }

    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// PUSHA指令操作方法
// 返回执行状态标志
// 
byte __VAR__ PUSHA
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->GREG[__TYVM_REGISTER_RSP__] += 64;
    if (cpu->StackTop >= cpu->GREG[__TYVM_REGISTER_RSP__])
    {
        Uint64ToBytes(cpu->GREG[__TYVM_REGISTER_RAX__], (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 64), 8);
        Uint64ToBytes(cpu->GREG[__TYVM_REGISTER_RBX__], (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 56), 8);
        Uint64ToBytes(cpu->GREG[__TYVM_REGISTER_RDX__], (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 48), 8);
        Uint64ToBytes(cpu->GREG[__TYVM_REGISTER_RCX__], (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 40), 8);
        Uint64ToBytes(cpu->GREG[__TYVM_REGISTER_RSP__], (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 32), 8);
        Uint64ToBytes(cpu->GREG[__TYVM_REGISTER_RBP__], (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 24), 8);
        Uint64ToBytes(cpu->GREG[__TYVM_REGISTER_RSI__], (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 16), 8);
        Uint64ToBytes(cpu->GREG[__TYVM_REGISTER_RDI__], (byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] - 8), 8);
    }
    else
    {
        cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__, cpu->GREG[__TYVM_REGISTER_RSP__]);
        (__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
        return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
    }

    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// POPA指令操作方法
// 返回执行状态标志
// 
byte __VAR__ POPA
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->GREG[__TYVM_REGISTER_RSP__] -= 64;
    if (cpu->StackBottom <= cpu->GREG[__TYVM_REGISTER_RSP__])
    {
        cpu->GREG[__TYVM_REGISTER_RDI__] = BytesToUint64((byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] + 56), 8);
        cpu->GREG[__TYVM_REGISTER_RSI__] = BytesToUint64((byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] + 48), 8);
        cpu->GREG[__TYVM_REGISTER_RBP__] = BytesToUint64((byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] + 40), 8);
        cpu->GREG[__TYVM_REGISTER_RSP__] = BytesToUint64((byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] + 32), 8);
        cpu->GREG[__TYVM_REGISTER_RCX__] = BytesToUint64((byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] + 24), 8);
        cpu->GREG[__TYVM_REGISTER_RDX__] = BytesToUint64((byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] + 16), 8);
        cpu->GREG[__TYVM_REGISTER_RBX__] = BytesToUint64((byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] + 8), 8);
        cpu->GREG[__TYVM_REGISTER_RAX__] = BytesToUint64((byte __PTR__)(cpu->GREG[__TYVM_REGISTER_RSP__] + 0), 8);
    }
    else
    {
        cpu->System->SysException(cpu->System, __TYVM_RUNNING_EXCEPTION_OVERFLOW_STACK__, cpu->GREG[__TYVM_REGISTER_RSP__]);
        (__P_To_V__ excuter_flag) = __TYVM_CPU_STOP__;
        return __INSTRUCTION_PACKAGE_RUN_RESULT_ERROR__;
    }

    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// LAF指令操作方法
// 返回执行状态标志
// 
byte __VAR__ LAF
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->GREG[__TYVM_REGISTER_RAX__] = cpu->FLAGREG;
    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// SAF指令操作方法
// 返回执行状态标志
// 
byte __VAR__ SAF
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->FLAGREG = cpu->GREG[__TYVM_REGISTER_RAX__];
    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// LAIP指令操作方法
// 返回执行状态标志
// 
byte __VAR__ LAIP
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->GREG[__TYVM_REGISTER_RAX__] = cpu->IP;
    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}

//
// SAIP指令操作方法
// 返回执行状态标志
// 
byte __VAR__ SAIP
(
    struct instructionpackage   __PTR__ instruct,       // 指令包
    CPU                         __PTR__ cpu,            // 用于执行指令的CPU对象
    bool                        __PTR__ excuter_flag    // 执行状态标志
)
{
    cpu->IP = cpu->GREG[__TYVM_REGISTER_RAX__];
    return __INSTRUCTION_PACKAGE_RUN_RESULT_NORMAL__;
}