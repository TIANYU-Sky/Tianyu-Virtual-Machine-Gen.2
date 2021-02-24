
#pragma once

#ifndef __TIANYUSL_C_CPP_BASEDATATYPE__
#define __TIANYUSL_C_CPP_BASEDATATYPE__

#include"define.h"

typedef       unsigned char uchar;      // 重定义：无符号字符
typedef         signed char sbyte;      // 重定义：有符号字节（8位整数）
typedef       unsigned char byte;       // 重定义：无符号字节（8位整数）
typedef         signed char int8;       // 重定义：有符号8位整数
typedef       unsigned char uint8;      // 重定义：无符号8位整数
typedef               short int16;      // 重定义：有符号16位整数
typedef      unsigned short uint16;     // 重定义：无符号16位整数
typedef                 int int32;      // 重定义：有符号32位整数
typedef        unsigned int uint32;     // 重定义：无符号32位整数
typedef           long long int64;      // 重定义：有符号64位整数
typedef  unsigned long long uint64;     // 重定义：无符号64位整数
typedef        void __PTR__ object;     // 重定义：任意类型
typedef        char __PTR__ string;     // 重定义：字符串类型
typedef                char error;      // 重定义：错误定义类型（8位整数）

#ifndef __cplusplus
typedef unsigned char bool;     // 用于C语言的布尔类型结构定义
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
    //通用对象基类
    class Object
    {
        // 构造函数
        // 通用对象基类构造函数
        _Public obscure Object() {}
        // 析构函数
        // 通用对象基类析构函数
        _Public virtual ~Object(){}

        // 重载函数
        // 获取一个值用于指示指定对象与当前对象是否相等
        // 参数（obj）：指定的对象
        // 返回值：true-指定对象与当前对象相等 | false-指定对象与当前对象不相等
        _Public virtual bool		__VAR__ Equals
        (
            __IN_Param__ Object __REF__ obj		// 指定的比较对象
        )
        {
            // 通过地址进行比较
            return (uint64)this == (uint64)(__R_To_P__ obj);
        }
        // 重载函数
        // 获取当前对象的哈希值
        // 返回值：返回当前对象的哈希值
        _Public virtual uint64	__VAR__	GetHashCode()
        {
            return (uint64)this;
        }
    };

    // 天宇异常基类
    class Exception : public Object
    {
        // 静态参数
        // 错误代码（无错误）
        _Public static const error __VAR__ Exception_NoError;

        // 异常代码
        _Protected           error __VAR__ Error;

        // 构造函数
        // 天宇异常基类构造函数（默认无错误）
        _Public obscure  Exception()
            : Object(),
            Error(Exception_NoError)
        {

        }
        // 构造函数
        // 天宇异常基类构造函数
        // 参数（err：error）：错误代码
        _Public explicit Exception
        (
            __IN_Param__ error __VAR__ err
        )
            : Object(),
            Error(err)
        {

        }

        // 析构函数
        // 天宇异常基类析构函数
        _Public virtual ~Exception()
        {
            // 天宇异常基类析构函数无需具体行为
        }

        // 访问器函数
        // 获取当前错误的错误代码
        // 返回值：错误代码
        _Public virtual error __VAR__ GetError()
        {
            return Error;
        }
    };
    const error __VAR__ Exception::Exception_NoError = 0x00;   // 天宇异常基类默认参数：无错误字段

    //template<typename _T>
    //__Predefine__ class SmartPointer;   // 智能指针
    //template<typename _T>
    //__Predefine__ class ConstPointer;   // 静态指针

    __Predefine__ class Char;       // 有符号字符类型包装类
    __Predefine__ class UChar;      // 无符号字符类型包装类
    __Predefine__ class Boolean;    // 布尔类型包装类
    __Predefine__ class Byte;       // 无符号字节类型包装类
    __Predefine__ class SByte;      // 有符号字节类型包装类
    __Predefine__ class Short;      // 有符号短整数类型包装类
    __Predefine__ class UShort;     // 无符号短整数类型包装类
    __Predefine__ class Int;        // 有符号整数类型包装类
    __Predefine__ class UInt;       // 无符号整数类型包装类
    __Predefine__ class Long;       // 有符号长整数类型包装类
    __Predefine__ class ULong;      // 无符号长整数类型包装类

    __Predefine__ class String;     // 字符串类

#if __cplusplus >= 201103L
    using Int8      = SByte;    // 别名：8位有符号整数包装类
    using UInt8     = Byte;     // 别名：8位无符号整数包装类
    using Int16     = Short;    // 别名：16位有符号整数包装类
    using UInt16    = UShort;   // 别名：16位无符号整数包装类
    using Int32     = Int;      // 别名：32位有符号整数包装类
    using UInt32    = UInt;     // 别名：32位无符号整数包装类
    using Int64     = Long;     // 别名：64位有符号整数包装类
    using UInt64    = ULong;    // 别名：64位无符号整数包装类
#else
	typedef SByte	Int8;		// 别名：8位有符号整数包装类
	typedef Byte	UInt8;		// 别名：8位无符号整数包装类
	typedef Short	Int16;		// 别名：16位有符号整数包装类
	typedef UShort	UInt16;		// 别名：16位无符号整数包装类
	typedef Int		Int32;      // 别名：32位有符号整数包装类
	typedef UInt	UInt32;     // 别名：32位无符号整数包装类
	typedef Long	Int64;		// 别名：64位有符号整数包装类
	typedef ULong	UInt64;		// 别名：64位无符号整数包装类
#endif // __cplusplus >= 201103L

    // 基本数据结构定义块
    //template<typename _Elem>
    //__Predefine__ class Array;              // 数组
    template<typename _Elem>    
    __Predefine__ class Stack;              // 堆栈
    template<typename _Elem>
    __Predefine__ class Queue;              // 队列
    //template<typename _Elem>
    //__Predefine__ class ArrayList;          // 数组链表
    //template<typename _Elem>                
    //__Predefine__ class LinkedList;         // 链式链表
    //template<typename _Elem>
    //__Predefine__ class List;               // 链表
    //template<typename _Key, typename _Val>
    //__Predefine__ class SortedList;         // 排序链表
    //template<typename _Key, typename _Val>
    //__Predefine__ class Dictionary;         // 字典
    //template<typename _Key, typename _Val>
    //__Predefine__ class HashTable;          // 哈希表

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