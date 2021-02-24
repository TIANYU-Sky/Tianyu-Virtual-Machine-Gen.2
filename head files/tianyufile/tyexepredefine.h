#pragma once

#ifndef __TIANYUFILE_TYEXEPREDEFINE_H__
#define __TIANYUFILE_TYEXEPREDEFINE_H__

#include"../define.h"

#ifdef __cplusplus
__C__
{
#endif

#define TianyuFile_TYM  0x01    // �����ļ���ʽ Ŀ���ļ�
#define TianyuFile_TYL  0x02    // �����ļ���ʽ �����ļ�
#define TianyuFile_TYY  0x03    // �����ļ���ʽ Ӧ�ó���
#define TianyuFile_TYK  0x04    // �����ļ���ʽ ��̬���ӿ�
#define TianyuFile_TYD  0x05    // �����ļ���ʽ ��̬���ӿ�

#define TianyuFile_TYI  0x10    // �����ļ���ʽ TYI�ı��ļ�
#define TianyuFile_TYJ  0x11    // �����ļ���ʽ TYJ�ı��ļ�
#define TianyuFile_TYX  0x12    // �����ļ���ʽ TYX�ı��ļ�
#define TianyuFile_TY_  0x13    // �����ļ���ʽ TY�ļ�
#define TianyuFile_TYH  0x14    // �����ļ���ʽ TYH�ı��ļ������ʽ�ļ���
#define TianyuFile_TYT  0x15    // �����ļ���ʽ TYT�ı��ļ���xml�����ļ���
#define TianyuFile_LOG  0x16    // �����ļ���ʽ TLOG��־�ļ�

#define TianyuFile_NON  0xFF    // �����ļ���ʽ �������ļ���ʽ

// �����ļ�ͷħ����ZTTQTXZY��
#define __TianyuFileHead_MagicNumber_Pre__ {'Z','T','T','Q','T','X','Z','Y'}

#define __TianyuProgramHead_RunTime_PHY__       0x01        // �������ͷ�� ���л��� �����
#define __TianyuProgramHead_RunTime_VIR__       0x02        // �������ͷ�� ���л��� �����

#define __TianyuProgramHead_SystemVersion__     0x10        // �������ͷ�� ϵͳ�汾 1.0

#define __TianyuProgramHead_ProgramVersion__    0x10        // �������ͷ�� ����汾 1.0

#define __TianyuProgramHead_ProgramGroup_x86__  0x01        // �������ͷ�� ������ 32λ����
#define __TianyuProgramHead_ProgramGroup_x64__  0x02        // �������ͷ�� ������ 64λ����

#define __TianyuProgramHead_ProcessGroup_TVM__   0x01       // �������ͷ�� ������� ���������
#define __TianyuProgramHead_ProcessGroup_ARM__   0x02       // �������ͷ�� ������� ARM�����
#define __TianyuProgramHead_ProcessGroup_x86__   0x04       // �������ͷ�� ������� X86�����
#define __TianyuProgramHead_ProcessGroup_BCM__   0x08       // �������ͷ�� ������� �ֽ��������

#define __TianyuProgramHead_EncodeGroup_Little__    0x00    // �������ͷ�� ���뷽ʽ С�� 
#define __TianyuProgramHead_EncodeGroup_Large__     0x08    // �������ͷ�� ���뷽ʽ ���

#define __TianyuProgramHead_FileLabel_TYM__   0x01          // �������ͷ�� �ļ����� Ŀ���ļ�
#define __TianyuProgramHead_FileLabel_TYL__   0x02          // �������ͷ�� �ļ����� �����ļ�
#define __TianyuProgramHead_FileLabel_TYY__   0x04          // �������ͷ�� �ļ����� Ӧ�ó���
#define __TianyuProgramHead_FileLabel_TYJ__   0x08          // �������ͷ�� �ļ����� ��̬���ӿ�
#define __TianyuProgramHead_FileLabel_TYD__   0x10          // �������ͷ�� �ļ����� ��̬���ӿ�

#define __TianyuSignTableGroup_SignType_VAR__   0x01        // ������ű� ����
#define __TianyuSignTableGroup_SignType_LAB__   0x02        // ������ű� ��ǩ
#define __TianyuSignTableGroup_SignType_PRO__   0x04        // ������ű� ����/����
#define __TianyuSignTableGroup_SignType_EXT__   0x08        // ������ű� ��չ
#define __TianyuSignTableGroup_SignType_DEF__   0x08        // ������ű� ���Ͷ���

#define __TianyuRelocateTableGroup_LocateLength_8__     0x03        // �����ض�λ�� �ض�λ����-8λ
#define __TianyuRelocateTableGroup_LocateLength_16__    0x02        // �����ض�λ�� �ض�λ����-16λ
#define __TianyuRelocateTableGroup_LocateLength_32__    0x01        // �����ض�λ�� �ض�λ����-32λ
#define __TianyuRelocateTableGroup_LocateLength_64__    0x00        // �����ض�λ�� �ض�λ����-64λ

#define __TianyuRelocateTableGroup_State_REL__   0x01        // �����ض�λ�� ���Ѱַ������ʱ�ض�λ��
#define __TianyuRelocateTableGroup_State_ABS__   0x04        // �����ض�λ�� ��ǩ��װ��ʱ�ض�λ��

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUFILE_TYEXEPREDEFINE_H__