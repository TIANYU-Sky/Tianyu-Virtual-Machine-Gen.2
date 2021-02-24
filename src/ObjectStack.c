#include<tianyuvm/stack.h>
#include<stdlib.h>

#ifdef __cplusplus
__C__
{
#endif

int32 __VAR__ StackFun_Push
(
	Stack  __PTR__ stack,
	object __VAR__ element
)
{
	if (null != stack)
	{
		StackNode __PTR__ newnode = (StackNode __PTR__)malloc(sizeof(StackNode));
		if (null != newnode)
		{
			newnode->Datas = element;
			newnode->Next = stack->_Top.Next;
			stack->_Top.Next = newnode;
			++(stack->Count);
			return 0;
		}
		return -2;
	}
	return -1;
}
object __VAR__ StackFun_Pop
(
	Stack __PTR__ stack
)
{
	if (null != stack && null != stack->_Top.Next)
	{
		object result = stack->_Top.Next->Datas;
		StackNode __PTR__ del = stack->_Top.Next;
		stack->_Top.Next = del->Next;
		free(del);
		--(stack->Count);
		return result;
	}
	return null;
}
object __VAR__ StackFun_Peek
(
	Stack __PTR__ stack
)
{
	if (null != stack && null != stack->_Top.Next)
		return stack->_Top.Next->Datas;
	return null;
}
void  __VAR__ StackFun_Clear
(
	Stack __PTR__ stack
)
{
	if (null != stack)
	{
		while (null != stack->_Top.Next)
		{
			StackNode __PTR__ temp = stack->_Top.Next;
			StackNode __PTR__ del = temp;
			while (null != temp)
			{
				temp = temp->Next;
				free(del->Datas);
				free(del);
				del = temp;
			}
			stack->Count = 0;
			stack->_Top.Next = null;
		}
	}
}

Stack __PTR__ CreateStack()
{
	Stack __PTR__ news = (Stack __PTR__)malloc(sizeof(Stack));
	if (null != news)
	{
		news->Count = 0;
		news->_Top.Next = null;

		news->Clear = StackFun_Clear;
		news->Peek = StackFun_Peek;
		news->Pop = StackFun_Pop;
		news->Push = StackFun_Push;
		return news;
	}
	return null;
}
void      __VAR__ DestroyStack
(
	Stack __PTR__ stack
)
{
	if (null != stack)
	{
		StackFun_Clear(stack);
		free(stack);
	}
}

#ifdef __cplusplus
}
#endif