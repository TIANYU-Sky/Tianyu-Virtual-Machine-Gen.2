/**
 * �������������ϵͳ�Ķ������ݽṹ
 * �������ַ����ַ����Լ�void*����
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
 * �ַ�����
*/
// �ַ��������� Ԥ����
__Predefine__ struct charqueue;    
// �ַ����нڵ����� Ԥ����
__Predefine__ struct charqueuenode;

// �ַ����в�������ָ��-���
typedef int32 __VAR__ (__PTR__ charqueuefun_enqueue)(struct charqueue __PTR__, char);
// �ַ����в�������ָ��-����
typedef char  __VAR__ (__PTR__ charqueuefun_dequeue)(struct charqueue __PTR__);
// �ַ����в�������ָ��-��ն���
typedef void  __VAR__ (__PTR__ charqueuefun_clear)  (struct charqueue __PTR__);
// �ַ����в�������ָ��-�鿴����ͷԪ�أ������ӣ�
typedef char  __VAR__ (__PTR__ charqueuefun_peek)   (struct charqueue __PTR__);

// �ַ����нڵ����ͽṹ��
typedef struct charqueuenode
{
    char                 __VAR__ Datas;
    struct charqueuenode __PTR__ Next;
} CharQueueNode;
// �ַ��������ͽṹ��
typedef struct charqueue
{
    int32         __VAR__ Count;            // ��ȡһ��������ָʾ��ǰ��������������Ԫ�ظ���
    CharQueueNode __VAR__ _Head;            // ���һ��ָ��ָ����е�ͷ��
    CharQueueNode __PTR__ _End;             // ���һ��ָ��ָ����е�β��

    charqueuefun_enqueue __VAR__ Enqueue;   // ��ȡһ������ָ��ָ����е���ӷ���
    charqueuefun_dequeue __VAR__ Dequeue;   // ��ȡһ������ָ��ָ����еĳ��ӷ���
    charqueuefun_clear   __VAR__ Clear;     // ��ȡһ������ָ��ָ����е���շ���
    charqueuefun_peek    __VAR__ Peek;      // ��ȡһ������ָ��ָ����еĶ�ͷ��ȡ����
} CharQueue;

// �����ַ����з���
CharQueue __PTR__ CreateCharQueue();
// �����ַ����з���
void      __VAR__ DestroyCharQueue(CharQueue __PTR__ queue);
 
/**
 * �ַ�������
*/
// �ַ����������� Ԥ����
__Predefine__ struct stringqueue;
// �ַ������нڵ����� Ԥ����
__Predefine__ struct stringqueuenode;

// �ַ������в�������ָ��-���
typedef int32 __VAR__(__PTR__ stringqueuefun_enqueue)(struct stringqueue __PTR__, char __PTR__);
// �ַ������в�������ָ��-����
typedef char  __PTR__(__PTR__ stringqueuefun_dequeue)(struct stringqueue __PTR__);
// �ַ������в�������ָ��-��ն���
typedef void  __VAR__(__PTR__ stringqueuefun_clear)  (struct stringqueue __PTR__);
// �ַ������в�������ָ��-�鿴����ͷԪ�أ������ӣ�
typedef char  __PTR__(__PTR__ stringqueuefun_peek)   (struct stringqueue __PTR__);

// �ַ������нڵ����ͽṹ��
typedef struct stringqueuenode
{
    char                   __PTR__ Datas;
    struct stringqueuenode __PTR__ Next;
} StringQueueNode;
// �ַ����������ͽṹ��
typedef struct stringqueue
{
    int32           __VAR__ Count;          // ��ȡһ��������ָʾ��ǰ��������������Ԫ�ظ���
    StringQueueNode __VAR__ _Head;          // ���һ��ָ��ָ����е�ͷ��
    StringQueueNode __PTR__ _End;           // ���һ��ָ��ָ����е�β��

    stringqueuefun_enqueue __VAR__ Enqueue; // ��ȡһ������ָ��ָ����е���ӷ���
    stringqueuefun_dequeue __VAR__ Dequeue; // ��ȡһ������ָ��ָ����еĳ��ӷ���
    stringqueuefun_clear   __VAR__ Clear;   // ��ȡһ������ָ��ָ����е���շ���
    stringqueuefun_peek    __VAR__ Peek;    // ��ȡһ������ָ��ָ����еĶ�ͷ��ȡ����
} StringQueue;

// �����ַ������з���
StringQueue __PTR__ CreateStringQueue();
// �����ַ������з���
void        __VAR__ DestroyStringQueue(StringQueue __PTR__ queue);

/**
 * �������Ͷ���
*/
// ����������� Ԥ����
__Predefine__ struct queue;
// ������нڵ����� Ԥ����
__Predefine__ struct queuenode;

// ������в�������ָ��-���
typedef int32  __VAR__(__PTR__ queuefun_enqueue)(struct queue __PTR__, object __VAR__);
// ������в�������ָ��-����
typedef object __VAR__(__PTR__ queuefun_dequeue)(struct queue __PTR__);
// ������в�������ָ��-��ն���
typedef void   __VAR__(__PTR__ queuefun_clear)  (struct queue __PTR__);
// ������в�������ָ��-�鿴����ͷԪ�أ������ӣ�
typedef object __VAR__(__PTR__ queuefun_peek)   (struct queue __PTR__);

// ������нڵ����ͽṹ��
typedef struct queuenode
{
    object           __VAR__ Datas;
    struct queuenode __PTR__ Next;
} QueueNode;
// ����������ͽṹ��
typedef struct queue
{
    int32     __VAR__ Count;            // ��ȡһ��������ָʾ��ǰ��������������Ԫ�ظ���
    QueueNode __VAR__ _Head;            // ���һ��ָ��ָ����е�ͷ��
    QueueNode __PTR__ _End;             // ���һ��ָ��ָ����е�β��

    queuefun_enqueue __VAR__ Enqueue;   // ��ȡһ������ָ��ָ����е���ӷ���
    queuefun_dequeue __VAR__ Dequeue;   // ��ȡһ������ָ��ָ����еĳ��ӷ���
    queuefun_clear   __VAR__ Clear;     // ��ȡһ������ָ��ָ����е���շ���
    queuefun_peek    __VAR__ Peek;      // ��ȡһ������ָ��ָ����еĶ�ͷ��ȡ����
} Queue;

// ����������з���
Queue __PTR__ CreateQueue();
// ���ٶ�����з���
void  __VAR__ DestroyQueue(Queue __PTR__ queue);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_QUEUE__