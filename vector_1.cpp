#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// 第一种遍历方式 重载下标运算符[]
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	// 第二种遍历方式 范围for 其实底层就是迭代器
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	// 第三种遍历方式 迭代器
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	// 迭代器 从后向前遍历 从后往前输出
	// 获取最后的一个位置 和end()原来的位置相同
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	// 注意rbegin指向的是vector最后一个元素的下一位，
	// 其实是先减减 在解引用访问
}
void test_vector2()
{
	//构造函数
	vector<int> v2;
	vector<int> v3(4, 100);
	vector<int> v4(v3.begin(), v3.end());//迭代器进行初始化
	vector<int> v5(++v3.begin(), --v3.end()); //迭代器初始化只是位置不同
}
void test_vector3()
{
	cout << int() << endl;
}
void test_vector4()
{
	vector<int> v;
	v.reserve(100); //capacity增到100，开空间在知道多少空间时，提前开好，减少扩容次数，增高效率 而且不会缩容
	v.resize(100); // capacity 和 size都扩增到100 同时会初始化，把缺省值填上。
}
void test_vector5()
{
	vector<int> v; //   size  capacity
	v.resize(10);  //     10     10
	v.resize(20);  //     20     20
	v.resize(10);  //     10     20
}
void test_vector6()
{
	int a[] = { 1, 2, 3, 4 };
	//指针就是天然的迭代器
	vector<int>v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	auto pos = find(v.begin(), v.end(), 3);
	//cout << pos << endl;
	v.insert(pos, 30);
	//v.erase(pos); 迭代器失效
}
int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	test_vector6();
	system("pause");
}