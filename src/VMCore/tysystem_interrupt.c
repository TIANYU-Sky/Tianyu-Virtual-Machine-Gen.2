#include<tianyuvm/tvmsystem.h>
#include<tianyuvm/tvmsysinterrupt.h>
#include"tvmsysreal.h"
#include<stdio.h>

uint64	__VAR__ Interrupt_ApplyMemory
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ size
);
void	__VAR__ Interrupt_DestroyMemory
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ mem
);
uint64	__VAR__ Interrupt_SizeMemory
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ mem
);

extern void		__VAR__ Interrupt_CreateThread
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ mem
);
extern uint64	__VAR__ Interrupt_LoadLibrary
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ lib_path
);
extern void 	__VAR__ Interrupt_UnloadLibrary
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ lib
);
extern uint64	__VAR__ Interrupt_LoadFunc
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ lib
);

void	__VAR__ Interrupt_PutChar
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ ch
);
void	__VAR__ Interrupt_PutString
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ mem
);
uint64	__VAR__ Interrupt_GetChar
(
	TVMSystem	__PTR__ sys
);
uint64	__VAR__ Interrupt_GetString
(
	TVMSystem	__PTR__	sys,
	uint64		__VAR__ addr
);

void __VAR__ TYSystem_Interrupt
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ icode,
	uint64		__VAR__ parms,
	uint64		__PTR__ result
)
{
	switch (icode)
	{
	case __TIANYUVM_SYSTEM_INT_MEMORY_APPLY__:
		(__P_To_V__ result) = Interrupt_ApplyMemory(sys, parms);
		break;
	case __TIANYUVM_SYSTEM_INT_MEMORY_DESTR__:
		Interrupt_DestroyMemory(sys, parms);
		break;
	case __TIANYUVM_SYSTEM_INT_MEMORY_SIZE__:
		(__P_To_V__ result) = Interrupt_SizeMemory(sys, parms);
		break;

	case __TIANYUVM_SYSTEM_INT_THREAD_CREATE__:
		Interrupt_CreateThread(sys, parms);
		break;
	case __TIANYUVM_SYSTEM_INT_THREAD_LOAD__:
		(__P_To_V__ result) = Interrupt_LoadLibrary(sys, parms);
		break;
	case __TIANYUVM_SYSTEM_INT_THREAD_UNLOAD__:
		Interrupt_UnloadLibrary(sys, parms);
		break;
	case __TIANYUVM_SYSTEM_INT_THREAD_LFUNC__:
		(__P_To_V__ result) = Interrupt_LoadFunc(sys, parms);
		break;

	case __TIANYUVM_SYSTEM_INT_CONSOLE_PUTCHAR__:

		break;
	case __TIANYUVM_SYSTEM_INT_CONSOLE_PUTSTR__:
		break;
	case __TIANYUVM_SYSTEM_INT_CONSOLE_GETCHAR__:
		break;
	case __TIANYUVM_SYSTEM_INT_CONSOLE_GETSTR__:
		break;

	default:
		(__P_To_V__ result) = 0;
		break;
	}
}


uint64	__VAR__ Interrupt_ApplyMemory
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ size
)
{
	TYSystem __PTR__ tysys = (TYSystem __PTR__)sys;

	return tysys->_Memory->Apply(tysys->_Memory, (int32)size);
}
void	__VAR__ Interrupt_DestroyMemory
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ mem
)
{
	TYSystem __PTR__ tysys = (TYSystem __PTR__)sys;

	tysys->_Memory->Destroy(tysys->_Memory, mem);
}
uint64	__VAR__ Interrupt_SizeMemory
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ mem
)
{
	return 0;
}

void	__VAR__ Interrupt_PutChar
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ ch
)
{
	char nch = (char)(ch & 0xFF);
	
	printf_s("%c", nch);
}
void	__VAR__ Interrupt_PutString
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ mem
)
{
	char __PTR__ str = (char __PTR__)mem;

	printf_s("%s", str);
}
uint64	__VAR__ Interrupt_GetChar
(
	TVMSystem	__PTR__ sys
)
{
	char ch = getchar();

	return ch;
}
uint64	__VAR__ Interrupt_GetString
(
	TVMSystem	__PTR__	sys,
	uint64		__VAR__ addr
)
{
	char	__VAR__ buffer[2048] = { '\0' };
	int32	__VAR__ length = 0;

	char __VAR__ ch = '\n';
	do
	{
		ch = getchar();
		buffer[length++] = ch;
		if (2048 <= length)
			break;
	} while ('\n' != ch);

	if ('\n' == ch)
	{
		--length;
		buffer[length] = '\0';
	}
	else if (2048 == length)
		buffer[length - 1] = '\0';
	else
		buffer[length++] = '\0';

	char	__PTR__ str = (char __PTR__)addr;

	if (0 == length)
		str[0] = '\0';
	else
		for (int i = 0; i < length; ++i)
			str[i] = buffer[i];

	return length;
}