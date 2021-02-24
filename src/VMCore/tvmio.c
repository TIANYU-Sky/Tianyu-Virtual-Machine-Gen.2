#include<tianyuvm/tvmio.h>

typedef struct tyiocontroller
{
    IOController    __VAR__ Base;

    DeviceList      __PTR__ Devices;
}TYIOController;

IODevice __PTR__ IOController_GetIODevice
(
    IOController    __PTR__ controller,
    uint64          __VAR__ device_code
)
{
    if (null != controller)
        return ((TYIOController __PTR__)controller)->Devices->GetDevice
        (
            ((TYIOController __PTR__)controller)->Devices,
            device_code
        );
    return null;
}
bool __VAR__ IOController_AddIODevice
(
    IOController    __PTR__ controller,
    uint64          __VAR__ device_code,
    IODevice        __PTR__ device
)
{
    if (null != controller)
        return ((TYIOController __PTR__)controller)->Devices->AddDevice
        (
            ((TYIOController __PTR__)controller)->Devices,
            device_code,
            device
        );
    return __DEVICE_ADD_RESULT_FAILED__;
}
bool __VAR__ IOController_RemoveIODevice
(
    IOController    __PTR__ controller,
    uint64          __VAR__ device_code
)
{
    if (null != controller)
        return ((TYIOController __PTR__)controller)->Devices->RemoveDevice
        (
            ((TYIOController __PTR__)controller)->Devices,
            device_code
        );
    return __DEVICE_REMOVE_RESULT_FAILED__;
}
uint64 __VAR__ IOController_DevicesCount
(
    IOController    __PTR__ controller
)
{
    if (null != controller)
        return ((TYIOController __PTR__)controller)->Devices->Count
        (
            ((TYIOController __PTR__)controller)->Devices
        );
    return 0;
}



IOController __PTR__ CreateIOController()
{
    TYIOController __PTR__ controller = (TYIOController __PTR__)malloc(sizeof(TYIOController));
    if (null != controller)
    {
        controller->Base.AddDevice = IOController_AddIODevice;
        controller->Base.GetDevice = IOController_GetIODevice;
        controller->Base.RemoveDevice = IOController_RemoveIODevice;
        controller->Base.Count = IOController_DevicesCount;

        controller->Devices = CreateDeviceList();
        if (null == controller->Devices)
        {
            free(controller);
            return null;
        }
        return (IOController __PTR__)controller;
    }
    return null;
}
void         __VAR__ DestroyIOController
(
    IOController __PTR__ controller
)
{
    if (null != controller)
    {
        DestroyDeviceList(((TYIOController __PTR__)controller)->Devices);
        free((TYIOController __PTR__)controller);
    }
}