/**
 * �������������ϵͳ�Ķ�ջ���ݽṹ
 * �������ַ����ַ����Լ�void*����
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
 * �ַ���ջ
*/
// �ַ���ջ���� Ԥ����
__Predefine__ struct charstack;
// �ַ���ջ�ڵ����� Ԥ����
__Predefine__ struct charstacknode;

// �ַ���ջ��������ָ��-��ջ
typedef int32 __VAR__(__PTR__ charstackfun_push) (struct charstack __PTR__, char);
// �ַ���ջ��������ָ��-��ջ
typedef char  __VAR__(__PTR__ charstackfun_pop)  (struct charstack __PTR__);
// �ַ���ջ��������ָ��-��ȡջβ������ջ��
typedef char  __VAR__(__PTR__ charstackfun_peek) (struct charstack __PTR__);
// �ַ���ջ��������ָ��-��ն�ջ
typedef void  __VAR__(__PTR__ charstackfun_clear)(struct charstack __PTR__);

// �ַ���ջ�ڵ����ͽṹ��
typedef struct charstacknode
{
    char                 __VAR__ Datas;
    struct charstacknode __PTR__ Next;
} CharStackNode;
// �ַ���ջ���ͽṹ��
typedef struct charstack
{
    int32         __VAR__ Count;       // ��ȡһ��������ָʾ��ǰ��ջ����������Ԫ�ظ���
    CharStackNode __VAR__ _Top;        // ���һ��ָ��ָ���ջ�Ķ���

    charstackfun_push   __VAR__ Push;  // ��ȡһ������ָ��ָ���ջ����ջ����
    charstackfun_pop    __VAR__ Pop;   // ��ȡһ������ָ��ָ���ջ�ĳ�ջ����
    charstackfun_clear  __VAR__ Clear; // ��ȡһ������ָ��ָ���ջ����շ���
    charstackfun_peek   __VAR__ Peek;
} CharStack;

// �����ַ���ջ����
CharStack __PTR__ CreateCharStack();
// �����ַ���ջ����
void      __VAR__ DestroyCharStack(CharStack __PTR__ stack);

/**
 * �ַ�����ջ
*/
// �ַ�����ջ���� Ԥ����
__Predefine__ struct stringstack;
// �ַ�����ջ�ڵ����� Ԥ����
__Predefine__ struct stringstacknode;

// �ַ�����ջ��������ָ��-��ջ
typedef int32 __VAR__(__PTR__ stringstackfun_push) (struct stringstack __PTR__, char __PTR__);
// �ַ�����ջ��������ָ��-��ջ
typedef char  __PTR__(__PTR__ stringstackfun_pop)  (struct stringstack __PTR__);
// �ַ�����ջ��������ָ��-��ȡջβ������ջ��
typedef char  __PTR__(__PTR__ stringstackfun_peek) (struct stringstack __PTR__);
// �ַ�����ջ��������ָ��-��ն�ջ
typedef void  __VAR__(__PTR__ stringstackfun_clear)(struct stringstack __PTR__);

// �ַ�����ջ�ڵ����ͽṹ��
typedef struct stringstacknode
{
    char                   __PTR__ Datas;
    struct stringstacknode __PTR__ Next;
} StringStackNode;
// �ַ�����ջ���ͽṹ��
typedef struct stringstack
{
    int32           __VAR__ Count;          // ��ȡһ��������ָʾ��ǰ��ջ����������Ԫ�ظ���
    StringStackNode __VAR__ _Top;           // ���һ��ָ��ָ���ջ�Ķ���

    stringstackfun_push     __VAR__ Push;   // ��ȡһ������ָ��ָ���ջ����ջ����
    stringstackfun_pop      __VAR__ Pop;    // ��ȡһ������ָ��ָ���ջ�ĳ�ջ����
    stringstackfun_clear    __VAR__ Clear;  // ��ȡһ������ָ��ָ���ջ����շ���
    stringstackfun_peek     __VAR__ Peek;
} StringStack;

// �����ַ�����ջ����
StringStack __PTR__ CreateStringStack();
// �����ַ�����ջ����
void        __VAR__ DestroyStringStack(StringStack __PTR__ stack);

/**
 * �������Ͷ�ջ
*/
// �����ջ���� Ԥ����
__Predefine__ struct stack;
// �����ջ�ڵ����� Ԥ����
__Predefine__ struct stacknode;

// �����ջ��������ָ��-��ջ
typedef int32  __VAR__(__PTR__ stackfun_push) (struct stack __PTR__, object __VAR__);
// �����ջ��������ָ��-��ջ
typedef object __VAR__(__PTR__ stackfun_pop)  (struct stack __PTR__);
// �����ջ��������ָ��-��ȡջβ������ջ��
typedef object __VAR__(__PTR__ stackfun_peek) (struct stack __PTR__);
// �����ջ��������ָ��-��ն�ջ
typedef void   __VAR__(__PTR__ stackfun_clear)(struct stack __PTR__);

// �����ջ�ڵ����ͽṹ��
typedef struct stacknode
{
    object           __VAR__ Datas;
    struct stacknode __PTR__ Next;
} StackNode;
// �����ջ���ͽṹ��
typedef struct stack
{
    int32     __VAR__ Count;       // ��ȡһ��������ָʾ��ǰ��ջ����������Ԫ�ظ���
    StackNode __VAR__ _Top;        // ���һ��ָ��ָ���ջ�Ķ���

    stackfun_push   __VAR__ Push;  // ��ȡһ������ָ��ָ���ջ����ջ����
    stackfun_pop    __VAR__ Pop;   // ��ȡһ������ָ��ָ���ջ�ĳ�ջ����
    stackfun_clear  __VAR__ Clear; // ��ȡһ������ָ��ָ���ջ����շ���
    stackfun_peek   __VAR__ Peek;
} Stack;

// ���������ջ����
Stack __PTR__ CreateStack();
// ���ٶ����ջ����
void  __VAR__ DestroyStack(Stack __PTR__ stack);

#ifdef __cplusplus
}
#endif

#endif // !__TIANYUVM_C_CPP_STACK__