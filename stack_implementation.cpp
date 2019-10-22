#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <string>
using namespace std;


namespace lth
{
	template<class T, class Container>
	class Stack
	{
	public:
		Stack()
		{
			//自定义类会调用自己的构造函数
		}
		void push(const T &x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		 T& top() 
		{
			return _con.back();
		}
		size_t size() 
		{
			return _con.size();
		}
		bool empty() const
		{
			return _con.empty();
		}
	/*	friend ostream <<(ostream& out, const T& x)
		{
			out << x << " ";
			return out;
		}*/
	private:
		Container _con;
	};
	void test1()
	{
		Stack<int, vector<int>> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(5);
		s.push(6);
		cout << "size:" << s.size() << endl;
		
		while (!s.empty())
		{
			cout << s.top() << endl;
			s.pop();
		}
		cout << endl;
		//Stack<string, vector<string>>t;
		//t.push("wo ai ni");
		//t.push("hehe  gun!!");
		//while (!t.empty())
		//{
		//	//t.top() = 'D';
		//	cout << t.top() << endl;
		//	t.pop();
		//}
		//cout << endl;
	}
	void test2()
	{
		Stack<int, deque<int>> s;
		//Stack<int, list<int>> s;
		s.push(1);
		s.push(2);
		s.push(2);
		s.push(2);
		s.push(2);
		while (!s.empty())
		{
			cout << s.top() << endl;
			s.pop();
		}
	}
}
int main()
{
	lth::test1();
	lth::test2();
	system("pause");
}