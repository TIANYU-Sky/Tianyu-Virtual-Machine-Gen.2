#pragma once
#ifndef __TIANYUVM_CORE_SYSTEM__
#define __TIANYUVM_CORE_SYSTEM__

#include<tianyuvm/tvmsystem.h>
#include<pthread.h>

typedef struct tysystem
{
	TVMSystem	__VAR__ Base;

	Memory			__PTR__ _Memory;
	IOController	__PTR__ _IOController;
	pthread_mutex_t __VAR__ _Mutex;
}TYSystem;

#endif // !__TIANYUVM_CORE_SYSTEM__
