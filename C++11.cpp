#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;


//
//int main()
//{
//	//C++11使用了初始化列表，使其初始化，C++98无法编译通过，需要循环赋值
//	vector<int> v = { 1, 3, 5, 7, 9 };
//	
//	//内置类型的初始化
//	int x1 = { 10 };
//	int x2{ 10 };
//	int x3 = 1 + 2;
//	int x4 = { 1 + 2 };
//	int x5{ 1 + 2 };
//
//	cout << x1 << x2 << x3 << x4 << x5 << endl;
//
//	int arr1[5] {1, 2, 3, 4, 5};
//	for (auto e : arr1)
//	{
//		cout << e << endl;
//	}
//
//	int* arr3 = new int[5]{1, 2, 3, 4, 5};
//	for (int i = 0; i < 5; i++)
//	{
//		cout << arr3[i] << " ";
//	}
//	cout << endl;
//	map<int, int> m{ { 1, 2 } };
//	for (auto e : m)
//	{
//		cout << e.first << " " << e.second << endl;
//	}
//	system("pause");
//}

#include <initializer_list>
template <class T>
class Vector{
public:
	Vector (initializer_list<T> l)
		:_capacity(l.size())
		, _size(0)
	{
		_array = new T[_capacity];
		for (auto e : l)
		{
			_array[_size++] = e;
		}
	}
	vector<T>& operator=(initializer_list<T> l)
	{
		delete[] _array;
		size_t i = 0;
		for (auto e : l)
		{
			_array[i++] = e;
		}
		return *this;
	}
	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

//RTTI 运行时类型识别 
// typeid 只能查看类型不能用其结果定义类型
// dynamic_cast 只能应用于含有虚函数的继承体系中


//decltype 根据表达式的实际类型推演出定义变量时所用的类型



//推导函数返回值的类型

void* GetMemory(size_t size)
{
	return malloc(size);
}
//
//int main()
//{

	// 推导函数类型

	/*cout << typeid(decltype(GetMemory)).name() << endl;

	cout << typeid(decltype(GetMemory(9.00))).name() << endl;*/
	//// 推导变量类型
	//int a = 10;
	//double b = 20;

	//decltype(a + b) c;
	//cout << typeid(c).name()<< endl;

	//initializer_list<int>l{ 1, 2, 3, 4, 5 };
	//Vector<int> V(l);
	//V.Print();
	//Vector<int> K(V);
	//K.Print();
	//Vector<int> T = V;
	//T.Print();
//	system("pause");
//}

//C++对于空类编译器会生成一些默认的成员函数，
// 构造函数 拷贝构造函数， 运算符重载，析构函数，&和const&重载、移动构造、移动拷贝构造等函数


//class A
//{
//public:
//	A() = default;
//
//	// 显示缺省构造函数，由编译器生成
//
//
//	A& operator=(const A& x);
//private:
//	int _a;
//};
//
//A& A::operator=(const A& x) = default;
//
////A::A(int a) = default;
//
//int main()
//{
//	A a1;
//	A a2;
//	a2 = a1;
//	system("pause");
//}


class Base
{
	virtual void foo();
};
class A : Base
{
	void foo() final;
	// void bar() final; // 父类中没有bar虚函数可以被重写
};

class B final : A  //指明B是不可以被继承的
{
	//void foo();  //Error: 在A中已经被final了，不可以被继承
	//void foo() override; // Error： 在A中已经被final了 
};

//class C : B  //已经被final了
//{
//
//}




//int global = 10;
//
//int& GetG_A()
//{
//	return global;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	//a和b都是左值
//	//左值既可以放在=的左侧也可以放在=的右侧
//
//	a = b;
//	b = a;
//
//	const int c = 30;
//
//	// c = a;// Eorro c不能放在=左边，所以c不算左值
//
//	cout << &c << endl;
//
//	
//    //	b + 1 = 2;
//	// 编译失败， b+1的结果只是一个临时变量，没有具体的名称，也不能取地址
//
//	GetG_A() = 100;
//	cout << global << endl;
//	
//
//	int&& r1 = 10;
//	r1 = 100;
//
//	//int a = 10;
//	//int &&r2 = a;
//
//
//
//	system("pause");
//}

//class String
//{
//public :
//	String(char* str = "")
//	{
//		if (nullptr == str)
//			str = "";
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//	
//	String(const String& s)
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			char* pTemp = new char[strlen(s._str) + 1];
//			strcpy(pTemp, s._str);
//			delete[] _str;
//			_str = pTemp;
//		}
//		return *this;
//	}
//
//	String operator+(const String& s)
//	{
//		char * pTemp = new char[strlen(_str) + strlen(s._str) + 1];
//		strcpy(pTemp, _str);
//		strcpy(pTemp + strlen(_str), s._str);
//		String strRet(pTemp);
//		return strRet;
//	}
//	~String()
//	{
//		if (_str)
//			delete[] _str;
//	}
//	String(String&& s)
//		:_str(s._str)
//	{
//		s._str = nullptr;
//	}
//private:
//	char* _str;
//
//};
//
//int main()
//{
//	while (1)
//	{
//		malloc(10000);
//	}
//}


//}