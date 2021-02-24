#include<tianyuvm/collections.h>

#ifdef __cplusplus
__C__
{
#endif

void   __VAR__ Uint64ToBytes
(
    uint64 __VAR__ data,
    byte   __PTR__ buffer,
    int32  __VAR__ count
)
{
    for (int i = 0; i < count; ++i)
    {
        buffer[i] = data & __Unsigned_Int8_Max__;
        data >>= 8;
    }
}
uint64 __VAR__ BytesToUint64
(
    byte   __PTR__ buffer,
    int32  __VAR__ count
)
{
    uint64 result = 0;
    for (int i = count -1; i >= 0; --i)
    {
        result <<= 8;
        result |= buffer[i];
    }
    return result;
}

#ifdef __cplusplus
}
#endif