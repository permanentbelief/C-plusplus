//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <deque>
//#include <list>
//#include <vector>
//#include <string>
//using namespace std;
//
//namespace lth
//{
//	template <class T, class Con = deque<T>>
//	class Queue
//	{
//	public:
//		Queue() {}
//		void Push(const T& x) { _c.push_back(x); }
//		void Pop() { _c.pop_front(); }
//		T& Back() { return _c.back(); }
//		const T& Back()const { return _c.back(); }
//		T& Front() { return _c.front(); }
//		const T& Front()const { return _c.front(); }
//		size_t Size()const { return _c.size(); }
//		bool Empty()const { return _c.empty(); }
//	private:
//		Con _c;
//	};
//	void test1()
//	{
//		// 一个模板参数的时候
//		Queue<int> q;
//		q.Push(1);
//		q.Push(2);
//		q.Push(3);
//		q.Push(4);
//		cout <<"size:"  << q.Size() << endl;
//		cout << "第一个元素front:"  << q.Front() << endl;
//		cout << "最后一个元素back:" << q.Back() << endl;
//		while (!q.Empty())
//		{
//			cout << q.Front() << " ";
//			q.Pop();
//		}
//		cout << endl;
//	}
//	void test2()
//	{
//		//Queue<int, list<int>> q;
//		Queue<int, deque<int>> q;
//		q.Push(1);
//		q.Push(1);
//		q.Push(1);
//		q.Push(1);
//		q.Push(1);
//		while (!q.Empty())
//		{
//			cout << q.Front() << endl;
//			q.Pop();
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	//lth::test1();
//	lth::test2();
//	system("pause");
//}
