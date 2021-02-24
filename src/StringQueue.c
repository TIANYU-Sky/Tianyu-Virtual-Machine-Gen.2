#include<tianyuvm/queue.h>
#include<stdlib.h>

#ifdef __cplusplus
__C__
{
#endif

char  __PTR__ StringQueueFun_Peek
(
	StringQueue __PTR__ queue
)
{
	if (null != queue && 0 < queue->Count)
		return queue->_Head.Next->Datas;
	return null;
}
void  __VAR__ StringQueueFun_Clear
(
	StringQueue __PTR__ queue
)
{
	if (null != queue)
	{
		StringQueueNode __PTR__ temp = queue->_Head.Next;
		StringQueueNode __PTR__ del = temp;
		while (null != temp)
		{
			temp = temp->Next;
			free(del->Datas);
			free(del);
			del = temp;
		}
		queue->_Head.Next = null;
		queue->_End = __V_To_P__ queue->_Head;
		queue->Count = 0;
	}
}
int32 __VAR__ StringQueueFun_Enqueue
(
	StringQueue __PTR__ queue, 
	char __PTR__ element
)
{
	if (null != queue)
	{
		StringQueueNode __PTR__ newnode = (StringQueueNode __PTR__)malloc(sizeof(StringQueueNode));
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
char  __PTR__ StringQueueFun_Dequeue
(
	StringQueue __PTR__ queue
)
{
	if (null != queue && 0 < queue->Count)
	{
		char __PTR__ result = queue->_Head.Next->Datas;
		StringQueueNode __PTR__ del = queue->_Head.Next;
		queue->_Head.Next = del->Next;
		free(del);
		--(queue->Count);
		if (0 == queue->Count)
			queue->_End = __V_To_P__ queue->_Head;
		return result;
	}
	return null;
}
StringQueue __PTR__ CreateStringQueue()
{
	StringQueue __PTR__ newq = (StringQueue __PTR__)malloc(sizeof(StringQueue));
	if (null != newq)
	{
		newq->Count = 0;
		newq->_Head.Next = null;
		newq->_End = __V_To_P__ newq->_Head;

		newq->Enqueue = StringQueueFun_Enqueue;
		newq->Dequeue = StringQueueFun_Dequeue;
		newq->Clear = StringQueueFun_Clear;
		newq->Peek = StringQueueFun_Peek;
		return newq;
	}
	return null;
}

void      __VAR__ DestroyStringQueue
(
	StringQueue __PTR__ queue
)
{
	if (null != queue)
	{
		StringQueueNode __PTR__ temp = queue->_Head.Next;
		StringQueueNode __PTR__ del = temp;
		while (null != temp)
		{
			temp = temp->Next;
			free(del->Datas);
			free(del);
			del = temp;
		}
		free(queue);
	}
}

#ifdef __cplusplus
}
#endif