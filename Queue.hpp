#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __QUEUE__
#define __QUEUE__

#include<iostream>
using namespace std;
#include<assert.h>


//实现QUEUE
template<class T>
struct Node
{
	T _data;
	Node* _next;
	Node(const T& x)
		:_data(x)
		, _next(NULL)
	{}
};

template<class T>
class Queue
{
public:
	Queue()
		:_tail(NULL)
		, _head(NULL)
	{}


	Queue<T>(const Queue<T>& q)
		: _tail(NULL)
		, _head(NULL)
	{
		Node<T>* cur = q._head;
		while (cur)
		{
			this->Push(cur->_data);
			cur = cur->_next;
		}
	}

	Queue<T>& operator=(const Queue<T>& q)
	{
		if (&q != this)
		{
			Node<T>* cur = _head;
			while (cur)
			{
				Node<T>* del = cur;
				cur = cur->_next;
				delete del;
			}

			Node<T>* cur1 = q._head;
			while (cur1)
			{
				this->Push(cur1->_data);
				cur1 = cur1->_next;
			}
		}
		return *this;
	}

	~Queue()
	{
		if (_head)
		{
			delete[] _head;
			_head = NULL;
		}
	}

	void Push(const T& x)
	{
		if (_head == NULL)
		{
			_head = new Node<T>(x);
			_tail =  _head;
		}
		else
		{
			Node<T>* cur = new Node<T>(x);
			_tail->_next = cur;
			_tail = cur;
		}
	}

	void Pop()//出队头删
	{
		assert(Size() > 0);
		if (_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			Node<T>* del = _head;
			_head = _head->_next;
			delete del;
			del = NULL;
		}
	}

	size_t Size()
	{
		int count = 0;
		Node<T>* cur = _head;
		while (cur)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}

	bool Empty()
	{
		return Size() == 0;
	}

	T& Top()
	{
		assert(Size() > 0);
		return _head->_data;
	}

private:
	Node<T>* _head;
	Node<T>* _tail;
};

#endif	//__QUEUE__