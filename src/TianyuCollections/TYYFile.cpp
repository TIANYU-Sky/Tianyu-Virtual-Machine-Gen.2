#include<tianyufile/tyfile.h>
#include<tianyufile/tyexepredefine.h>
#include<iostream>
#include<tools.h>

const char __VAR__ TYYFilePackage::TianyuMagicNumber[8] = __TianyuFileHead_MagicNumber_Pre__;

TYYFilePackage::TYYFilePackage
(
	__IN_Param__ CStructString __PTR__ path
	)
    :_FileState(__TYEXEFILE_STATE_OK__),
    _StringTable(null),
    _TYFileHead(),
    _StringLength(0),
    _Signs(null),
    _SignsCount(0),
    _FileStream()
{
    if (null == path || path->IsNull(path))
    {
        _FileState = __TYEXEFILE_STATE_FERR__;
        return;
    }

    try
    {
        _FileStream.open(path->String(path), std::ios::in | std::ios::binary);
    }
    catch (std::exception)
    {
        _FileState = __TYEXEFILE_STATE_FERR__;
    }

    if (!LoadFile())
    {
        _FileStream.close();
        _FileState = __TYEXEFILE_STATE_SERR__;
    }
}
TYYFilePackage::~TYYFilePackage()
{
    delete(_StringTable);
    delete(_Signs);
    if (_FileStream.is_open())
        _FileStream.close();
}

byte        __VAR__ TYYFilePackage::GetFileState()
{
    return _FileState;
}

bool        __VAR__ TYYFilePackage::IsStringsNull()
{
    return null == _StringTable;
}
char        __PTR__ TYYFilePackage::GetStringTable()
{
    return _StringTable;
}
uint64      __VAR__ TYYFilePackage::GetStringLength()
{
    return _StringLength;
}

TianyuHead  __REF__ TYYFilePackage::GetFileHead()
{
    return _TYFileHead;
}

bool        __VAR__ TYYFilePackage::IsSignNull()
{
    return null == _Signs;
}
TYTableItem __REF__ TYYFilePackage::GetSignItem
(
    uint64 __VAR__ index
    )
{
    return _Signs[index];
}
TYTableItem __PTR__ TYYFilePackage::GetSignItems()
{
    return _Signs;
}
uint64      __VAR__ TYYFilePackage::GetSignsCount()
{
    return _SignsCount;
}

bool        __VAR__ LoadFile_ReadHead
(
    __IN_Param__ std::ifstream  __REF__ stream,
    __IO_Param__ TianyuHead     __REF__ head
    );
bool        __VAR__ LoadFile_ReadString
(
    __IN_Param__ std::ifstream  __REF__ stream,
    __IN_Param__ uint64         __VAR__ position,
    __IN_Param__ uint64         __VAR__ count,
    __IO_Param__ char           __PAR__ strings
    );
bool        __VAR__ LoadFile_ReadSigns
(
    __IN_Param__ std::ifstream  __REF__ stream,
    __IN_Param__ uint64         __VAR__ position,
    __IN_Param__ uint64         __VAR__ count,
    __IO_Param__ TYTableItem    __PAR__ items
);
bool        __VAR__ TYYFilePackage::LoadFile()
{
    if (!_FileStream.is_open())
        return false;

    if (
        !LoadFile_ReadHead
        (
            _FileStream,
            _TYFileHead
            )
        )
        return false;

    if (
        !LoadFile_ReadString
        (
            _FileStream,
            _TYFileHead.TYHead.StringTableOffset,
            _TYFileHead.TYHead.StringTableSize,
            _StringTable
            )
        )
        return false;

    if (
        !LoadFile_ReadSigns
        (
            _FileStream,
            _TYFileHead.TYHead.ExportTableOffset,
            _TYFileHead.TYHead.ExportTableCount,
            _Signs
            )
        )
        return false;

    return true;
}

uint64      __VAR__ TYYFilePackage::ReadFile
(
    __OT_Param__ char               __PAR__ buffer,
    __OT_Param__ TYRelocationItem   __PAR__ relocations,
    __OT_Param__ uint64             __REF__ rel_count,
    __IN_Param__ uint64             __VAR__ sign_index
)
{
    TYTableItem __REF__ item = _Signs[sign_index];

    _FileStream.clear();
    _FileStream.seekg(item.ItemLocation);

    char __PTR__ temp = new char[8];
    if (8 != _FileStream.readsome(temp, 8))
    {
        delete[] temp;
        return 0;
    }

    rel_count = BytesToUint64((byte __PTR__)temp, 8);
    delete[] temp;

    buffer = new char[item.ItemLength];
    if (_FileStream.readsome(buffer, item.ItemLength) != item.ItemLength)
    {
        delete[] buffer;
        return 0;
    }

    if (0 < rel_count)
    {
        relocations = new TYRelocationItem[rel_count];

        uint64 __VAR__ rel_length = rel_count * __TianyuRelocationItem_Struct_Length__;
        temp = new char[rel_length];
        if (rel_length != _FileStream.readsome(temp, rel_length))
        {
            delete[] temp;
            delete[] relocations;
            delete[] buffer;
            return 0;
        }

        for (uint64 i = 0; i < rel_count; ++i)
        {
            uint64 __VAR__ offset = i * __TianyuRelocationItem_Struct_Length__;

            relocations[i].Type         = temp[offset + 0];
            relocations[i].State        = temp[offset + 1];
            relocations[i].LocateLength = temp[offset + 2];

            relocations[i].Offset       = BytesToUint64((byte __PTR__)temp + offset + 3 , 8);
            relocations[i].StringIndex  = BytesToUint64((byte __PTR__)temp + offset + 11, 8);
        }
        delete[] temp;
    }

    return item.ItemLength;
}
byte        __PTR__ TYYFilePackage::ReadFile()
{
    _FileStream.clear();
    _FileStream.seekg(0, std::ios::end);
    uint64 length = _FileStream.tellg();
    byte __PTR__ buffer = new byte[length];

    _FileStream.clear();
    _FileStream.seekg(0);

    _FileStream.read((char __PTR__)buffer, length);
    return buffer;
}


#pragma region 外部定义操作方法

bool        __VAR__ LoadFile_CheckMagic
(
    __IN_Param__ char           __PTR__ str
    )
{
    if (null == str)
        return false;

    if (TYYFilePackage::TianyuMagicNumber[0] != str[0])
        return false;
    if (TYYFilePackage::TianyuMagicNumber[1] != str[1])
        return false;
    if (TYYFilePackage::TianyuMagicNumber[2] != str[2])
        return false;
    if (TYYFilePackage::TianyuMagicNumber[3] != str[3])
        return false;
    if (TYYFilePackage::TianyuMagicNumber[4] != str[4])
        return false;
    if (TYYFilePackage::TianyuMagicNumber[5] != str[5])
        return false;
    if (TYYFilePackage::TianyuMagicNumber[6] != str[6])
        return false;
    if (TYYFilePackage::TianyuMagicNumber[7] != str[7])
        return false;

    return true;
}

bool        __VAR__ LoadFile_ReadHead
(
    __IN_Param__ std::ifstream  __REF__ stream,
    __IO_Param__ TianyuHead     __REF__ head
    )
{
    if (!stream.is_open())
        return false;

    stream.clear();
    stream.seekg(0);

    char __PTR__ buffer = new char[__TianyuHead_Struct_Length__];
    std::streamsize size = stream.readsome(buffer, (std::streamsize)__TianyuHead_Struct_Length__);
    if (__TianyuHead_Struct_Length__ != size)
        return false;

    if (!LoadFile_CheckMagic(buffer))
        return false;

    head.TYHead.MagicNumber[0] = buffer[0];
    head.TYHead.MagicNumber[1] = buffer[1];
    head.TYHead.MagicNumber[2] = buffer[2];
    head.TYHead.MagicNumber[3] = buffer[3];
    head.TYHead.MagicNumber[4] = buffer[4];
    head.TYHead.MagicNumber[5] = buffer[5];
    head.TYHead.MagicNumber[6] = buffer[6];
    head.TYHead.MagicNumber[7] = buffer[7];

    head.TYHead.FileLength =            BytesToUint64((byte __PTR__)buffer + 8,     8);
    head.TYHead.HeadLength = (uint32)   BytesToUint64((byte __PTR__)buffer + 16,    4);
    head.TYHead.HeadLength = (uint32)   BytesToUint64((byte __PTR__)buffer + 20,    4);
    head.TYHead.StringTableOffset =     BytesToUint64((byte __PTR__)buffer + 24,    8);  
    head.TYHead.ExportTableOffset =     BytesToUint64((byte __PTR__)buffer + 32,    8);
    head.TYHead.StringTableSize =       BytesToUint64((byte __PTR__)buffer + 40,    8);
    head.TYHead.StringTableCount =      BytesToUint64((byte __PTR__)buffer + 48,    8);
    head.TYHead.ExportTableCount =      BytesToUint64((byte __PTR__)buffer + 56,    8);

    head.ProgramHead.RunTime        = buffer[__TianyuFileHead_Struct_Length__ + 0];
    head.ProgramHead.SystemVersion  = buffer[__TianyuFileHead_Struct_Length__ + 1];
    head.ProgramHead.ProgramVersion = buffer[__TianyuFileHead_Struct_Length__ + 2];
    head.ProgramHead.AdditionProp   = buffer[__TianyuFileHead_Struct_Length__ + 3];
    head.ProgramHead.ProgramGroup   = buffer[__TianyuFileHead_Struct_Length__ + 4];
    head.ProgramHead.ProcessGroup   = buffer[__TianyuFileHead_Struct_Length__ + 5];
    head.ProgramHead.EncodeGroup    = buffer[__TianyuFileHead_Struct_Length__ + 6];
    head.ProgramHead.FileLabel      = buffer[__TianyuFileHead_Struct_Length__ + 7];

    head.ProgramHead.CSPosition = BytesToUint64
    (
    (byte __PTR__)buffer + __TianyuFileHead_Struct_Length__ + 8, 
        8
        );
    head.ProgramHead.DSPosition = BytesToUint64
    (
    (byte __PTR__)buffer + __TianyuFileHead_Struct_Length__ + 16, 
        8
        );
    head.ProgramHead.ProgramEntry = BytesToUint64
    (
    (byte __PTR__)buffer + __TianyuFileHead_Struct_Length__ + 24, 
        8
        );
    head.ProgramHead.StackSize = (uint32)BytesToUint64
    (
    (byte __PTR__)buffer + __TianyuFileHead_Struct_Length__ + 32, 
        4
        );

    return true;
}
bool        __VAR__ LoadFile_ReadString
(
    __IN_Param__ std::ifstream  __REF__ stream,
    __IN_Param__ uint64         __VAR__ position,
    __IN_Param__ uint64         __VAR__ count,
    __IO_Param__ char           __PAR__ strings
    )
{
    if (!stream.is_open())
        return false;

    if (0 == count)
        return true;

    stream.clear();
    stream.seekg(position);

    strings = new char[count];
    std::streamsize readsize = stream.readsome(strings, count);

    if (count != readsize)
        return false;

    return true;
}
bool        __VAR__ LoadFile_ReadSigns
(
    __IN_Param__ std::ifstream  __REF__ stream,
    __IN_Param__ uint64         __VAR__ position,
    __IN_Param__ uint64         __VAR__ count,
    __IO_Param__ TYTableItem    __PAR__ items
    )
{
    if (!stream.is_open())
        return false;

    if (0 == count)
        return true;

    stream.clear();
    stream.seekg(position);

    items = new TYTableItem[count];

    uint64 __VAR__ size = __TianyuTableItem_Struct_Length__ * count;
    char __PTR__ buffer = new char[size];

    if (stream.readsome(buffer, size) != size)
    {
        delete[] buffer;
        return false;
    }

    for (uint64 i = 0; i < count; ++i)
    {
        uint64 __VAR__ offset = i * __TianyuTableItem_Struct_Length__;
        items[i].Type           = buffer[offset + 0];
        items[i].ItemIndex      = BytesToUint64((byte __PTR__)buffer + offset + 1,  8);
        items[i].StringIndex    = BytesToUint64((byte __PTR__)buffer + offset + 9,  8);
        items[i].ItemLocation   = BytesToUint64((byte __PTR__)buffer + offset + 17, 8);
        items[i].ItemLength     = BytesToUint64((byte __PTR__)buffer + offset + 25, 8);
    }

    delete[] buffer;
    return true;
}

#pragma endregion
