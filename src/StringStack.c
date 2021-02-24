#include<tianyuvm/stack.h>
#include<stdlib.h>

#ifdef __cplusplus
__C__
{
#endif

int32 __VAR__ StringStackFun_Push
(
	StringStack __PTR__ stack,
	char	    __PTR__ element
)
{
	if (null != stack)
	{
		StringStackNode __PTR__ newnode = (StringStackNode __PTR__)malloc(sizeof(StringStackNode));
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
char  __PTR__ StringStackFun_Pop
(
	StringStack __PTR__ stack
)
{
	if (null != stack && null != stack->_Top.Next)
	{
		char __PTR__ result = stack->_Top.Next->Datas;
		StringStackNode __PTR__ del = stack->_Top.Next;
		stack->_Top.Next = del->Next;
		free(del);
		--(stack->Count);
		return result;
	}
	return null;
}
char  __PTR__ StringStackFun_Peek
(
	StringStack __PTR__ stack
)
{
	if (null != stack && null != stack->_Top.Next)
		return stack->_Top.Next->Datas;
	return null;
}
void  __VAR__ StringStackFun_Clear
(
	StringStack __PTR__ stack
)
{
	if (null != stack)
	{
		while (null != stack->_Top.Next)
		{
			StringStackNode __PTR__ temp = stack->_Top.Next;
			StringStackNode __PTR__ del = temp;
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

StringStack __PTR__ CreateStringStack()
{
	StringStack __PTR__ news = (StringStack __PTR__)malloc(sizeof(StringStack));
	if (null != news)
	{
		news->Count = 0;
		news->_Top.Next = null;

		news->Clear = StringStackFun_Clear;
		news->Peek = StringStackFun_Peek;
		news->Pop = StringStackFun_Pop;
		news->Push = StringStackFun_Push;
		return news;
	}
	return null;
}
void      __VAR__ DestroyStringStack
(
	StringStack __PTR__ stack
)
{
	if (null != stack)
	{
		StringStackFun_Clear(stack);
		free(stack);
	}
}

#ifdef __cplusplus
}
#endif