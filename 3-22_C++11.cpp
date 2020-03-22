#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <array>
using namespace std;

//int main()
//{
//	//C++98
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//
//	//C++11支持{}初始化
//	int* p1 = new int(10); // C++98
//	//int* p2 = new int[5](1);//C++98不支持new数组的初始化
//	int* p3 = new int[5]{1,2,3,4,5};//C++11
//	vector<int> v1{ 1, 2, 3, 4, 5 };
//	vector<int> v2 = { 1, 2, 3, 4, 5 };
//	set<int> s1 = { 2, 3, 1, 5, 3, 5 };
//	map<string, int> countMap = { { "sort", 1 }, { "string", 3 } }; // =可以有，可以没有
//
//	return 0;
//}

// C++98
class A


{
public:
	//explicit A(int a)
	A(int a)
		:_a(a)
	{}
private:
	int _a;
};

class Point
{
public:
	Point(int x, int y) : _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};

//int main()
//{
//	//C++98
//	A a1(1); // 调用构造函数
//	A a2 = 2; // 类型转换    -> 1、构造临时对象 + 拷贝构造a2 + 优化 = 直接构造
//	string s1("hello");
//	string s2 = "hello";
//
//	int i = 0;
//	const double& d = i;
//
//	Point p1(1, 1);
//	//Point p2 = (2,2);  // C++98不支持多个参数对象转换
//	Point p3 = { 3, 3 }; //C++11
//
//	// 那么这里就可以看到map的初始化和set的初始化时一样的方式支持的，只是map存是
//	// 一个一个的pair，{ "sort", 1 }转成一个pair对象
//	set<int> s1 = { 2, 3, 1, 5, 3, 5 };
//	map<string, int> countMap = { { "sort", 1 }, { "string", 3 } }; // =可以有，可以没有
//
//	return 0;
//}

//int main()
//{
//	initializer_list<int> l1 = { 1, 2, 3, 4, 5 };
//	initializer_list<int>::iterator it1 = l1.begin();
//	while (it1 != l1.end())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//	
//	//vector (initializer_list<value_type> il,const allocator_type& alloc = allocator_type());
//	// 其他的容器也是类似的方式支持的
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	cout << typeid(v).name() << endl;
//
//	int a = 10;
//	int b = 20;
//
//	// 用decltype推演a+b的实际类型，作为定义c的类型
//	decltype(a + b) c;
//	cout << typeid(c).name() << endl;
//
//	// 1、范围for对于容器而言，底层是由迭代器支持的。
//	for (auto e : v)
//		cout << e << " ";
//	// 2、这里是取v容器中的值依次赋值给e，也就是说对e的改变不会影响v
//	for (auto& e : v)
//		e *= 2;
//	// 3、当时e拷贝大家大的对象时，注意用&
//	vector<string> vs{"sort", "string"};
//	for (const auto& e : vs)
//		// ...
//}

//int main()
//{
//	// a是左值，10是一个右值
//	int a = 10;
//	// 在左边的一定左值吗？是的
//	// 在右边的一定是右值吗？不一定,比如下面表达式的a
//	int b = a;
//	// 左值通常是：可以被修改的对象
//	// 右值通常是：常量，表达式的返回值(临时对象)
//	int c = a + b;
//}

//int main()
//{
//	// 1、左值引用可以引用左值
//	int a = 10;
//	int& b = a;
//
//	// 2、左值引用能否引用右值？不行，但是const左值引用可以
//	const int& c = 10;
//	const int& d = a + b;
//
//	return 0;
//}

//int main()
//{
//	// 右引用引用右值
//	// 右值引用能否引用左值？不能,
//	// 但是可以使用move将左值转换成右值,就可以右值引用了
//	int a = 10;
//	//int&& b = a; // 编译报错
//	int && b = move(a);
//	int&& c = 10;
//	int&& d = a + 10;
//}

// 实现String的深拷贝
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// 拷贝构造
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;
		strcpy(_str, s._str);
	}

	// 移动构造->为什么这里能直接进行移动，因为s是右值中的将亡值，
	// 反正你都要走了，我不要拷贝了，直接将你资源移动给我可好。
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		swap(_str, s._str);
	}

	// s1 = tmp
	// 移动构造
	String& operator = (String&& s)
	{
		swap(_str, s._str);

		return *this;
	}

	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;

		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	// s1 + s2
	// s1.operator+(&s1, s2)
	String operator+(const String& s) const
	{
		String tmp;
		tmp._str = new char[strlen(_str) + strlen(s._str)+1];
		strcpy(tmp._str, _str);
		strcat(tmp._str, s._str);
		return tmp;
	}

	~String()
	{
		if (_str)
			delete[] _str;
	}

	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};

// 移动构造和移动赋值

int main()
{
	String s1("hello");
	String s2("world");
	String ret = s1 + s2; // ->拷贝构造
	cout << ret.c_str() << endl;

	String s3(s1);       // 拷贝构造
	String s5(move(s1)); // 移动构造

	return 0;
}