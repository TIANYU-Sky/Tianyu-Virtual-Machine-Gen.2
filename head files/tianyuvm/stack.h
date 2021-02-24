/**
 * 用于天宇虚拟机系统的堆栈数据结构
 * 包含：字符、字符串以及void*类型
*/
#pragma once

#ifndef __TIANYUVM_C_CPP_STACK__
#define __TIANYUVM_C_CPP_STACK__

#include"define.h"
#include"basedatatype.h"

#ifdef __cplusplus
__C__
{
#endif

/**
 * 字符堆栈
*/
// 字符堆栈类型 预定义
__Predefine__ struct charstack;
// 字符堆栈节点类型 预定义
__Predefine__ struct charstacknode;

// 字符堆栈操作函数指针-入栈
typedef int32 __VAR__(__PTR__ charstackfun_push) (struct charstack __PTR__, char);
// 字符堆栈操作函数指针-出栈
typedef char  __VAR__(__PTR__ charstackfun_pop)  (struct charstack __PTR__);
// 字符堆栈操作函数指针-获取栈尾（不出栈）
typedef char  __VAR__(__PTR__ charstackfun_peek) (struct charstack __PTR__);
// 字符堆栈操作函数指针-清空堆栈
typedef void  __VAR__(__PTR__ charstackfun_clear)(struct charstack __PTR__);

// 字符堆栈节点类型结构体
typedef struct charstacknode
{
    char                 __VAR__ Datas;
    struct charstacknode __PTR__ Next;
} CharStackNode;
// 字符堆栈类型结构体
typedef struct charstack
{
    int32         __VAR__ Count;       // 获取一个数用于指示当前堆栈中所包含的元素个数
    CharStackNode __VAR__ _Top;        // 获的一个指针指向堆栈的顶部

    charstackfun_push   __VAR__ Push;  // 获取一个函数指针指向堆栈的入栈方法
    charstackfun_pop    __VAR__ Pop;   // 获取一个函数指针指向堆栈的出栈方法
    charstackfun_clear  __VAR__ Clear; // 获取一个函数指针指向堆栈的清空方法
    charstackfun_peek   __VAR__ Peek;
} CharStack;

// 创建字符堆栈方法
CharStack __PTR__ CreateCharStack();
// 销毁字符堆栈方法
void      __VAR__ DestroyCharStack(CharStack __PTR__ stack);

/**
 * 字符串堆栈
*/
// 字符串堆栈类型 预定义
__Predefine__ struct stringstack;
// 字符串堆栈节点类型 预定义
__Predefine__ struct stringstacknode;

// 字符串堆栈操作函数指针-入栈
typedef int32 __VAR__(__PTR__ stringstackfun_push) (struct stringstack __PTR__, char __PTR__);
// 字符串堆栈操作函数指针-出栈
typedef char  __PTR__(__PTR__ stringstackfun_pop)  (struct stringstack __PTR__);
// 字符串堆栈操作函数指针-获取栈尾（不出栈）
typedef char  __PTR__(__PTR__ stringstackfun_peek) (struct stringstack __PTR__);
// 字符串堆栈操作函数指针-清空堆栈
typedef void  __VAR__(__PTR__ stringstackfun_clear)(struct stringstack __PTR__);

// 字符串堆栈节点类型结构体
typedef struct stringstacknode
{
    char                   __PTR__ Datas;
    struct stringstacknode __PTR__ Next;
} StringStackNode;
// 字符串堆栈类型结构体
typedef struct stringstack
{
    int32           __VAR__ Count;          // 获取一个数用于指示当前堆栈中所包含的元素个数
    StringStackNode __VAR__ _Top;           // 获的一个指针指向堆栈的顶部

    stringstackfun_push     __VAR__ Push;   // 获取一个函数指针指向堆栈的入栈方法
    stringstackfun_pop      __VAR__ Pop;    // 获取一个函数指针指向堆栈的出栈方法
    stringstackfun_clear    __VAR__ Clear;  // 获取一个函数指针指向堆栈的清空方法
    stringstackfun_peek     __VAR__ Peek;
} StringStack;

// 创建字符串堆栈方法
StringStack __PTR__ CreateStringStack();
// 销毁字符串堆栈方法
void        __VAR__ DestroyStringStack(StringStack __PTR__ stack);

/**
 * 任意类型堆栈
*/
// 对象堆栈类型 预定义
__Predefine__ struct stack;
// 对象堆栈节点类型 预定义
__Predefine__ struct stacknode;

// 对象堆栈操作函数指针-入栈
typedef int32  __VAR__(__PTR__ stackfun_push) (struct stack __PTR__, object __VAR__);
// 对象堆栈操作函数指针-出栈
typedef object __VAR__(__PTR__ stackfun_pop)  (struct stack __PTR__);
// 对象堆栈操作函数指针-获取栈尾（不出栈）
typedef object __VAR__(__PTR__ stackfun_peek) (struct stack __PTR__);
// 对象堆栈操作函数指针-清空堆栈
typedef void   __VAR__(__PTR__ stackfun_clear)(struct stack __PTR__);

// 对象堆栈节点类型结构体
typedef struct stacknode
{
    object           __VAR__ Datas;
    struct stacknode __PTR__ Next;
} StackNode;
// 对象堆栈类型结构体
typedef struct stack
{
    int32     __VAR__ Count;       // 获取一个数用于指示当前堆栈中所包含的元素个数
    StackNode __VAR__ _Top;        // 获的一个指针指向堆栈的顶部

    stackfun_push   __VAR__ Push;  // 获取一个函数指针指向堆栈的入栈方法
    stackfun_pop    __VAR__ Pop;   // 获取一个函数指针指向堆栈的出栈方法
    stackfun_clear  __VAR__ Clear; // 获取一个函数指针指向堆栈的清空方法
    stackfun_peek   __VAR__ Peek;
} Stack;

// 创建对象堆栈方法
Stack __PTR__ CreateStack();
// 销毁对象堆栈方法
void  __VAR__ DestroyStack(Stack __PTR__ stack);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_STACK__