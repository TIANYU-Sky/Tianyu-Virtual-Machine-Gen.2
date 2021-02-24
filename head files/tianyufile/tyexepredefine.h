#pragma once

#ifndef __TIANYUFILE_TYEXEPREDEFINE_H__
#define __TIANYUFILE_TYEXEPREDEFINE_H__

#include"../define.h"

#ifdef __cplusplus
__C__
{
#endif

#define TianyuFile_TYM  0x01    // 天宇文件格式 目标文件
#define TianyuFile_TYL  0x02    // 天宇文件格式 链接文件
#define TianyuFile_TYY  0x03    // 天宇文件格式 应用程序
#define TianyuFile_TYK  0x04    // 天宇文件格式 静态链接库
#define TianyuFile_TYD  0x05    // 天宇文件格式 动态链接库

#define TianyuFile_TYI  0x10    // 天宇文件格式 TYI文本文件
#define TianyuFile_TYJ  0x11    // 天宇文件格式 TYJ文本文件
#define TianyuFile_TYX  0x12    // 天宇文件格式 TYX文本文件
#define TianyuFile_TY_  0x13    // 天宇文件格式 TY文件
#define TianyuFile_TYH  0x14    // 天宇文件格式 TYH文本文件（多格式文件）
#define TianyuFile_TYT  0x15    // 天宇文件格式 TYT文本文件（xml兼容文件）
#define TianyuFile_LOG  0x16    // 天宇文件格式 TLOG日志文件

#define TianyuFile_NON  0xFF    // 天宇文件格式 非天宇文件格式

// 天宇文件头魔数（ZTTQTXZY）
#define __TianyuFileHead_MagicNumber_Pre__ {'Z','T','T','Q','T','X','Z','Y'}

#define __TianyuProgramHead_RunTime_PHY__       0x01        // 天宇程序头部 运行环境 物理机
#define __TianyuProgramHead_RunTime_VIR__       0x02        // 天宇程序头部 运行环境 虚拟机

#define __TianyuProgramHead_SystemVersion__     0x10        // 天宇程序头部 系统版本 1.0

#define __TianyuProgramHead_ProgramVersion__    0x10        // 天宇程序头部 程序版本 1.0

#define __TianyuProgramHead_ProgramGroup_x86__  0x01        // 天宇程序头部 程序族 32位程序
#define __TianyuProgramHead_ProgramGroup_x64__  0x02        // 天宇程序头部 程序族 64位程序

#define __TianyuProgramHead_ProcessGroup_TVM__   0x01       // 天宇程序头部 处理机族 天宇虚拟机
#define __TianyuProgramHead_ProcessGroup_ARM__   0x02       // 天宇程序头部 处理机族 ARM处理机
#define __TianyuProgramHead_ProcessGroup_x86__   0x04       // 天宇程序头部 处理机族 X86处理机
#define __TianyuProgramHead_ProcessGroup_BCM__   0x08       // 天宇程序头部 处理机族 字节码虚拟机

#define __TianyuProgramHead_EncodeGroup_Little__    0x00    // 天宇程序头部 编码方式 小端 
#define __TianyuProgramHead_EncodeGroup_Large__     0x08    // 天宇程序头部 编码方式 大端

#define __TianyuProgramHead_FileLabel_TYM__   0x01          // 天宇程序头部 文件类型 目标文件
#define __TianyuProgramHead_FileLabel_TYL__   0x02          // 天宇程序头部 文件类型 链接文件
#define __TianyuProgramHead_FileLabel_TYY__   0x04          // 天宇程序头部 文件类型 应用程序
#define __TianyuProgramHead_FileLabel_TYJ__   0x08          // 天宇程序头部 文件类型 静态链接库
#define __TianyuProgramHead_FileLabel_TYD__   0x10          // 天宇程序头部 文件类型 动态链接库

#define __TianyuSignTableGroup_SignType_VAR__   0x01        // 天宇符号表 变量
#define __TianyuSignTableGroup_SignType_LAB__   0x02        // 天宇符号表 标签
#define __TianyuSignTableGroup_SignType_PRO__   0x04        // 天宇符号表 过程/方法
#define __TianyuSignTableGroup_SignType_EXT__   0x08        // 天宇符号表 拓展
#define __TianyuSignTableGroup_SignType_DEF__   0x08        // 天宇符号表 类型定义

#define __TianyuRelocateTableGroup_LocateLength_8__     0x03        // 天宇重定位表 重定位长度-8位
#define __TianyuRelocateTableGroup_LocateLength_16__    0x02        // 天宇重定位表 重定位长度-16位
#define __TianyuRelocateTableGroup_LocateLength_32__    0x01        // 天宇重定位表 重定位长度-32位
#define __TianyuRelocateTableGroup_LocateLength_64__    0x00        // 天宇重定位表 重定位长度-64位

#define __TianyuRelocateTableGroup_State_REL__   0x01        // 天宇重定位表 相对寻址（链接时重定位）
#define __TianyuRelocateTableGroup_State_ABS__   0x04        // 天宇重定位表 标签（装载时重定位）

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUFILE_TYEXEPREDEFINE_H__