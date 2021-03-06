/**
 * 用于天宇虚拟机系统的中断描述符
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMSYSINTERRUPT__
#define __TIANYUVM_C_CPP_TVMSYSINTERRUPT__

#define __TIANYUVM_SYSTEM_INT_MEMORY_APPLY__    0x10
#define __TIANYUVM_SYSTEM_INT_MEMORY_DESTR__    0x11
#define __TIANYUVM_SYSTEM_INT_MEMORY_SIZE__     0x12

#define __TIANYUVM_SYSTEM_INT_THREAD_CREATE__   0x20
#define __TIANYUVM_SYSTEM_INT_THREAD_LOAD__     0x21
#define __TIANYUVM_SYSTEM_INT_THREAD_UNLOAD__   0x22
#define __TIANYUVM_SYSTEM_INT_THREAD_LFUNC__    0x23

#define __TIANYUVM_SYSTEM_INT_CONSOLE_PUTCHAR__ 0x30
#define __TIANYUVM_SYSTEM_INT_CONSOLE_PUTSTR__  0x31
#define __TIANYUVM_SYSTEM_INT_CONSOLE_GETCHAR__ 0x32
#define __TIANYUVM_SYSTEM_INT_CONSOLE_GETSTR__  0x33

#endif // !__TIANYUVM_C_CPP_TVMSYSINTERRUPT__