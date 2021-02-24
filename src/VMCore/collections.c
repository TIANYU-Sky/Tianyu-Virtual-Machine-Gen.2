#include<tianyuvm/collections.h>
#include<tianyuvm/tvmio.h>

#define __DEVICE_LIST_HASH_VALUE__  32

typedef struct devicelistnode
{
    uint64                  __VAR__ DeviceCode;
    IODevice                __PTR__ Device;

    struct devicelistnode   __PTR__ Next;
}DeviceListNode;

typedef struct tydevicelist
{
    DeviceList      __VAR__ Base;

    uint64          __VAR__ Count;
    DeviceListNode  __VAR__ Devices[__DEVICE_LIST_HASH_VALUE__];
}TYDeviceList;

IODevice __PTR__ TYDeviceList_GetIODevice
(
    DeviceList  __PTR__ device_list,
    uint64      __VAR__ device_code
)
{
    if (null != device_list)
    {
        TYDeviceList    __PTR__ devices = (TYDeviceList __PTR__)device_list;
        DeviceListNode  __PTR__ temp = devices->Devices[Mod_32(device_code)].Next;
        while (null != temp)
        {
            if (temp->DeviceCode == device_code)
                return temp->Device;
            temp = temp->Next;
        }
    }
    return null;
}

bool __VAR__ TYDeviceList_AddIODevice
(
    DeviceList  __PTR__ device_list,
    uint64      __VAR__ device_code,
    IODevice    __PTR__ device
)
{
    if (null != device_list)
    {
        TYDeviceList    __PTR__ devices = (TYDeviceList __PTR__)device_list;
        DeviceListNode  __PTR__ newdevice = (DeviceListNode __PTR__)malloc(sizeof(DeviceListNode));

        if (null != newdevice)
        {
            newdevice->Device = device;
            newdevice->DeviceCode = device_code;

            DeviceListNode  __PTR__ temp = devices->Devices + Mod_32(device_code);
            while (null != temp->Next)
            {
                if (temp->Next->DeviceCode == device_code)
                {
                    free(newdevice);
                    return __DEVICE_ADD_RESULT_FAILED__;
                }
                else if (temp->Next->DeviceCode > device_code)
                    break;
                temp = temp->Next;
            }
            newdevice->Next = temp->Next;
            temp->Next = newdevice;
            ++(devices->Count);
            return __DEVICE_ADD_RESULT_SECCUSS__;
        }
    }
    return __DEVICE_ADD_RESULT_FAILED__;
}

bool __VAR__ TYDeviceList_RemoveIODevice
(
    DeviceList  __PTR__ device_list,
    uint64      __VAR__ device_code
)
{
    if (null != device_list)
    {
        TYDeviceList __PTR__ devices = (TYDeviceList __PTR__)device_list;

        DeviceListNode  __PTR__ temp = devices->Devices + Mod_32(device_code);
        while (null != temp->Next)
        {
            if (temp->Next->DeviceCode == device_code)
            {
                DeviceListNode __PTR__ del = temp->Next;
                temp->Next = del->Next;
                free(del);
                --(devices->Count);
                return __DEVICE_REMOVE_RESULT_SECCUSS__;
            }
            temp = temp->Next;
        }
    }
    return __DEVICE_REMOVE_RESULT_FAILED__;
}

uint64 __VAR__ TYDeviceList_DeviceCount
(
    struct devicelist   __PTR__ device_list
)
{
    if (null != device_list)
        return ((TYDeviceList __PTR__)device_list)->Count;
    return 0;
}

DeviceList __PTR__ CreateDeviceList()
{
    TYDeviceList __PTR__ devicelist = (TYDeviceList __PTR__)malloc(sizeof(TYDeviceList));
    if (null != devicelist)
    {
        devicelist->Base.AddDevice = TYDeviceList_AddIODevice;
        devicelist->Base.GetDevice = TYDeviceList_GetIODevice;
        devicelist->Base.RemoveDevice = TYDeviceList_RemoveIODevice;
        devicelist->Base.Count = TYDeviceList_DeviceCount;

        devicelist->Count = 0;

        for (int i = 0; i < __DEVICE_LIST_HASH_VALUE__; ++i)
            devicelist->Devices[i].Next = null;

        return (DeviceList __PTR__)devicelist;
    }
    return null;
}
void       __VAR__ DestroyDeviceList
(
    DeviceList __PTR__ device_list
)
{
    if (null != device_list)
        free((TYDeviceList __PTR__)device_list);
}