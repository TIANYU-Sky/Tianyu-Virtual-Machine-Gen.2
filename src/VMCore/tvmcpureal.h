#pragma once
#ifndef __TIANYUVM_CORE_CPU__
#define __TIANYUVM_CORE_CPU__

#include<tianyuvm/tvmcpu.h>
#include<tianyuvm/collections.h>
#include<tianyuvm/tvminstruct.h>
#include<math.h>
#include<pthread.h>

typedef struct tvmcpu
{
	CPU			__VAR__ Base;

	pthread_t	__VAR__ Thread;
}TVMCPU;

#endif // !__TIANYUVM_CORE_CPU__