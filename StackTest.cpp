#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.hpp"

void Test()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);

	while(!s1.Empty()) 
	{
		cout<<s1.Top()<<"  ";
		s1.Pop();
	}
	cout<<endl;
}

//测试两个栈实现一个队列
void Test1()
{
	Queue<int> q1;
	q1.InQueue(1);	
	q1.InQueue(2);
	q1.InQueue(3);
	q1.InQueue(4);
	/*q1.Print();*/

	q1.OutQueue();
	/*q1.Print();*/
	q1.InQueue(5); 
	q1.InQueue(6);
	q1.InQueue(7);
	
	q1.Print();
}

int main()
{
	Test1();
	system("pause");
	return 0;
}


//
//#include"Queue.hpp"
//
//void Test()
//{
//	Queue<int> q1;
//	q1.Push(1);
//	q1.Push(2);
//	q1.Push(3);
//	q1.Push(4);
//	q1.Push(5);
//	q1.Push(6);
//
//	while (!q1.Empty())
//	{
//		cout << q1.Top() << "  ";
//		q1.Pop();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}