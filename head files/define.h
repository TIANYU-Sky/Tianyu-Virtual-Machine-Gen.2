
#pragma once

#ifndef __TIANYUSL_C_CPP_DEFINE__
#define __TIANYUSL_C_CPP_DEFINE__

#define __Predefine__   // 前向声明标签

#define __VAR__     // 值类型标签
#define __PTR__ *   // 指针类型标签

#define __P_To_V__  *   // 类型转换：指针→值
#define __V_To_P__  &   // 类型转换：值→指针

#define __IN_Param__    // 输入参数标签
#define __OT_Param__    // 输出参数标签
#define __IO_Param__    // 输入输出参数标签

#define __Request___    // 请求方法标签
#define __Response__    // 回复方法标签

#define obscure         // 模糊定义标签                

#define __Signed_Char_Min__     (-128)                      // 字符类型有符号最小值
#define __Signed_Char_Max__     127                         // 字符类型有符号最大值
#define __Unsigned_Char_Min__   0                           // 字符类型无符号最小值
#define __Unsigned_Char_Max__   0xFF                        // 字符类型无符号最大值

#define __Signed_Int8_Min__     (-128)                      // 8位有符号整数最小预定义值
#define __Signed_Int8_Max__     127                         // 8位有符号整数最大预定义值
#define __Unsigned_Int8_Min__   0                           // 8位无符号整数最小预定义值
#define __Unsigned_Int8_Max__   0xFF                        // 8位无符号整数最大预定义值

#define __Signed_Int16_Min__    (-32768)                    // 16位有符号整数最小预定义值
#define __Signed_Int16_Max__    32767                       // 16位有符号整数最大预定义值
#define __Unsigned_Int16_Min__  0                           // 16位无符号整数最小预定义值
#define __Unsigned_Int16_Max__  0xFFFF                      // 16位无符号整数最大预定义值

#define __Signed_Int32_Min__    (-2147483647 - 1)           // 32位有符号整数最小预定义值
#define __Signed_Int32_Max__    2147483647                  // 32位有符号整数最大预定义值
#define __Unsigned_Int32_Min__  0                           // 32位无符号整数最小预定义值
#define __Unsigned_Int32_Max__  0xFFFFFFFF                  // 32位无符号整数最大预定义值

#define __Signed_Int64_Min__    (-9223372036854775807 - 1)  // 64位有符号整数最小预定义值
#define __Signed_Int64_Max__    9223372036854775807         // 64位有符号整数最大预定义值
#define __Unsigned_Int64_Min__  0                           // 64位无符号整数最小预定义值
#define __Unsigned_Int64_Max__  0xFFFFFFFFFFFFFFFF          // 64位无符号整数最大预定义值

#define __Double_Exp_Abs_Max__  308

#pragma region 空指针限定符（区分版本）
#if __cplusplus >= 201103L
constexpr auto null = nullptr;
#else
#define null 0
#endif // __cplusplus >= 201103L
#pragma endregion

#ifdef __cplusplus  // C++特有操作定义

#define _Public      public:     // 定义用公有访问控制符重定义
#define _Private     private:    // 定义用私有访问控制符重定义
#define _Protected   protected:  // 定义用保护访问控制符重定义

#define _THIS        *this        // 定义访问本地对象关键字

#define _abstract                    // 抽象类型标签
#define _interface   _abstract class  // 接口定义关键字

#define __C__       extern "C"      // C语言编译块

#define __TIANYU__  tianyu  // 天宇命名空间

#define __REF__     &       // 引用类型标签
#define __PAR__     *&      // 指针引用类型

#define __P_To_R__  *       // 类型转换：指针→引用
#define __R_To_P__  &       // 类型转换：引用→指针
#define __R_To_V__          // 类型转换：引用→值
#define __V_To_R__          // 类型转换：值→引用

#define __Interface_Func__  // 接口函数标签
#define __Realize___Func__  // 接口函数实现标签
#define __Override__Func__  // 函数重载标签

#else

#define true    1   // 布尔真：用于C语言的布尔型操作宏定义
#define false   0   // 布尔假：用于C语言的布尔型操作宏定义

#endif // __cplusplus

#ifdef __cplusplus
__C__
{
#endif // __cplusplus

#define Align_8(size)	    (((size) + 7) & ~7)			// 数据对齐：8倍数对齐
#define Align_16(size)	    (((size) + 15) & ~15)		// 数据对齐：16倍数对齐
#define Align_32(size)	    (((size) + 31) & ~31)		// 数据对齐：32倍数对齐
#define Align_64(size)	    (((size) + 63) & ~63)		// 数据对齐：64倍数对齐
#define Align_128(size)	    (((size) + 127) & ~127)		// 数据对齐：128倍数对齐
// 数据对齐：2^n倍数对齐
#define Align(size, base)	(((size) + ((0x01 << (base)) - 1)) & ~((0x01 << (base)) - 1))

#define Mod_8(size)         ((size) & 7)						// 数据取模：8取模
#define Mod_16(size)        ((size) & 15)						// 数据取模：16取模
#define Mod_32(size)        ((size) & 31)						// 数据取模：32取模
#define Mod_64(size)        ((size) & 63)						// 数据取模：64取模
#define Mod_128(size)       ((size) & 127)						// 数据取模：128取模
#define Mod(size, base)     ((size) & ((0x01 << (base)) - 1))	// 数据取模：2^n取模

#if (defined __linux) || (defined __unix)

#include<unistd.h>
// 获取当前系统类型
#define getsystem()                                     "POSIX"
// 将指定格式的字符串打印至指定的内存数组中
#define sprintf_t(buffer, buffer_count, formatter, ...) sprintf(buffer, formatter, ##__VA_ARGS__)
// 字符串拷贝
#define strcpy_t(dest, length, source)                  strcpy(dest, source)
// 获取字符串长度
#define strlen_t(array_pointer, max_length)             strlen(array_pointer)
#define sleep_t(time)                                   sleep(time/1000)           

#elif (defined _WIN32) || (defined _WIN64)

#include<Windows.h>
// 获取当前系统类型
#define getsystem()                                     "Windows"
// 将指定格式的字符串打印至指定的内存数组中
#define sprintf_t(buffer, buffer_count, formatter, ...) sprintf_s(buffer, buffer_count, formatter, ##__VA_ARGS__)
// 字符串拷贝
#define strcpy_t(dest, length, source)                  strcpy_s(dest, length, source)
// 获取字符串长度
#define strlen_t(array_pointer, max_length)             strnlen_s(array_pointer, max_length)
#define sleep_t(time)                                   sleep(time)

#else

// 获取当前系统类型
#define getsystem()                                     "UnKnown"
// 将指定格式的字符串打印至指定的内存数组中
#define sprintf_t(buffer, buffer_count, formatter, ...) printf("不支持的操作（Not Support Operation）")
// 字符串拷贝
#define strcpy_t(dest, length, source)                  printf("不支持的操作（Not Support Operation）")
// 获取字符串长度
#define strlen_t(array_pointer, max_length)             printf("不支持的操作（Not Support Operation）")

#endif //(defined __linux) || (defined __unix)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __TIANYUSL_C_CPP_DEFINE__