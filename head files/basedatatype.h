
#pragma once

#ifndef __TIANYUSL_C_CPP_BASEDATATYPE__
#define __TIANYUSL_C_CPP_BASEDATATYPE__

#include"define.h"

typedef       unsigned char uchar;      // �ض��壺�޷����ַ�
typedef         signed char sbyte;      // �ض��壺�з����ֽڣ�8λ������
typedef       unsigned char byte;       // �ض��壺�޷����ֽڣ�8λ������
typedef         signed char int8;       // �ض��壺�з���8λ����
typedef       unsigned char uint8;      // �ض��壺�޷���8λ����
typedef               short int16;      // �ض��壺�з���16λ����
typedef      unsigned short uint16;     // �ض��壺�޷���16λ����
typedef                 int int32;      // �ض��壺�з���32λ����
typedef        unsigned int uint32;     // �ض��壺�޷���32λ����
typedef           long long int64;      // �ض��壺�з���64λ����
typedef  unsigned long long uint64;     // �ض��壺�޷���64λ����
typedef        void __PTR__ object;     // �ض��壺��������
typedef        char __PTR__ string;     // �ض��壺�ַ�������
typedef                char error;      // �ض��壺���������ͣ�8λ������

#ifndef __cplusplus
typedef unsigned char bool;     // ����C���ԵĲ������ͽṹ����
#endif // !__cplusplus


#define __C_STRUCT_STRING_INVAILD_LENGTH__  -1
#define __C_STRUCT_STRING_MAX_LENGTH__      65536

#ifdef __cplusplus
__C__
{
#endif

__Predefine__ struct c_struct_string;

typedef int32   __VAR__ (__PTR__ c_struct_string_getlength)
(
    struct c_struct_string  __PTR__ str
);
typedef char    __PTR__ (__PTR__ c_struct_string_getstring)
(
    struct c_struct_string  __PTR__ str
);
typedef bool   __VAR__ (__PTR__ c_struct_string_setstring)
(
    struct c_struct_string  __PTR__ str,
    char                    __PTR__ cstr,
    int32                   __VAR__ length
);
typedef bool   __VAR__ (__PTR__ c_struct_string_isnull)
(
    struct c_struct_string  __PTR__ str
);

typedef struct c_struct_string
{
    c_struct_string_getlength   __VAR__ Length;
    c_struct_string_getstring   __VAR__ String;
    c_struct_string_setstring   __VAR__ Set;
    c_struct_string_isnull      __VAR__ IsNull;
}CStructString;

CStructString __PTR__ CreateCStructString();
CStructString __PTR__ CreateCStructStringFromCSS
(
    CStructString __PTR__ cstr
);
void          __VAR__ DestroyCStructString
(
    CStructString __PTR__ cstr
);
CStructString __PTR__ CreateCStructStringFromChars
(
    char    __PTR__ str,
    int32   __VAR__ length
);
CStructString __PTR__ CreateCStructStringFromCharA
(
    char    __VAR__ str[],
    int32   __VAR__ length
);
CStructString __PTR__ CreateCStructStringFromCharsIndex
(
    char    __PTR__ str,
    int32   __VAR__ index,
    int32   __VAR__ length
);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#define __EXCEPTION__ ty_exceptions

namespace __TIANYU__
{
    //ͨ�ö������
    class Object
    {
        // ���캯��
        // ͨ�ö�����๹�캯��
        _Public obscure Object() {}
        // ��������
        // ͨ�ö��������������
        _Public virtual ~Object(){}

        // ���غ���
        // ��ȡһ��ֵ����ָʾָ�������뵱ǰ�����Ƿ����
        // ������obj����ָ���Ķ���
        // ����ֵ��true-ָ�������뵱ǰ������� | false-ָ�������뵱ǰ�������
        _Public virtual bool		__VAR__ Equals
        (
            __IN_Param__ Object __REF__ obj		// ָ���ıȽ϶���
        )
        {
            // ͨ����ַ���бȽ�
            return (uint64)this == (uint64)(__R_To_P__ obj);
        }
        // ���غ���
        // ��ȡ��ǰ����Ĺ�ϣֵ
        // ����ֵ�����ص�ǰ����Ĺ�ϣֵ
        _Public virtual uint64	__VAR__	GetHashCode()
        {
            return (uint64)this;
        }
    };

    // �����쳣����
    class Exception : public Object
    {
        // ��̬����
        // ������루�޴���
        _Public static const error __VAR__ Exception_NoError;

        // �쳣����
        _Protected           error __VAR__ Error;

        // ���캯��
        // �����쳣���๹�캯����Ĭ���޴���
        _Public obscure  Exception()
            : Object(),
            Error(Exception_NoError)
        {

        }
        // ���캯��
        // �����쳣���๹�캯��
        // ������err��error�����������
        _Public explicit Exception
        (
            __IN_Param__ error __VAR__ err
        )
            : Object(),
            Error(err)
        {

        }

        // ��������
        // �����쳣������������
        _Public virtual ~Exception()
        {
            // �����쳣���������������������Ϊ
        }

        // ����������
        // ��ȡ��ǰ����Ĵ������
        // ����ֵ���������
        _Public virtual error __VAR__ GetError()
        {
            return Error;
        }
    };
    const error __VAR__ Exception::Exception_NoError = 0x00;   // �����쳣����Ĭ�ϲ������޴����ֶ�

    //template<typename _T>
    //__Predefine__ class SmartPointer;   // ����ָ��
    //template<typename _T>
    //__Predefine__ class ConstPointer;   // ��ָ̬��

    __Predefine__ class Char;       // �з����ַ����Ͱ�װ��
    __Predefine__ class UChar;      // �޷����ַ����Ͱ�װ��
    __Predefine__ class Boolean;    // �������Ͱ�װ��
    __Predefine__ class Byte;       // �޷����ֽ����Ͱ�װ��
    __Predefine__ class SByte;      // �з����ֽ����Ͱ�װ��
    __Predefine__ class Short;      // �з��Ŷ��������Ͱ�װ��
    __Predefine__ class UShort;     // �޷��Ŷ��������Ͱ�װ��
    __Predefine__ class Int;        // �з����������Ͱ�װ��
    __Predefine__ class UInt;       // �޷����������Ͱ�װ��
    __Predefine__ class Long;       // �з��ų��������Ͱ�װ��
    __Predefine__ class ULong;      // �޷��ų��������Ͱ�װ��

    __Predefine__ class String;     // �ַ�����

#if __cplusplus >= 201103L
    using Int8      = SByte;    // ������8λ�з���������װ��
    using UInt8     = Byte;     // ������8λ�޷���������װ��
    using Int16     = Short;    // ������16λ�з���������װ��
    using UInt16    = UShort;   // ������16λ�޷���������װ��
    using Int32     = Int;      // ������32λ�з���������װ��
    using UInt32    = UInt;     // ������32λ�޷���������װ��
    using Int64     = Long;     // ������64λ�з���������װ��
    using UInt64    = ULong;    // ������64λ�޷���������װ��
#else
	typedef SByte	Int8;		// ������8λ�з���������װ��
	typedef Byte	UInt8;		// ������8λ�޷���������װ��
	typedef Short	Int16;		// ������16λ�з���������װ��
	typedef UShort	UInt16;		// ������16λ�޷���������װ��
	typedef Int		Int32;      // ������32λ�з���������װ��
	typedef UInt	UInt32;     // ������32λ�޷���������װ��
	typedef Long	Int64;		// ������64λ�з���������װ��
	typedef ULong	UInt64;		// ������64λ�޷���������װ��
#endif // __cplusplus >= 201103L

    // �������ݽṹ�����
    //template<typename _Elem>
    //__Predefine__ class Array;              // ����
    template<typename _Elem>    
    __Predefine__ class Stack;              // ��ջ
    template<typename _Elem>
    __Predefine__ class Queue;              // ����
    //template<typename _Elem>
    //__Predefine__ class ArrayList;          // ��������
    //template<typename _Elem>                
    //__Predefine__ class LinkedList;         // ��ʽ����
    //template<typename _Elem>
    //__Predefine__ class List;               // ����
    //template<typename _Key, typename _Val>
    //__Predefine__ class SortedList;         // ��������
    //template<typename _Key, typename _Val>
    //__Predefine__ class Dictionary;         // �ֵ�
    //template<typename _Key, typename _Val>
    //__Predefine__ class HashTable;          // ��ϣ��

    template<typename Key, typename Value>
    class KeyValuePair final
    {
        _Public Key __PTR__ m_Key;
        _Public Value __PTR__ m_Value;

        _Public KeyValuePair() :
            m_Key(null),
            m_Value(null)
        {
        }
    };
}
#endif // __cplusplus
#endif // __TIANYUSL_C_CPP_BASEDATATYPE__