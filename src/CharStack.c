#include<tianyuvm/stack.h>
#include<stdlib.h>

#ifdef __cplusplus
__C__
{
#endif

int32 __VAR__ CharStackFun_Push
(
	CharStack __PTR__ stack,
	char	  __VAR__ element
)
{
	if (null != stack)
	{
		CharStackNode __PTR__ newnode = (CharStackNode __PTR__)malloc(sizeof(CharStackNode));
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
char  __VAR__ CharStackFun_Pop
(
	CharStack __PTR__ stack
)
{
	if (null != stack && null != stack->_Top.Next)
	{
		char result = stack->_Top.Next->Datas;
		CharStackNode __PTR__ del = stack->_Top.Next;
		stack->_Top.Next = del->Next;
		free(del);
		--(stack->Count);
		return result;
	}
	return '\0';
}
char  __VAR__ CharStackFun_Peek
(
	CharStack __PTR__ stack
)
{
	if (null != stack && null != stack->_Top.Next)
		return stack->_Top.Next->Datas;
	return '\0';
}
void  __VAR__ CharStackFun_Clear
(
	CharStack __PTR__ stack
)
{
	if (null != stack)
	{
		while (null != stack->_Top.Next)
		{
			CharStackNode __PTR__ temp = stack->_Top.Next;
			CharStackNode __PTR__ del = temp;
			while (null != temp)
			{
				temp = temp->Next;
				free(del);
				del = temp;
			}
			stack->Count = 0;
			stack->_Top.Next = null;
		}
	}
}

CharStack __PTR__ CreateCharStack()
{
	CharStack __PTR__ news = (CharStack __PTR__)malloc(sizeof(CharStack));
	if (null != news)
	{
		news->Count = 0;
		news->_Top.Next = null;
		
		news->Clear = CharStackFun_Clear;
		news->Peek = CharStackFun_Peek;
		news->Pop = CharStackFun_Pop;
		news->Push = CharStackFun_Push;
		return news;
	}
	return null;
}
void      __VAR__ DestroyCharStack
(
	CharStack __PTR__ stack
)
{
	if (null != stack)
	{
		CharStackFun_Clear(stack);
		free(stack);
	}
}

#ifdef __cplusplus
}
#endif