#include<tianyuvm/tvmmemory.h>
#include<tianyuvm/collections.h>
#include<stdlib.h>

uint64 __VAR__ MemoryDeviceFun_Apply
(
	Memory __PTR__ mem_dev,
	int32  __VAR__ size
)
{
	return (uint64)((byte __PTR__)malloc(sizeof(byte) * Align_8(size)));
}
void   __VAR__ MemoryDeviceFun_Destroy
(
	Memory __PTR__ mem_dev,
	uint64 __VAR__ addr
)
{
	free((byte __PTR__)addr);
}

Memory __PTR__ CreateMemoryObject
(
	string __VAR__ init_data,
	int32  __VAR__ length
)
{
	Memory __PTR__ memory = (Memory __PTR__)malloc(sizeof(Memory));
	if (null != memory)
	{
		memory->Apply = MemoryDeviceFun_Apply;
		memory->Destroy = MemoryDeviceFun_Destroy;
		return memory;
	}
	return null;
}
void   __VAR__ DestroyMemoryObject
(
	Memory __PTR__ memory
)
{
	free(memory);
}