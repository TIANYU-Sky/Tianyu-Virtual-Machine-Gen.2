#include<tianyuvm/queue.h>
#include<stdlib.h>

#ifdef __cplusplus
__C__
{
#endif

char  __VAR__ CharQueueFun_Peek
(
	CharQueue __PTR__ queue
) 
{
	if (null != queue && 0 < queue->Count)
		return queue->_Head.Next->Datas;
	return '\0';
}
void  __VAR__ CharQueueFun_Clear
(
	CharQueue __PTR__ queue
)
{
	if (null != queue)
	{
		CharQueueNode __PTR__ temp = queue->_Head.Next;
		CharQueueNode __PTR__ del = temp;
		while (null != temp)
		{
			temp = temp->Next;
			free(del);
			del = temp;
		}
		queue->_Head.Next = null;
		queue->_End = __V_To_P__ queue->_Head;
		queue->Count = 0;
	}
}
int32 __VAR__ CharQueueFun_Enqueue
(
	CharQueue __PTR__ queue, 
	char element
)
{
	if (null != queue)
	{
		CharQueueNode __PTR__ newnode = (CharQueueNode __PTR__)malloc(sizeof(CharQueueNode));
		if (null != newnode)
		{
			newnode->Datas = element;
			newnode->Next = null;
			queue->_End->Next = newnode;
			queue->_End = newnode;
			++(queue->Count);
			return 0;
		}
		return -2;
	}
	return -1;
}
char  __VAR__ CharQueueFun_Dequeue
(
	CharQueue __PTR__ queue
)
{
	if (null != queue && 0 < queue->Count)
	{
		char result = queue->_Head.Next->Datas;
		CharQueueNode __PTR__ del = queue->_Head.Next;
		queue->_Head.Next = del->Next;
		free(del);
		--(queue->Count);
		if (0 == queue->Count)
			queue->_End = __V_To_P__ queue->_Head;
		return result;
	}
	return '\0';
}
CharQueue __PTR__ CreateCharQueue()
{
	CharQueue __PTR__ newq = (CharQueue __PTR__)malloc(sizeof(CharQueue));
	if (null != newq)
	{
		newq->Count = 0;
		newq->_Head.Datas = '\0';
		newq->_Head.Next = null;
		newq->_End = __V_To_P__ newq->_Head;

		newq->Enqueue = CharQueueFun_Enqueue;
		newq->Dequeue = CharQueueFun_Dequeue;
		newq->Clear = CharQueueFun_Clear;
		newq->Peek = CharQueueFun_Peek;
		return newq;
	}
	return null;
}

void      __VAR__ DestroyCharQueue
(
	CharQueue __PTR__ queue
)
{
	if (null != queue)
	{
		CharQueueNode __PTR__ temp = queue->_Head.Next;
		CharQueueNode __PTR__ del = temp;
		while (null != temp)
		{
			temp = temp->Next;
			free(del);
			del = temp;
		}
		free(queue);
	}
}

#ifdef __cplusplus
}
#endif