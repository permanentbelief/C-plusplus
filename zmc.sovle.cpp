#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <deque>
using namespace std;

namespace zmc{
	template<class T, class Con = deque<T> >	//ÈÝÆ÷

	class stack
	{
	public:
		stack()
		{
		}

		void Push(const T& x)
		{
			c.push_back(x);
		}
		void Pop()
		{
			c.pop_back();
		}
		T& Top()
		{
			return c.back();
		}
		const T& Top()const
		{
			return c.back();
		}
		size_t Size()const
		{
			return c.size();
		}
		bool Empty()
		{
			return c.empty();
		}
	private:
		Con c;


	};
}
int main()
{

	zmc::stack<int> s;
	//s.Push(1);
	//s.Push(1);
	s.Push(1);


	system("pause");
	return 0;
}