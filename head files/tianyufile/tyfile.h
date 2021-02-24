#pragma once

#ifndef __TIANYUFILE_TYFILE_H__
#define __TIANYUFILE_TYFILE_H__

#ifdef __cplusplus
#include<fstream>
#else
#include<stdio.h>
#endif

#include"../define.h"
#include"../basedatatype.h"

#include"tyexestruct.h"

#define __TYEXEFILE_STATE_OK__      0x00
#define __TYEXEFILE_STATE_FERR__    0x01
#define __TYEXEFILE_STATE_SERR__    0x02

typedef struct tianyufileinformation
{
    byte          __VAR__ FileType;
    CStructString __PTR__ FullName;
    CStructString __PTR__ Extension;
    CStructString __PTR__ FileName;
    CStructString __PTR__ Directory;
    CStructString __PTR__ Root;
}TYFileInfo;

#ifdef __cplusplus
__C__
{
#endif

TYFileInfo   __VAR__ TYGetFileInfo
(
    CStructString __PTR__ file
    );

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
class TYYFilePackage
{
    _Public static const char   __VAR__ TianyuMagicNumber[8];

    _Private byte               __VAR__ _FileState;
    _Private char               __PTR__ _StringTable;
    _Private TianyuHead         __VAR__ _TYFileHead;
    _Private uint64             __VAR__ _StringLength;
    _Private TYTableItem        __PTR__ _Signs;
    _Private uint64             __VAR__ _SignsCount;
    _Private std::ifstream      __VAR__ _FileStream;

    _Public TYYFilePackage
    (
        __IN_Param__ CStructString __PTR__ path
    );
    _Public ~TYYFilePackage();

    _Public byte        __VAR__ GetFileState();

    _Public bool        __VAR__ IsStringsNull();
    _Public char        __PTR__ GetStringTable();
    _Public uint64      __VAR__ GetStringLength();

    _Public TianyuHead  __REF__ GetFileHead();

    _Public bool        __VAR__ IsSignNull();
    _Public TYTableItem __REF__ GetSignItem
    (
        uint64 __VAR__ index
    );
    _Public TYTableItem __PTR__ GetSignItems();
    _Public uint64      __VAR__ GetSignsCount();

    _Public uint64      __VAR__ ReadFile
    (
        __OT_Param__ char               __PAR__ buffer,
        __OT_Param__ TYRelocationItem   __PAR__ relocations,
        __OT_Param__ uint64             __REF__ rel_count,
        __IN_Param__ uint64             __VAR__ sign_index
    );
    _Public  byte       __PTR__ ReadFile();

    _Private bool       __VAR__ LoadFile();
};
#endif

#endif // !__TIANYUFILE_TYFILE_H__