#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>

#include <deque>
using namespace std;
void PrintDeque(const deque<int>& d)
{
	for (const auto& e : d)
	{
		cout << e << " ";
	}
	cout << endl;
}
//测试deque的构造函数
void TestDeque1()
{
	//构造空的双端队列
	deque<int> d1;

	//用10个值为5的元素构造双端队列
	deque<int> d2(10, 5);
	PrintDeque(d2);
	// 用数组的区间构造双端队列
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3);

	//用d3拷贝构造d4
	deque<int> d4(d3);
	PrintDeque(d4);
	PrintDeque(d4);
}
// 测试deque的迭代器
void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int>d(array, array + sizeof(array) / sizeof(array[0]));

	//正向迭代器打印deque的元素
	for (auto it = d.cbegin(); it != d.cend(); ++it)
	{
		cout << *it << " ";
	}
		
	cout << endl;

	//反向迭代器逆向打印deque的元素
	for (auto it = d.crbegin(); it != d.crend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void TestDeque3()
{
	// 列表初始化
	deque<int>d1{ 3, 4, 5 };
	//在deque的尾部插入5，头部插入1，并打印
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;
	d1.emplace_back(7);
	d1.emplace_front(1);
	PrintDeque(d1);

	//在deque的begin位置插入元素0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);

	//删除deque的首部与尾部元素
	d1.pop_front();
	d1.pop_back();
	PrintDeque(d1);
	d1.erase(d1.begin());
	d1.erase(d1.end()-1);//删除尾部元素是下标是end-1，
	PrintDeque(d1);
}
int main()
{
	//TestDeque1();
	//TestDeque2();
	TestDeque3();
	system("pause");
}