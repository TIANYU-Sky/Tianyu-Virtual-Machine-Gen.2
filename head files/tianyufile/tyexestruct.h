#pragma once

#ifndef __TIANYUFILE_TYEXESTRUCT_H__
#define __TIANYUFILE_TYEXESTRUCT_H__

#include"../define.h"
#include"../basedatatype.h"

#define __TianyuFileHead_Struct_Length__        64
#define __TianyuProgramHead_Struct_Length__     36
#define __TianyuHead_Struct_Length__            100

#define __TianyuAdditionHead_Struct_Length__    16

#define __TianyuTableItem_Struct_Length__       33
#define __TianyuRelocationItem_Struct_Length__  19

#ifdef __cplusplus
__C__
{
#endif

typedef struct tianyufilehead
{

    byte    __VAR__ MagicNumber[8];     // 0-天宇文件头部 魔数（用于指定当前文件格式：ZTYZATY）
    uint64  __VAR__ FileLength;         // 8-天宇文件头部 指示当前文件的整体长度
    uint32  __VAR__ HeadLength;         // 16-天宇文件头部 指示当前天宇头部的长度
    uint32  __VAR__ ProgramHeadOffset;  // 20-天宇文件头部 指示当前程序头部的偏移量

    uint64  __VAR__ StringTableOffset;  // 24-天宇附加头部 字符串表偏移量
    uint64  __VAR__ ExportTableOffset;  // 32-天宇附加头部 导出符号表偏移量

    uint64  __VAR__ StringTableSize;    // 40-天宇附加头部 字符串表大小
    uint64  __VAR__ StringTableCount;   // 48-天宇附加头部 字符串表项数
    uint64  __VAR__ ExportTableCount;   // 56-天宇附加头部 导出符号表项数

}TianyuFileHead;

typedef struct tianyuprogramhead
{
    byte    __VAR__ RunTime;            // 0-天宇程序头部 程序运行时
    byte    __VAR__ SystemVersion;      // 1-天宇程序头部 系统版本
    byte    __VAR__ ProgramVersion;     // 2-天宇程序头部 程序版本
    byte    __VAR__ AdditionProp;       // 3-天宇程序头部 附加属性（没有控制意义）
    byte    __VAR__ ProgramGroup;       // 4-天宇程序头部 程序类型（32/64）
    byte    __VAR__ ProcessGroup;       // 5-天宇程序头部 处理机类型
    byte    __VAR__ EncodeGroup;        // 6-天宇程序头部 编码方式
    byte    __VAR__ FileLabel;          // 7-天宇程序头部 文件类别/标识
    uint64  __VAR__ CSPosition;         // 8-天宇程序头部 代码段定位
    uint64  __VAR__ DSPosition;         // 16-天宇程序头部 数据段定位（DS值）
    uint64  __VAR__ ProgramEntry;       // 24-天宇程序头部 程序入口（文件为可执行文件时有效）
    uint32  __VAR__ StackSize;          // 32-天宇程序头部 程序运行堆栈大小
}TianyuProgramHead;

typedef struct tianyuhead
{
    TianyuFileHead      __VAR__ TYHead;
    TianyuProgramHead   __VAR__ ProgramHead;
}TianyuHead;


typedef struct tianyuadditionhead
{
    uint64  __VAR__ RelocationTableOffset;  // 天宇附加头部 重定义表偏移量

    uint64  __VAR__ RelocationTableCount;   // 天宇附加头部 重定义表项数
}TianyuAdditionHead;

typedef struct tystringtable
{
    char    __PTR__ RawString;      // 天宇文件 字符串表 字符串源
    uint64  __VAR__ StringLength;   // 天宇文件 字符串表 字符串源长度
}TYStringTable;

typedef struct tytableitem
{
    byte    __VAR__ Type;           // 0-天宇文件符号表项 符号类型
    uint64  __VAR__ ItemIndex;      // 1-天宇文件符号表项 符号标号
    uint64  __VAR__ StringIndex;    // 9-天宇文件符号表项 符号字符串定位标号
    uint64  __VAR__ ItemLocation;   // 17-天宇文件符号表项 符号项代码段定位
    uint64  __VAR__ ItemLength;     // 25-天宇文件符号表项 符号项代码段长度
}TYTableItem;

typedef struct tyreloactionitem
{
    byte    __VAR__ Type;           // 0-天宇重定义表项 符号类型
    byte    __VAR__ State;          // 1-天宇重定义表项 重定位方式
    byte    __VAR__ LocateLength;   // 2-天宇重定义表项 重定位长度（8/16/32/64）
    uint64  __VAR__ Offset;         // 3-天宇重定义表项 本节的重定位位置
    uint64  __VAR__ StringIndex;    // 11-天宇重定义表项 符号名字符串标号
}TYRelocationItem;

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUFILE_TYEXESTRUCT_H__