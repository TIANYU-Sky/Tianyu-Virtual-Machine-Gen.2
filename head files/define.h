
#pragma once

#ifndef __TIANYUSL_C_CPP_DEFINE__
#define __TIANYUSL_C_CPP_DEFINE__

#define __Predefine__   // ǰ��������ǩ

#define __VAR__     // ֵ���ͱ�ǩ
#define __PTR__ *   // ָ�����ͱ�ǩ

#define __P_To_V__  *   // ����ת����ָ���ֵ
#define __V_To_P__  &   // ����ת����ֵ��ָ��

#define __IN_Param__    // ���������ǩ
#define __OT_Param__    // ���������ǩ
#define __IO_Param__    // �������������ǩ

#define __Request___    // ���󷽷���ǩ
#define __Response__    // �ظ�������ǩ

#define obscure         // ģ�������ǩ                

#define __Signed_Char_Min__     (-128)                      // �ַ������з�����Сֵ
#define __Signed_Char_Max__     127                         // �ַ������з������ֵ
#define __Unsigned_Char_Min__   0                           // �ַ������޷�����Сֵ
#define __Unsigned_Char_Max__   0xFF                        // �ַ������޷������ֵ

#define __Signed_Int8_Min__     (-128)                      // 8λ�з���������СԤ����ֵ
#define __Signed_Int8_Max__     127                         // 8λ�з����������Ԥ����ֵ
#define __Unsigned_Int8_Min__   0                           // 8λ�޷���������СԤ����ֵ
#define __Unsigned_Int8_Max__   0xFF                        // 8λ�޷����������Ԥ����ֵ

#define __Signed_Int16_Min__    (-32768)                    // 16λ�з���������СԤ����ֵ
#define __Signed_Int16_Max__    32767                       // 16λ�з����������Ԥ����ֵ
#define __Unsigned_Int16_Min__  0                           // 16λ�޷���������СԤ����ֵ
#define __Unsigned_Int16_Max__  0xFFFF                      // 16λ�޷����������Ԥ����ֵ

#define __Signed_Int32_Min__    (-2147483647 - 1)           // 32λ�з���������СԤ����ֵ
#define __Signed_Int32_Max__    2147483647                  // 32λ�з����������Ԥ����ֵ
#define __Unsigned_Int32_Min__  0                           // 32λ�޷���������СԤ����ֵ
#define __Unsigned_Int32_Max__  0xFFFFFFFF                  // 32λ�޷����������Ԥ����ֵ

#define __Signed_Int64_Min__    (-9223372036854775807 - 1)  // 64λ�з���������СԤ����ֵ
#define __Signed_Int64_Max__    9223372036854775807         // 64λ�з����������Ԥ����ֵ
#define __Unsigned_Int64_Min__  0                           // 64λ�޷���������СԤ����ֵ
#define __Unsigned_Int64_Max__  0xFFFFFFFFFFFFFFFF          // 64λ�޷����������Ԥ����ֵ

#define __Double_Exp_Abs_Max__  308

#pragma region ��ָ���޶��������ְ汾��
#if __cplusplus >= 201103L
constexpr auto null = nullptr;
#else
#define null 0
#endif // __cplusplus >= 201103L
#pragma endregion

#ifdef __cplusplus  // C++���в�������

#define _Public      public:     // �����ù��з��ʿ��Ʒ��ض���
#define _Private     private:    // ������˽�з��ʿ��Ʒ��ض���
#define _Protected   protected:  // �����ñ������ʿ��Ʒ��ض���

#define _THIS        *this        // ������ʱ��ض���ؼ���

#define _abstract                    // �������ͱ�ǩ
#define _interface   _abstract class  // �ӿڶ���ؼ���

#define __C__       extern "C"      // C���Ա����

#define __TIANYU__  tianyu  // ���������ռ�

#define __REF__     &       // �������ͱ�ǩ
#define __PAR__     *&      // ָ����������

#define __P_To_R__  *       // ����ת����ָ�������
#define __R_To_P__  &       // ����ת�������á�ָ��
#define __R_To_V__          // ����ת�������á�ֵ
#define __V_To_R__          // ����ת����ֵ������

#define __Interface_Func__  // �ӿں�����ǩ
#define __Realize___Func__  // �ӿں���ʵ�ֱ�ǩ
#define __Override__Func__  // �������ر�ǩ

#else

#define true    1   // �����棺����C���ԵĲ����Ͳ����궨��
#define false   0   // �����٣�����C���ԵĲ����Ͳ����궨��

#endif // __cplusplus

#ifdef __cplusplus
__C__
{
#endif // __cplusplus

#define Align_8(size)	    (((size) + 7) & ~7)			// ���ݶ��룺8��������
#define Align_16(size)	    (((size) + 15) & ~15)		// ���ݶ��룺16��������
#define Align_32(size)	    (((size) + 31) & ~31)		// ���ݶ��룺32��������
#define Align_64(size)	    (((size) + 63) & ~63)		// ���ݶ��룺64��������
#define Align_128(size)	    (((size) + 127) & ~127)		// ���ݶ��룺128��������
// ���ݶ��룺2^n��������
#define Align(size, base)	(((size) + ((0x01 << (base)) - 1)) & ~((0x01 << (base)) - 1))

#define Mod_8(size)         ((size) & 7)						// ����ȡģ��8ȡģ
#define Mod_16(size)        ((size) & 15)						// ����ȡģ��16ȡģ
#define Mod_32(size)        ((size) & 31)						// ����ȡģ��32ȡģ
#define Mod_64(size)        ((size) & 63)						// ����ȡģ��64ȡģ
#define Mod_128(size)       ((size) & 127)						// ����ȡģ��128ȡģ
#define Mod(size, base)     ((size) & ((0x01 << (base)) - 1))	// ����ȡģ��2^nȡģ

#if (defined __linux) || (defined __unix)

#include<unistd.h>
// ��ȡ��ǰϵͳ����
#define getsystem()                                     "POSIX"
// ��ָ����ʽ���ַ�����ӡ��ָ�����ڴ�������
#define sprintf_t(buffer, buffer_count, formatter, ...) sprintf(buffer, formatter, ##__VA_ARGS__)
// �ַ�������
#define strcpy_t(dest, length, source)                  strcpy(dest, source)
// ��ȡ�ַ�������
#define strlen_t(array_pointer, max_length)             strlen(array_pointer)
#define sleep_t(time)                                   sleep(time/1000)           

#elif (defined _WIN32) || (defined _WIN64)

#include<Windows.h>
// ��ȡ��ǰϵͳ����
#define getsystem()                                     "Windows"
// ��ָ����ʽ���ַ�����ӡ��ָ�����ڴ�������
#define sprintf_t(buffer, buffer_count, formatter, ...) sprintf_s(buffer, buffer_count, formatter, ##__VA_ARGS__)
// �ַ�������
#define strcpy_t(dest, length, source)                  strcpy_s(dest, length, source)
// ��ȡ�ַ�������
#define strlen_t(array_pointer, max_length)             strnlen_s(array_pointer, max_length)
#define sleep_t(time)                                   sleep(time)

#else

// ��ȡ��ǰϵͳ����
#define getsystem()                                     "UnKnown"
// ��ָ����ʽ���ַ�����ӡ��ָ�����ڴ�������
#define sprintf_t(buffer, buffer_count, formatter, ...) printf("��֧�ֵĲ�����Not Support Operation��")
// �ַ�������
#define strcpy_t(dest, length, source)                  printf("��֧�ֵĲ�����Not Support Operation��")
// ��ȡ�ַ�������
#define strlen_t(array_pointer, max_length)             printf("��֧�ֵĲ�����Not Support Operation��")

#endif //(defined __linux) || (defined __unix)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TIANYUSL_C_CPP_DEFINE__