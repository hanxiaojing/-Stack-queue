#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __STACK__
#define __STACK__
#include<iostream>
using namespace std;

#include<assert.h>
//适配器实现Stack
//template<class T>
//class SeqList
//{
//public:
//	SeqList()
//		:_array(NULL)
//		, _size(0)
//		, _capacity(0)
//	{}
//
//	SeqList<T>(const SeqList<T>& s)
//		: _array(new T[s._capacity])
//	{
//		swap(_array, s._array);
//		swap(_size, s._size);
//		swap(_capacity, s._capacity);
//	}
//
//	SeqList<T>& operator=(const SeqList<T>& s)
//	{
//		if (&s != this)
//		{
//			delete[] _array;
//			swap(_array, s._array);
//			swap(_size, s._size);
//			swap(_capacity, s._capacity);
//		}
//		return *this;
//	}
//
//	~SeqList()
//	{
//		if (_array)
//		{ 
//			delete[] _array;
//			_array = NULL;
//		}
//	}
//
//private:
//	T* _array;
//	size_t _size;
//	size_t _capacity;
//
//};
//
//template<class T,template<> class Container = SeqList>//模版的模版类
//class Stack
//{
//	//调用PushBack,PopFront等
//private:
//	Container<T> _con;//栈顶
//
//};


//直接实现Stack
template<class T>
class Stack
{
public:
	Stack()
		:_array(NULL)
		, _size(0)
		, _capacity(0)
	{}

	Stack<T>(const Stack<T>& s)
		: _array(new T[s._capacity])
	{
		swap(_array, s._array);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	Stack<T>& operator=(const Stack<T>& s)
	{
		if (&s != this)
		{
			swap(_array, s._array);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		return *this;
	}

	~Stack()
	{
		if (_array)
		{
			delete[] _array;
			_array = NULL;
		}
	}

	void _CheckCapacity()
	{
		if (_size == 0)
		{
			_capacity = 3;
			_array = new T[_capacity];
		}
		if (_size >= _capacity)
		{
			_capacity *= 2;
			T* tmp = new T[_capacity];
			for (int index = 0; index < _size; index++)
			{
				tmp[index] = _array[index];
			}
			delete[] _array;
			_array = tmp;
		}		
	}

	//入栈
	void Push(const T& x)
	{
		_CheckCapacity();
		_array[_size++] = x;		
	}

	void Pop()
	{
		if (_size == 0)
		{
			return;
		}
		--_size;
	}

	size_t Size()
	{
		return _size;
	}

	bool Empty()
	{
		return Size() == 0;
	}

	T& Top()
	{
		assert(_size > 0);
		return _array[_size - 1];
	}

private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

template<class T>
class Queue
{
public:
	void InQueue(const T& x)
	{
		s1.Push(x);
	}

	void OutQueue()
	{
		//栈s2为空，则将栈s1的元素全部倒入s2中，再弹出最上面的那个元素
		if (s2.Empty())
		{
			while (!s1.Empty())
			{
				s2.Push(s1.Top());
				s1.Pop();
			}
			s2.Pop();
		}

		//栈s2不为空，直接弹出元素
		else
		{
			s2.Pop();
		}
	}

	void Print()
	{
		if (s1.Empty() && s2.Empty())
		{
			cout << "The Queue is Empty!";
		}

		else if (!s1.Empty() && s2.Empty())
		{
			while (!s1.Empty())
			{
				s2.Push(s1.Top());
				s1.Pop();
			}

			while (!s2.Empty())
			{
				cout << s2.Top() << "  ";
				s2.Pop();
			}
		}

		else if (s1.Empty() && !s2.Empty())
		{
			while (!s2.Empty())
			{
				cout<<s2.Top()<<"  ";
				s2.Pop();
			}
		}

		else 
		{
			while (!s2.Empty())
			{
				cout << s2.Top() << "  ";
				s2.Pop();
			}

			while (!s1.Empty())
			{
				s2.Push(s1.Top());
				s1.Pop();
			}

			while (!s2.Empty())
			{
				cout << s2.Top() << "  ";
				s2.Pop();
			}
		}
		cout << endl;
	}

private:
	Stack<T> s1;
	Stack<T> s2;
};

#endif //__STACK__