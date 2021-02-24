
#pragma once
#ifndef __TIANYULANGUAGE_C_CPP_TLDEFINE__
#define __TIANYULANGUAGE_C_CPP_TLDEFINE__

#define __TIANYULANGUAGE_FILE_ENCODE_UTF8__     0x00
#define __TIANYULANGUAGE_FILE_ENCODE_GB2312__   0x01
#define __TIANYULANGUAGE_FILE_ENCODE_ASCII__    0x02


#define __TIANYULANGUAGE_REGISTER_RAX__   0b000000  // �������� �Ĵ������� RAX �ۼӼĴ���
#define __TIANYULANGUAGE_REGISTER_RBX__   0b000001  // �������� �Ĵ������� RBX ��ַ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_RCX__   0b000010  // �������� �Ĵ������� RCX �����Ĵ���
#define __TIANYULANGUAGE_REGISTER_RDX__   0b000011  // �������� �Ĵ������� RDX ���ݼĴ���
#define __TIANYULANGUAGE_REGISTER_RSP__   0b000100  // �������� �Ĵ������� RSP ջָ��Ĵ���
#define __TIANYULANGUAGE_REGISTER_RBP__   0b000101  // �������� �Ĵ������� RBP ��ַָ��Ĵ���
#define __TIANYULANGUAGE_REGISTER_RSI__   0b000110  // �������� �Ĵ������� RSI Դַ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_RDI__   0b000111  // �������� �Ĵ������� RDI Ŀ�ĵ�ַ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_R8__    0b001000  // �������� �Ĵ������� R8 ͨ�üĴ���
#define __TIANYULANGUAGE_REGISTER_R9__    0b001001  // �������� �Ĵ������� R9 ͨ�üĴ���
#define __TIANYULANGUAGE_REGISTER_R10__   0b001010  // �������� �Ĵ������� R10 ͨ�üĴ���
#define __TIANYULANGUAGE_REGISTER_R11__   0b001011  // �������� �Ĵ������� R11 ͨ�üĴ���
#define __TIANYULANGUAGE_REGISTER_R12__   0b001100  // �������� �Ĵ������� R12 ͨ�üĴ���
#define __TIANYULANGUAGE_REGISTER_R13__   0b001101  // �������� �Ĵ������� R13 ͨ�üĴ���
#define __TIANYULANGUAGE_REGISTER_R14__   0b001110  // �������� �Ĵ������� R14 ͨ�üĴ���
#define __TIANYULANGUAGE_REGISTER_R15__   0b001111  // �������� �Ĵ������� R15 ͨ�üĴ���

#define __TIANYULANGUAGE_REGISTER_ST0__   0b010000  // �������� �Ĵ������� ST(0)�����ջ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_ST1__   0b010001  // �������� �Ĵ������� ST(1)�����ջ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_ST2__   0b010010  // �������� �Ĵ������� ST(2)�����ջ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_ST3__   0b010011  // �������� �Ĵ������� ST(3)�����ջ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_ST4__   0b010100  // �������� �Ĵ������� ST(4)�����ջ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_ST5__   0b010101  // �������� �Ĵ������� ST(5)�����ջ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_ST6__   0b010110  // �������� �Ĵ������� ST(6)�����ջ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_ST7__   0b010111  // �������� �Ĵ������� ST(7)�����ջ�Ĵ���

#define __TIANYULANGUAGE_REGISTER_MMX0__  0b011000  // �������� �Ĵ������� MMX(0)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TIANYULANGUAGE_REGISTER_MMX1__  0b011001  // �������� �Ĵ������� MMX(1)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TIANYULANGUAGE_REGISTER_MMX2__  0b011010  // �������� �Ĵ������� MMX(2)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TIANYULANGUAGE_REGISTER_MMX3__  0b011011  // �������� �Ĵ������� MMX(3)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TIANYULANGUAGE_REGISTER_MMX4__  0b011100  // �������� �Ĵ������� MMX(4)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TIANYULANGUAGE_REGISTER_MMX5__  0b011101  // �������� �Ĵ������� MMX(5)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TIANYULANGUAGE_REGISTER_MMX6__  0b011110  // �������� �Ĵ������� MMX(6)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TIANYULANGUAGE_REGISTER_MMX7__  0b011111  // �������� �Ĵ������� MMX(7)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�

#define __TIANYULANGUAGE_REGISTER_CS__    0b100001  // �������� �Ĵ������� RAX �ۼӼĴ���
#define __TIANYULANGUAGE_REGISTER_DS__    0b100010  // �������� �Ĵ������� RBX ��ַ�Ĵ���
#define __TIANYULANGUAGE_REGISTER_ES__    0b100011  // �������� �Ĵ������� RCX �����Ĵ���
#define __TIANYULANGUAGE_REGISTER_SS__    0b100100  // �������� �Ĵ������� RDX ���ݼĴ���

#define __TYLASM_LEXICAL_NO_ERROR__				0x00
#define __TYLASM_LEXICAL_LABEL_W_DOT__          0x11    // ���������� �ʷ��������� ��.��ͷ�ı�ʶ��
#define __TYLASM_LEXICAL_NUMBER_ERROR__         0x12    // ���������� �ʷ��������� ���ֽṹ

#define __TYL_SIGN_LENGTH_MAX__ 1024

#ifdef __cplusplus
#endif

#ifdef __cplusplus
#endif

#endif // !__TIANYULANGUAGE_C_CPP_TLDEFINE__