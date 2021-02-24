#include<tianyuvm/queue.h>
#include<stdlib.h>

#ifdef __cplusplus
__C__
{
#endif

object __VAR__ QueueFun_Peek
(
	Queue __PTR__ queue
)
{
	if (null != queue && 0 < queue->Count)
		return queue->_Head.Next->Datas;
	return null;
}
void  __VAR__ QueueFun_Clear
(
	Queue __PTR__ queue
)
{
	if (null != queue)
	{
		QueueNode __PTR__ temp = queue->_Head.Next;
		QueueNode __PTR__ del = temp;
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
int32 __VAR__ QueueFun_Enqueue
(
	Queue __PTR__ queue, 
	object __VAR__ element
)
{
	if (null != queue)
	{
		QueueNode __PTR__ newnode = (QueueNode __PTR__)malloc(sizeof(QueueNode));
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
object __VAR__ QueueFun_Dequeue
(
	Queue __PTR__ queue
)
{
	if (null != queue && 0 < queue->Count)
	{
		object result = queue->_Head.Next->Datas;
		QueueNode __PTR__ del = queue->_Head.Next;
		queue->_Head.Next = del->Next;
		free(del);
		--(queue->Count);
		if (0 == queue->Count)
			queue->_End = __V_To_P__ queue->_Head;
		return result;
	}
	return null;
}
Queue __PTR__ CreateQueue()
{
	Queue __PTR__ newq = (Queue __PTR__)malloc(sizeof(Queue));
	if (null != newq)
	{
		newq->Count = 0;
		newq->_Head.Next = null;
		newq->_End = __V_To_P__ newq->_Head;

		newq->Enqueue = QueueFun_Enqueue;
		newq->Dequeue = QueueFun_Dequeue;
		newq->Clear = QueueFun_Clear;
		newq->Peek = QueueFun_Peek;
		return newq;
	}
	return null;
}

void      __VAR__ DestroyQueue(Queue __PTR__ queue)
{
	if (null != queue)
	{
		QueueNode __PTR__ temp = queue->_Head.Next;
		QueueNode __PTR__ del = temp;
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