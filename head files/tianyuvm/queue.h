/**
 * 用于天宇虚拟机系统的队列数据结构
 * 包含：字符、字符串以及void*类型
*/

#pragma once

#ifndef __TIANYUVM_C_CPP_QUEUE__
#define __TIANYUVM_C_CPP_QUEUE__

#include"../define.h"
#include"../basedatatype.h"

#ifdef __cplusplus
__C__
{
#endif

/**
 * 字符队列
*/
// 字符队列类型 预定义
__Predefine__ struct charqueue;    
// 字符队列节点类型 预定义
__Predefine__ struct charqueuenode;

// 字符队列操作函数指针-入队
typedef int32 __VAR__ (__PTR__ charqueuefun_enqueue)(struct charqueue __PTR__, char);
// 字符队列操作函数指针-出队
typedef char  __VAR__ (__PTR__ charqueuefun_dequeue)(struct charqueue __PTR__);
// 字符队列操作函数指针-清空队列
typedef void  __VAR__ (__PTR__ charqueuefun_clear)  (struct charqueue __PTR__);
// 字符队列操作函数指针-查看队列头元素（不出队）
typedef char  __VAR__ (__PTR__ charqueuefun_peek)   (struct charqueue __PTR__);

// 字符队列节点类型结构体
typedef struct charqueuenode
{
    char                 __VAR__ Datas;
    struct charqueuenode __PTR__ Next;
} CharQueueNode;
// 字符队列类型结构体
typedef struct charqueue
{
    int32         __VAR__ Count;            // 获取一个数用于指示当前队列中所包含的元素个数
    CharQueueNode __VAR__ _Head;            // 获的一个指针指向队列的头部
    CharQueueNode __PTR__ _End;             // 获得一个指针指向队列的尾部

    charqueuefun_enqueue __VAR__ Enqueue;   // 获取一个函数指针指向队列的入队方法
    charqueuefun_dequeue __VAR__ Dequeue;   // 获取一个函数指针指向队列的出队方法
    charqueuefun_clear   __VAR__ Clear;     // 获取一个函数指针指向队列的清空方法
    charqueuefun_peek    __VAR__ Peek;      // 获取一个函数指针指向队列的队头获取方法
} CharQueue;

// 创建字符队列方法
CharQueue __PTR__ CreateCharQueue();
// 销毁字符队列方法
void      __VAR__ DestroyCharQueue(CharQueue __PTR__ queue);
 
/**
 * 字符串队列
*/
// 字符串队列类型 预定义
__Predefine__ struct stringqueue;
// 字符串队列节点类型 预定义
__Predefine__ struct stringqueuenode;

// 字符串队列操作函数指针-入队
typedef int32 __VAR__(__PTR__ stringqueuefun_enqueue)(struct stringqueue __PTR__, char __PTR__);
// 字符串队列操作函数指针-出队
typedef char  __PTR__(__PTR__ stringqueuefun_dequeue)(struct stringqueue __PTR__);
// 字符串队列操作函数指针-清空队列
typedef void  __VAR__(__PTR__ stringqueuefun_clear)  (struct stringqueue __PTR__);
// 字符串队列操作函数指针-查看队列头元素（不出队）
typedef char  __PTR__(__PTR__ stringqueuefun_peek)   (struct stringqueue __PTR__);

// 字符串队列节点类型结构体
typedef struct stringqueuenode
{
    char                   __PTR__ Datas;
    struct stringqueuenode __PTR__ Next;
} StringQueueNode;
// 字符串队列类型结构体
typedef struct stringqueue
{
    int32           __VAR__ Count;          // 获取一个数用于指示当前队列中所包含的元素个数
    StringQueueNode __VAR__ _Head;          // 获的一个指针指向队列的头部
    StringQueueNode __PTR__ _End;           // 获得一个指针指向队列的尾部

    stringqueuefun_enqueue __VAR__ Enqueue; // 获取一个函数指针指向队列的入队方法
    stringqueuefun_dequeue __VAR__ Dequeue; // 获取一个函数指针指向队列的出队方法
    stringqueuefun_clear   __VAR__ Clear;   // 获取一个函数指针指向队列的清空方法
    stringqueuefun_peek    __VAR__ Peek;    // 获取一个函数指针指向队列的队头获取方法
} StringQueue;

// 创建字符串队列方法
StringQueue __PTR__ CreateStringQueue();
// 销毁字符串队列方法
void        __VAR__ DestroyStringQueue(StringQueue __PTR__ queue);

/**
 * 任意类型队列
*/
// 对象队列类型 预定义
__Predefine__ struct queue;
// 对象队列节点类型 预定义
__Predefine__ struct queuenode;

// 对象队列操作函数指针-入队
typedef int32  __VAR__(__PTR__ queuefun_enqueue)(struct queue __PTR__, object __VAR__);
// 对象队列操作函数指针-出队
typedef object __VAR__(__PTR__ queuefun_dequeue)(struct queue __PTR__);
// 对象队列操作函数指针-清空队列
typedef void   __VAR__(__PTR__ queuefun_clear)  (struct queue __PTR__);
// 对象队列操作函数指针-查看队列头元素（不出队）
typedef object __VAR__(__PTR__ queuefun_peek)   (struct queue __PTR__);

// 对象队列节点类型结构体
typedef struct queuenode
{
    object           __VAR__ Datas;
    struct queuenode __PTR__ Next;
} QueueNode;
// 对象队列类型结构体
typedef struct queue
{
    int32     __VAR__ Count;            // 获取一个数用于指示当前队列中所包含的元素个数
    QueueNode __VAR__ _Head;            // 获的一个指针指向队列的头部
    QueueNode __PTR__ _End;             // 获得一个指针指向队列的尾部

    queuefun_enqueue __VAR__ Enqueue;   // 获取一个函数指针指向队列的入队方法
    queuefun_dequeue __VAR__ Dequeue;   // 获取一个函数指针指向队列的出队方法
    queuefun_clear   __VAR__ Clear;     // 获取一个函数指针指向队列的清空方法
    queuefun_peek    __VAR__ Peek;      // 获取一个函数指针指向队列的队头获取方法
} Queue;

// 创建对象队列方法
Queue __PTR__ CreateQueue();
// 销毁对象队列方法
void  __VAR__ DestroyQueue(Queue __PTR__ queue);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_QUEUE__