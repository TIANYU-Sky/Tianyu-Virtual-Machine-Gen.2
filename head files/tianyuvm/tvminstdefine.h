/**
 * �������������ϵͳ��ϵͳ���ÿ�
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_TVMINSTDEFINE__
#define __TIANYUVM_C_CPP_TVMINSTDEFINE__

#include"../define.h"

#define __INSTRUCTION_LOCK_STATE_TEST__                 0b01        // ����ָ����״̬
#define __INSTRUCTION_LOCK_STATE_LOCK__                 true        // ָ����ǰָ�������ڴ���
#define __INSTRUCTION_LOCK_STATE_UNLOCK__               false       // ָ����ǰָ���������ڴ���

#define __INSTRUCTION_OPDIRECT_TEST__                   0b10        // ����ָ�����㷽��
#define __INSTRUCTION_OPDIRECT_ONE_TO_TWO__             false       // ָ����ǰָ�����㷽��Ϊ ��һ���������ڶ�������
#define __INSTRUCTION_OPDIRECT_TWO_TO_ONE__             true        // ָ����ǰָ�����㷽��Ϊ �ڶ�����������һ������

#define __INSTRUCTION_SEGMENT_DEFAULTSEG__              0b111       // ָ��μĴ������� Ĭ�ϼĴ���
#define __INSTRUCTION_SEGMENT_CODESEG__                 0b001       // ָ��μĴ������� CS
#define __INSTRUCTION_SEGMENT_DATASEG__                 0b010       // ָ��μĴ������� DS
#define __INSTRUCTION_SEGMENT_STACKSEG__                0b011       // ָ��μĴ������� SS
#define __INSTRUCTION_SEGMENT_EXPANDSEG__               0b100       // ָ��μĴ������� ES
#define __INSTRUCTION_SEGMENT_NULL__                    0x000       // ָ��μĴ������� �޶μĴ���

#define __INSTRUCTION_OPNUMBER_64__                     0b00        // ָ����������С64λ
#define __INSTRUCTION_OPNUMBER_32__                     0b01        // ָ����������С32λ
#define __INSTRUCTION_OPNUMBER_16__                     0b10        // ָ����������С16λ
#define __INSTRUCTION_OPNUMBER_8__                      0b11        // ָ����������С8λ

#define __INSTRUCTION_ADDRESSING_OTHER__                0b00        // ָ��ָ��Ѱַ��ʽ ����Ѱַ
#define __INSTRUCTION_ADDRESSING_REG_DIRECT__           0b01        // ָ��ָ��Ѱַ��ʽ �Ĵ���ֱ��Ѱַ
#define __INSTRUCTION_ADDRESSING_IMM_INDIRECT__         0b10        // ָ��ָ��Ѱַ��ʽ ���������Ѱַ
#define __INSTRUCTION_ADDRESSING_IMM_DIRECT__           0b11        // ָ��ָ��Ѱַ��ʽ ֱ��������

#define __INSTRUCTION_OPNUM_IMM_SIZE_64__               0b1000      // ָ��������������׺�ĳ��� 64λ
#define __INSTRUCTION_OPNUM_IMM_SIZE_32__               0b0100      // ָ��������������׺�ĳ��� 32λ
#define __INSTRUCTION_OPNUM_IMM_SIZE_16__               0b0010      // ָ��������������׺�ĳ��� 16λ
#define __INSTRUCTION_OPNUM_IMM_SIZE_8__                0b0001      // ָ��������������׺�ĳ��� 8λ

#define __INSTRUCTION_OPONE_BASE_ADDR_STATE_VAILD__     true        // ��ѰַģʽΪ����Ѱַʱ ָʾ��ַ�Ĵ�����Ч
#define __INSTRUCTION_OPONE_BASE_ADDR_STATE_INVAILD__   false       // ��ѰַģʽΪ����Ѱַʱ ָʾ��ַ�Ĵ�����Ч

#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_1__         0b00        // ��ѰַģʽΪ����Ѱַʱ ָʾ��ַ�Ĵ�����Ա���1��
#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_2__         0b01        // ��ѰַģʽΪ����Ѱַʱ ָʾ��ַ�Ĵ�����Ա���2��
#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_4__         0b10        // ��ѰַģʽΪ����Ѱַʱ ָʾ��ַ�Ĵ�����Ա���4��
#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_8__         0b11        // ��ѰַģʽΪ����Ѱַʱ ָʾ��ַ�Ĵ�����Ա���8��
#define __INSTRUCTION_OPONE_BASE_ADDR_TIMES_TEST__      0b11        // ��ѰַģʽΪ����Ѱַʱ ������Ա���

#define __INSTRUCTION_OPONE_BASE_ADDR_OFFSET_VAILD__    true        // ��ѰַģʽΪ����Ѱַʱ ָʾ��ַ�Ĵ������ƫ������Ч
#define __INSTRUCTION_OPONE_BASE_ADDR_OFFSET_INVAILD__  false       // ��ѰַģʽΪ����Ѱַʱ ָʾ��ַ�Ĵ������ƫ������Ч

#define __INSTRUCTION_SECOND_OPTYPE_NONE__              0b00        // ָ���ڶ����������� �޵ڶ�������
#define __INSTRUCTION_SECOND_OPTYPE_REG__               0b01        // ָ���ڶ����������� �Ĵ���������
#define __INSTRUCTION_SECOND_OPTYPE_IMM__               0b10        // ָ���ڶ����������� ������
#define __INSTRUCTION_SECOND_OPTYPE_EXP__               0b11        // ָ���ڶ����������� ��չ���ͣ���ǰ��ʹ�ã�
#define __INSTRUCTION_SECOND_OPTYPE_TEST__              0b11        // ָ���ڶ����������� ����

#define __TYVM_SIGNREGISTER_CARRY_FLAG__    0b0000000000000001   // ��������� ��־�Ĵ��� ��λ��־λ
#define __TYVM_SIGNREGISTER_PARITY_FLAG__   0b0000000000000100   // ��������� ��־�Ĵ��� ��ż��־λ
#define __TYVM_SIGNREGISTER_ZERO_FLAG__     0b0000000001000000   // ��������� ��־�Ĵ��� ���־��λ
#define __TYVM_SIGNREGISTER_SIGN_FLAG__     0b0000000010000000   // ��������� ��־�Ĵ��� ���ű�־��λ
#define __TYVM_SIGNREGISTER_OVERFLOW_FLAG__ 0b0000100000000000   // ��������� ��־�Ĵ��� �����־λ

#define __TYVM_SIGN_DISTINGUISH_NUM__   0x8000000000000000 // ��������� �����б��

#define __TYVM_REGISTER_RAX__   0b0000  // ���������ָ� �Ĵ������� RAX �ۼӼĴ���
#define __TYVM_REGISTER_RBX__   0b0001  // ���������ָ� �Ĵ������� RBX ��ַ�Ĵ���
#define __TYVM_REGISTER_RCX__   0b0010  // ���������ָ� �Ĵ������� RCX �����Ĵ���
#define __TYVM_REGISTER_RDX__   0b0011  // ���������ָ� �Ĵ������� RDX ���ݼĴ���
#define __TYVM_REGISTER_RSP__   0b0100  // ���������ָ� �Ĵ������� RSP ջָ��Ĵ���
#define __TYVM_REGISTER_RBP__   0b0101  // ���������ָ� �Ĵ������� RBP ��ַָ��Ĵ���
#define __TYVM_REGISTER_RSI__   0b0110  // ���������ָ� �Ĵ������� RSI Դַ�Ĵ���
#define __TYVM_REGISTER_RDI__   0b0111  // ���������ָ� �Ĵ������� RDI Ŀ�ĵ�ַ�Ĵ���
#define __TYVM_REGISTER_R8__    0b1000  // ���������ָ� �Ĵ������� R8 ͨ�üĴ���
#define __TYVM_REGISTER_R9__    0b1001  // ���������ָ� �Ĵ������� R9 ͨ�üĴ���
#define __TYVM_REGISTER_R10__   0b1010  // ���������ָ� �Ĵ������� R10 ͨ�üĴ���
#define __TYVM_REGISTER_R11__   0b1011  // ���������ָ� �Ĵ������� R11 ͨ�üĴ���
#define __TYVM_REGISTER_R12__   0b1100  // ���������ָ� �Ĵ������� R12 ͨ�üĴ���
#define __TYVM_REGISTER_R13__   0b1101  // ���������ָ� �Ĵ������� R13 ͨ�üĴ���
#define __TYVM_REGISTER_R14__   0b1110  // ���������ָ� �Ĵ������� R14 ͨ�üĴ���
#define __TYVM_REGISTER_R15__   0b1111  // ���������ָ� �Ĵ������� R15 ͨ�üĴ���

#define __TYVM_REGISTER_ST_TEST__ 0x07  // ���������ָ� �Ĵ������� ST�����ջ�Ĵ�������

#define __TYVM_REGISTER_ST0__   0b0000  // ���������ָ� �Ĵ������� ST(0)�����ջ�Ĵ���
#define __TYVM_REGISTER_ST1__   0b0001  // ���������ָ� �Ĵ������� ST(1)�����ջ�Ĵ���
#define __TYVM_REGISTER_ST2__   0b0010  // ���������ָ� �Ĵ������� ST(2)�����ջ�Ĵ���
#define __TYVM_REGISTER_ST3__   0b0011  // ���������ָ� �Ĵ������� ST(3)�����ջ�Ĵ���
#define __TYVM_REGISTER_ST4__   0b0100  // ���������ָ� �Ĵ������� ST(4)�����ջ�Ĵ���
#define __TYVM_REGISTER_ST5__   0b0101  // ���������ָ� �Ĵ������� ST(5)�����ջ�Ĵ���
#define __TYVM_REGISTER_ST6__   0b0110  // ���������ָ� �Ĵ������� ST(6)�����ջ�Ĵ���
#define __TYVM_REGISTER_ST7__   0b0111  // ���������ָ� �Ĵ������� ST(7)�����ջ�Ĵ���

#define __TYVM_REGISTER_MMX0__   0b1000  // ���������ָ� �Ĵ������� MMX(0)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TYVM_REGISTER_MMX1__   0b1001  // ���������ָ� �Ĵ������� MMX(1)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TYVM_REGISTER_MMX2__   0b1010  // ���������ָ� �Ĵ������� MMX(2)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TYVM_REGISTER_MMX3__   0b1011  // ���������ָ� �Ĵ������� MMX(3)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TYVM_REGISTER_MMX4__   0b1100  // ���������ָ� �Ĵ������� MMX(4)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TYVM_REGISTER_MMX5__   0b1101  // ���������ָ� �Ĵ������� MMX(5)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TYVM_REGISTER_MMX6__   0b1110  // ���������ָ� �Ĵ������� MMX(6)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�
#define __TYVM_REGISTER_MMX7__   0b1111  // ���������ָ� �Ĵ������� MMX(7)�����ջ�Ĵ�������ǰ��SSE����ָ� ���Ĵ��Ժ���������ã�

#define __TYVM_REG_IMM_TEST__   0b1111  // ���������ָ� �Ĵ�������

#define __TYVM_INSTRUCTION_PREFIX_TEST__        0xF0    // ���������ָ� ǰ׺���Ա���
#define __TYVM_INSTRUCTION_PREFIX_FUNCTION__    0x90    // ���������ָ� ����ǰ׺������Lock���ܡ����������򡢲�������С��
#define __TYVM_INSTRUCTION_PREFIX_REGISTER__    0x60    // ���������ָ� �Ĵ���ǰ׺ ָʾ��ǰָ�������յĶμĴ���


#define _USE_MATH_DEFINES
#define M_LOG10_2   0.30102999566398119521373889472449 // log10(2)
#define M_LOG2_10   3.3219280948873623478703194294894  // log2(10) 


/**
 * ���������ָ��������
*/

#define __TYVM_INSTRUCTION_OPNUM_TEST__     0xF0    // �������������������
#define __TYVM_INSTRUCTION_OPNUM_ZERO_A__   0x00
#define __TYVM_INSTRUCTION_OPNUM_ZERO_B__   0x10
#define __TYVM_INSTRUCTION_OPNUM_ZERO_C__   0xD0
#define __TYVM_INSTRUCTION_OPNUM_ONE_A__    0x20
#define __TYVM_INSTRUCTION_OPNUM_ONE_B__    0x30
#define __TYVM_INSTRUCTION_OPNUM_ONE_C__    0x40
#define __TYVM_INSTRUCTION_OPNUM_ONE_D__    0x50
#define __TYVM_INSTRUCTION_OPNUM_ONE_E__    0xE0
#define __TYVM_INSTRUCTION_OPNUM_ONE_F__    0xF0
#define __TYVM_INSTRUCTION_OPNUM_TWO_A__    0xA0
#define __TYVM_INSTRUCTION_OPNUM_TWO_B__    0xB0
#define __TYVM_INSTRUCTION_OPNUM_TWO_C__    0xC0

#define __TYVM_INSTRUCTION_NOP__        0x00    // ���������ָ����� ��ָ��
#define __TYVM_INSTRUCTION_STC__        0x01    // ���������ָ����� ���ñ�־�Ĵ��� ��λ��־λΪ1
#define __TYVM_INSTRUCTION_CLC__        0x02    // ���������ָ����� ���ñ�־�Ĵ��� ��λ��־λΪ0
#define __TYVM_INSTRUCTION_CMC__        0x03    // ���������ָ����� ���ñ�־�Ĵ��� ��λ��־λȡ��
#define __TYVM_INSTRUCTION_RET__        0x04    // ���������ָ����� ���̷���
#define __TYVM_INSTRUCTION_IRET__       0x05    // ���������ָ����� �жϷ��أ���ǰΪ��ָ�
#define __TYVM_INSTRUCTION_PUSHF__      0x06    // ���������ָ����� ��64λ��־�Ĵ�������ջ��
#define __TYVM_INSTRUCTION_POPF__       0x07    // ���������ָ����� ��ջ��64λ���ݵ�������־�Ĵ���
#define __TYVM_INSTRUCTION_PUSHA__      0x08    // ���������ָ����� ��RAX��RBX��RDX��RCX��RSP��RBP��RSI��RDI����ѹ��ջ��
#define __TYVM_INSTRUCTION_POPA__       0x09    // ���������ָ����� ��RDI��RSI��RBP��RSP��RCX��RDX��RBX��RAX���ε�����ջ
#define __TYVM_INSTRUCTION_LAIP__       0x0A    // ���������ָ����� ��RIP�Ĵ���������RAX�Ĵ���
#define __TYVM_INSTRUCTION_SAIP__       0x0B    // ���������ָ����� ��RAX�Ĵ�������RIP�Ĵ���

#define __TYVM_INSTRUCTION_PUSH__       0x20    // ���������ָ����� ��ָ��Ԫ��ѹ���ջ
#define __TYVM_INSTRUCTION_POP__        0x21    // ���������ָ����� ��ջ��Ԫ�ص���
#define __TYVM_INSTRUCTION_IN__         0x22    // ���������ָ����� IO����ָ��
#define __TYVM_INSTRUCTION_LDS__        0x23    // ���������ָ����� ��ָ��װ��DS
#define __TYVM_INSTRUCTION_LES__        0x24    // ���������ָ����� ��ָ��װ��ES
#define __TYVM_INSTRUCTION_LCS__        0x25    // ���������ָ����� ��ָ��װ��CS
#define __TYVM_INSTRUCTION_LGS__        0x26    // ���������ָ����� ��ָ��װ��GS����ǰΪ��ָ�
#define __TYVM_INSTRUCTION_LSS__        0x27    // ���������ָ����� ��ָ��װ��SS
#define __TYVM_INSTRUCTION_LAF__        0x28    // ���������ָ����� ����־�Ĵ������ݴ�����RAX
#define __TYVM_INSTRUCTION_SAF__        0x29    // ���������ָ����� ��RAX���ݴ�������־�Ĵ���
#define __TYVM_INSTRUCTION_INC__        0x2A    // ���������ָ����� ����1
#define __TYVM_INSTRUCTION_DEC__        0x2B    // ���������ָ����� �Լ�1
#define __TYVM_INSTRUCTION_NEG__        0x2C    // ���������ָ����� ��
#define __TYVM_INSTRUCTION_JMP__        0x2D    // ���������ָ����� ��������תָ��
#define __TYVM_INSTRUCTION_CALL__       0x2E    // ���������ָ����� ����������ָ��漰CS/RIP��ջ��
#define __TYVM_INSTRUCTION_JE__         0x2F    // ���������ָ����� ���ʱת��
#define __TYVM_INSTRUCTION_JZ__         0x30    // ���������ָ����� ����0ʱת��
#define __TYVM_INSTRUCTION_JNE__        0x31    // ���������ָ����� ����ʱת��
#define __TYVM_INSTRUCTION_JNZ__        0x32    // ���������ָ����� ������0ʱת��
#define __TYVM_INSTRUCTION_JC__         0x33    // ���������ָ����� �н�λʱת��
#define __TYVM_INSTRUCTION_JNC__        0x34    // ���������ָ����� �޽�λʱת��
#define __TYVM_INSTRUCTION_JO__         0x35    // ���������ָ����� ���ʱת��
#define __TYVM_INSTRUCTION_JNO__        0x36    // ���������ָ����� δ���ʱת��
#define __TYVM_INSTRUCTION_JS__         0x37    // ���������ָ����� ����λΪ1ʱת�ƣ�����ʱת�ƣ�
#define __TYVM_INSTRUCTION_JNS__        0x38    // ���������ָ����� ����λΪ0ʱת�ƣ�����ʱת�ƣ�
#define __TYVM_INSTRUCTION_JP__         0x39    // ���������ָ����� ż��ʱת��
#define __TYVM_INSTRUCTION_JNP__        0x3A    // ���������ָ����� ����ʱת��
#define __TYVM_INSTRUCTION_JPO__        0x3B    // ���������ָ����� ����ʱת��
#define __TYVM_INSTRUCTION_JPE__        0x3C    // ���������ָ����� ż��ʱת��
#define __TYVM_INSTRUCTION_LOOP__       0x3D    // ���������ָ����� RCX��Ϊ0ʱѭ��
#define __TYVM_INSTRUCTION_JCXZ__       0x3E    // ���������ָ����� RCXΪ0ʱת��
#define __TYVM_INSTRUCTION_INT__        0x3F    // ���������ָ����� �ж�ָ��������ݱ��沢��ת��
#define __TYVM_INSTRUCTION_NOT__        0xE0    // ���������ָ����� ��

#define __TYVM_INSTRUCTION_MOV__        0xA0    // ���������ָ����� ����ָ��
#define __TYVM_INSTRUCTION_MOVW__       0xA1    // ���������ָ����� ����ָ���ǰΪ��ָ�
#define __TYVM_INSTRUCTION_MOVDW__      0xA2    // ���������ָ����� ����ָ���ǰΪ��ָ�
#define __TYVM_INSTRUCTION_MOVQW__      0xA3    // ���������ָ����� ����ָ���ǰΪ��ָ�
#define __TYVM_INSTRUCTION_CMPXCHG__    0xA4    // ���������ָ����� �Ƚϲ��������Զ�����Lock����
#define __TYVM_INSTRUCTION_OUT__        0xA5    // ���������ָ����� IO���ָ��
#define __TYVM_INSTRUCTION_LEA__        0xA6    // ���������ָ����� װ����Ч��ַ
#define __TYVM_INSTRUCTION_ADD__        0xA7    // ���������ָ����� �ӷ�
#define __TYVM_INSTRUCTION_SUB__        0xA8    // ���������ָ����� ����
#define __TYVM_INSTRUCTION_CMP__        0xA9    // ���������ָ����� �Ƚ�ָ��
#define __TYVM_INSTRUCTION_MUL__        0xAA    // ���������ָ����� �޷��ų˷�
#define __TYVM_INSTRUCTION_IMUL__       0xAB    // ���������ָ����� �з��ų˷�
#define __TYVM_INSTRUCTION_DIV__        0xAC    // ���������ָ����� �޷��ų���
#define __TYVM_INSTRUCTION_IDIV__       0xAD    // ���������ָ����� �з��ų���
#define __TYVM_INSTRUCTION_AND__        0xAE    // ���������ָ����� ��
#define __TYVM_INSTRUCTION_OR__         0xAF    // ���������ָ����� ��
#define __TYVM_INSTRUCTION_XOR__        0xB1    // ���������ָ����� ���
#define __TYVM_INSTRUCTION_SHR__        0xB2    // ���������ָ����� �߼�����
#define __TYVM_INSTRUCTION_SAR__        0xB3    // ���������ָ����� ��������
#define __TYVM_INSTRUCTION_SHL__        0xB4    // ���������ָ����� �߼�����
#define __TYVM_INSTRUCTION_SAL__        0xB5    // ���������ָ����� ��������
#define __TYVM_INSTRUCTION_ROL__        0xB6    // ���������ָ����� ѭ�����ƣ���ǰΪ��ָ�
#define __TYVM_INSTRUCTION_ROR__        0xB7    // ���������ָ����� ѭ�����ƣ���ǰΪ��ָ�
#define __TYVM_INSTRUCTION_RCL__        0xB8    // ���������ָ����� ����λ��ѭ�����ƣ���ǰΪ��ָ�
#define __TYVM_INSTRUCTION_RCR__        0xB9    // ���������ָ����� ����λ��ѭ�����ƣ���ǰΪ��ָ�


/**
 * ����ָ����
*/
#define __TYVM_INSTRUCTION_FINIT__      0x10    // ���������ָ����� ��ʼ�����㲿��������Ĵ������㡢�Ĵ���ָ�����㣩
#define __TYVM_INSTRUCTION_FCLEX__      0x11    // ���������ָ����� ����쳣
#define __TYVM_INSTRUCTION_FNOP__       0x12    // ���������ָ����� �����ָ��
#define __TYVM_INSTRUCTION_FLDZ__       0x13    // ���������ָ����� ��0.0װ��ST(0)
#define __TYVM_INSTRUCTION_FLD1__       0x14    // ���������ָ����� ��1.0װ��ST(0)
#define __TYVM_INSTRUCTION_FLDPI__      0x15    // ���������ָ����� ��PIװ��ST(0)
#define __TYVM_INSTRUCTION_FLDL2T__     0x16    // ���������ָ����� ��log2(10)װ��ST(0)
#define __TYVM_INSTRUCTION_FLDL2E__     0x17    // ���������ָ����� ��log2(e)װ��ST(0)
#define __TYVM_INSTRUCTION_FLDLG2__     0x18    // ���������ָ����� ��log10(2)װ��ST(0)
#define __TYVM_INSTRUCTION_FLDLN2__     0x19    // ���������ָ����� ��ln2װ��ST(0)
#define __TYVM_INSTRUCTION_FDECSTP__    0x1A    // ���������ָ����� ����ջָ��
#define __TYVM_INSTRUCTION_FINCSTP__    0x1B    // ���������ָ����� ����ջָ��

#define __TYVM_INSTRUCTION_FCHS__       0xD1    // ���������ָ����� �ı�ST(0)��������
#define __TYVM_INSTRUCTION_FABS__       0xD2    // ���������ָ����� ��ST(0)ȡ����ֵ����
#define __TYVM_INSTRUCTION_FSQRT__      0xD3    // ���������ָ����� ��ST(0)ȡ���ź󱣴�
#define __TYVM_INSTRUCTION_FSIN__       0xD4    // ���������ָ����� ��ST(0)ȡ����ֵ�󱣴�
#define __TYVM_INSTRUCTION_FCOS__       0xD5    // ���������ָ����� ��ST(0)ȡ����ֵ�󱣴�
#define __TYVM_INSTRUCTION_FXCH_A__     0xD6    // ���������ָ����� ����ST(0)��ST(1)
#define __TYVM_INSTRUCTION_FCMP_A__     0xD7    // ���������ָ����� �Ƚ�ST(0)��ST(1)
#define __TYVM_INSTRUCTION_FADD_A__     0xD8    // ���������ָ����� ����ӷ� ST(0)+ST(1)
#define __TYVM_INSTRUCTION_FSUB_A__     0xD9    // ���������ָ����� ������� ST(0)-ST(1)
#define __TYVM_INSTRUCTION_FSUBR_A__    0xDA    // ���������ָ����� ������� ST(1)-ST(0)
#define __TYVM_INSTRUCTION_FMUL_A__     0xDB    // ���������ָ����� ����˷� ST(0)*ST(1)
#define __TYVM_INSTRUCTION_FDIV_A__     0xDC    // ���������ָ����� ������� ST(0)/ST(1)
#define __TYVM_INSTRUCTION_FDIVR_A__    0xDD    // ���������ָ����� ������� ST(1)/ST(0)

#define __TYVM_INSTRUCTION_FXCH__       0x40    // ���������ָ����� ����ST(0)��ST(1)
#define __TYVM_INSTRUCTION_FLD__        0x41    // ���������ָ����� ��������װ��ST(0)
#define __TYVM_INSTRUCTION_FILD__       0x42    // ���������ָ����� ��64Ϊ����װ��ST(0)
#define __TYVM_INSTRUCTION_FST__        0x43    // ���������ָ����� ���渡����ST(0)
#define __TYVM_INSTRUCTION_FIST__       0x44    // ���������ָ����� ��������ST(0)
#define __TYVM_INSTRUCTION_FCMP__       0x45    // ���������ָ����� �Ƚ�ST(0)��ST(1)
#define __TYVM_INSTRUCTION_FADD__       0x46    // ���������ָ����� ����ӷ� ST(0)+ST(1)
#define __TYVM_INSTRUCTION_FIADD__      0x47    // ���������ָ����� ����ӷ� ST(0)+����
#define __TYVM_INSTRUCTION_FSUB__       0x48    // ���������ָ����� ������� ST(0)-ST(1)
#define __TYVM_INSTRUCTION_FSUBR__      0x49    // ���������ָ����� ������� ST(1)-ST(0)
#define __TYVM_INSTRUCTION_FISUB__      0x4A    // ���������ָ����� ������� ST(0)-����
#define __TYVM_INSTRUCTION_FISUBR__     0x4B    // ���������ָ����� ������� ����-ST(0)
#define __TYVM_INSTRUCTION_FMUL__       0x4C    // ���������ָ����� ����˷� ST(0)*ST(1)
#define __TYVM_INSTRUCTION_FIMUL__      0x4D    // ���������ָ����� ����˷� ST(0)*����
#define __TYVM_INSTRUCTION_FDIV__       0x4E    // ���������ָ����� ������� ST(0)/ST(1)
#define __TYVM_INSTRUCTION_FDIVR__      0x4F    // ���������ָ����� ������� ST(i)/ST(0)
#define __TYVM_INSTRUCTION_FIDIV__      0x50    // ���������ָ����� ������� ST(0)/����
#define __TYVM_INSTRUCTION_FIDIVR__     0x51    // ���������ָ����� ������� ����/ST(0)

#define __TYVM_INSTRUCTION_INVAILD__    0xFF    // ���������ָ����� ��Ч����

#endif // !__TIANYUVM_C_CPP_TVMINSTDEFINE__