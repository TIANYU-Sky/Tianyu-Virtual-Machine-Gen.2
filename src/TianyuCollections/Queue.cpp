#include<tianyutl/queue.h>
#include<tyexception/nullpointer.h>
#include<tyexception/outboundary.h>
#include<tyexception/unrealized.h>

template<typename T>
struct __TIANYU__::Queue<T>::QueueNode
{
	_Public T			__VAR__ Elem;
	_Public QueueNode	__PTR__ Next;
};

template<typename T>
__TIANYU__::Queue<T>::Queue()
	: _Count(0)
{
	_Head = new QueueNode();
	_Head->Next = null;
	_End = _Head;
}
template<typename T>
__TIANYU__::Queue<T>::~Queue()
{
	Clear();
	delete _Head;
}

template<typename T>
void __VAR__ __TIANYU__::Queue<T>::Enqueue
(
	__IN_Param__ T __VAR__ elem
)
{
	QueueNode __PTR__ node = new QueueNode();
	node->Next = null;
	node->Elem = elem;

	_End->Next = node;
	_End = _End->Next;
	++_Count;
}
template<typename T>
T	__VAR__ __TIANYU__::Queue<T>::Dequeue()
{
	if (0 < _Count)
	{
		QueueNode __PTR__ del = _Head->Next;
		_Head = _Head->Next;
		T __VAR__ result = del->Elem;
		delete del;
		--_Count;
		return result;
	}
	return _Head->Elem;
}
template<typename T>
T	__VAR__ __TIANYU__::Queue<T>::Peek()
{
	if (0 < _Count)
		return _Head->Next->Elem;
	return _Head->Elem;
}

template<typename T>
int32 __VAR__ __TIANYU__::Queue<T>::Count()
{
	return _Count;
}

template<typename T>
bool __VAR__ __TIANYU__::Queue<T>::IsReadOnly()
{
	return false;
}

template<typename T>
void __VAR__ __TIANYU__::Queue<T>::Add
(
	__IN_Param__ T __VAR__ elem
)
{
	Enqueue(elem);
}

template<typename T>
void __VAR__ __TIANYU__::Queue<T>::Clear()
{
	while (null != _Head->Next)
	{
		QueueNode __PTR__ del = _Head->Next;
		_Head = _Head->Next;
		delete del;
	}
	_End = _Head;
	_Count = 0;
}

template<typename T>
bool __VAR__ __TIANYU__::Queue<T>::Contains
(
	__IN_Param__ T __VAR__ elem
)
{
	QueueNode __PTR__ node = _Head;
	while (null != node->Next)
	{
		if (node->Next->Elem.GetHashCode() == elem.GetHashCode())
			return true;
		node = node->Next;
	}
	return false;
}

template<typename T>
void __VAR__ __TIANYU__::Queue<T>::CopyTo
(
	__IN_Param__ T      __PTR__ array,
	__IN_Param__ int32  __VAR__ len,
	__IN_Param__ int32  __VAR__ index
)
{
	if (null == array)
		throw new __TIANYU__::__EXCEPTION__::ArgumentNullPointerException();


	if (index >= len || len < index + _Count)
		throw new __TIANYU__::__EXCEPTION__::ArgumentOutOfBoundaryException();

	QueueNode __PTR__ node = _Head;
	while (null != node->Next)
	{
		array[index] = node->Next->Elem;
		node = node->Next;
	}
}

template<typename T>
void __VAR__ __TIANYU__::Queue<T>::Remove
(
	__IN_Param__ T __VAR__ elem
)
{
	throw new __TIANYU__::__EXCEPTION__::MethodNotImplementedException();
}