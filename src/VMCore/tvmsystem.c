#include"tvmsysreal.h"

uint64 __VAR__ TYSystem_Device_Access_In
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ device_code
)
{
	if (null != sys)
	{
		TYSystem __PTR__ tysystem = (TYSystem __PTR__)sys;
		IODevice __PTR__ device = tysystem->_IOController->GetDevice
		(
			tysystem->_IOController,
			device_code
		);
		if (null != device)
			return device->In(device);
	}
	return -1;
}
void __VAR__ TYSystem_Device_Access_Out
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ device_code,
	uint64		__VAR__ data
)
{
	if (null != sys)
	{
		TYSystem __PTR__ tysystem = (TYSystem __PTR__)sys;
		IODevice __PTR__ device = tysystem->_IOController->GetDevice
		(
			tysystem->_IOController,
			device_code
		);
		if (null != device)
			device->Out(device, data);
	}
}

extern void __VAR__ TYSystem_Interrupt
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ icode,
	uint64		__VAR__ parms,
	uint64		__PTR__ result
);

extern void __VAR__ TYSystem_RunningException
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ ecode,
	uint64		__VAR__ memory
);

void __VAR__ TYSystem_Memory_Lock
(
	TVMSystem	__PTR__ sys
)
{
	if (null != sys)
	{
		TYSystem __PTR__ tysys = (TYSystem __PTR__)sys;
		if (null != tysys->_Mutex)
			pthread_mutex_lock(__V_To_P__ tysys->_Mutex);
	}
}

void __VAR__ TYSystem_Memory_UnLock
(
	TVMSystem	__PTR__ sys
)
{
	if (null != sys)
	{
		TYSystem __PTR__ tysys = (TYSystem __PTR__)sys;
		if (null != tysys->_Mutex)
			pthread_mutex_unlock(__V_To_P__ tysys->_Mutex);
	}
}


TVMSystem __PTR__ CreateTVMSystem
(
	Memory          __PTR__ memory,
	IOController    __PTR__ controller
)
{
	if (null != memory && null != controller)
	{
		TYSystem __PTR__ tysys = (TYSystem __PTR__)malloc(sizeof(TYSystem));
		if (null != tysys)
		{
			tysys->_IOController = controller;
			tysys->_Memory = memory;
			pthread_mutex_init(__V_To_P__ tysys->_Mutex, null);

			tysys->Base.DeviceIn = TYSystem_Device_Access_In;
			tysys->Base.DeviceOut = TYSystem_Device_Access_Out;
			tysys->Base.Lock = TYSystem_Memory_Lock;
			tysys->Base.UnLock = TYSystem_Memory_UnLock;
			tysys->Base.SysInterrupt = TYSystem_Interrupt;
			tysys->Base.SysException = TYSystem_RunningException;

			return (TVMSystem __PTR__)tysys;
		}
		return null;
	}
	return null;
}
void      __VAR__ DestroyTVMSystem
(
	TVMSystem __PTR__ sys
)
{
	if (null != sys)
	{
		TYSystem __PTR__ tysys = (TYSystem __PTR__)sys;
		DestroyMemoryObject(tysys->_Memory);
		DestroyIOController(tysys->_IOController);
		pthread_mutex_destroy(__V_To_P__ tysys->_Mutex);
		free(tysys);
	}
}