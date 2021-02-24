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

    byte    __VAR__ MagicNumber[8];     // 0-�����ļ�ͷ�� ħ��������ָ����ǰ�ļ���ʽ��ZTYZATY��
    uint64  __VAR__ FileLength;         // 8-�����ļ�ͷ�� ָʾ��ǰ�ļ������峤��
    uint32  __VAR__ HeadLength;         // 16-�����ļ�ͷ�� ָʾ��ǰ����ͷ���ĳ���
    uint32  __VAR__ ProgramHeadOffset;  // 20-�����ļ�ͷ�� ָʾ��ǰ����ͷ����ƫ����

    uint64  __VAR__ StringTableOffset;  // 24-�����ͷ�� �ַ�����ƫ����
    uint64  __VAR__ ExportTableOffset;  // 32-�����ͷ�� �������ű�ƫ����

    uint64  __VAR__ StringTableSize;    // 40-�����ͷ�� �ַ������С
    uint64  __VAR__ StringTableCount;   // 48-�����ͷ�� �ַ���������
    uint64  __VAR__ ExportTableCount;   // 56-�����ͷ�� �������ű�����

}TianyuFileHead;

typedef struct tianyuprogramhead
{
    byte    __VAR__ RunTime;            // 0-�������ͷ�� ��������ʱ
    byte    __VAR__ SystemVersion;      // 1-�������ͷ�� ϵͳ�汾
    byte    __VAR__ ProgramVersion;     // 2-�������ͷ�� ����汾
    byte    __VAR__ AdditionProp;       // 3-�������ͷ�� �������ԣ�û�п������壩
    byte    __VAR__ ProgramGroup;       // 4-�������ͷ�� �������ͣ�32/64��
    byte    __VAR__ ProcessGroup;       // 5-�������ͷ�� ���������
    byte    __VAR__ EncodeGroup;        // 6-�������ͷ�� ���뷽ʽ
    byte    __VAR__ FileLabel;          // 7-�������ͷ�� �ļ����/��ʶ
    uint64  __VAR__ CSPosition;         // 8-�������ͷ�� ����ζ�λ
    uint64  __VAR__ DSPosition;         // 16-�������ͷ�� ���ݶζ�λ��DSֵ��
    uint64  __VAR__ ProgramEntry;       // 24-�������ͷ�� ������ڣ��ļ�Ϊ��ִ���ļ�ʱ��Ч��
    uint32  __VAR__ StackSize;          // 32-�������ͷ�� �������ж�ջ��С
}TianyuProgramHead;

typedef struct tianyuhead
{
    TianyuFileHead      __VAR__ TYHead;
    TianyuProgramHead   __VAR__ ProgramHead;
}TianyuHead;


typedef struct tianyuadditionhead
{
    uint64  __VAR__ RelocationTableOffset;  // �����ͷ�� �ض����ƫ����

    uint64  __VAR__ RelocationTableCount;   // �����ͷ�� �ض��������
}TianyuAdditionHead;

typedef struct tystringtable
{
    char    __PTR__ RawString;      // �����ļ� �ַ����� �ַ���Դ
    uint64  __VAR__ StringLength;   // �����ļ� �ַ����� �ַ���Դ����
}TYStringTable;

typedef struct tytableitem
{
    byte    __VAR__ Type;           // 0-�����ļ����ű��� ��������
    uint64  __VAR__ ItemIndex;      // 1-�����ļ����ű��� ���ű��
    uint64  __VAR__ StringIndex;    // 9-�����ļ����ű��� �����ַ�����λ���
    uint64  __VAR__ ItemLocation;   // 17-�����ļ����ű��� ���������ζ�λ
    uint64  __VAR__ ItemLength;     // 25-�����ļ����ű��� ���������γ���
}TYTableItem;

typedef struct tyreloactionitem
{
    byte    __VAR__ Type;           // 0-�����ض������ ��������
    byte    __VAR__ State;          // 1-�����ض������ �ض�λ��ʽ
    byte    __VAR__ LocateLength;   // 2-�����ض������ �ض�λ���ȣ�8/16/32/64��
    uint64  __VAR__ Offset;         // 3-�����ض������ ���ڵ��ض�λλ��
    uint64  __VAR__ StringIndex;    // 11-�����ض������ �������ַ������
}TYRelocationItem;

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUFILE_TYEXESTRUCT_H__