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
//  const int x = 10;
//	int a = 10;
//	// 在左边的一定左值吗？不一定  可以被修改对象
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

//int main()
//{
//	String s1("hello");
//	String s2("world");
//	String ret = s1 + s2;
//	cout << ret.c_str() << endl;
//
//	String s3(s1);       // 拷贝构造
//	String s5(move(s1)); // 移动构造
//
//	return 0;
//}

//int main()
//{
//	vector<String> v;
//	//String s1("左值");
//	//v.push_back(s1);               // 拷贝构造-深拷贝-代价大
//	//v.push_back("右值-将亡值");    // 移动构造-移动资源-代价小
//	v.push_back(move(s1));         // 移动构造-这里会付出代价，产生副作用，s1被制空了
//
//
//	String s2("左值");  // 了解一下，一般情况下我们还是使用上面push_pack就可以
//	v.emplace_back(s2);
//	v.emplace_back(String("右值-将亡值"));
//
//	return 0;
//}


//void Fun(int &x){ cout << "lvalue ref" << endl; }
//void Fun(int &&x){ cout << "rvalue ref" << endl; }
//void Fun(const int &x){ cout << "const lvalue ref" << endl; }
//void Fun(const int &&x){ cout << "const rvalue ref" << endl; }
//
//template<typename T>
//void PerfectForward(T && t)   //模板传参的过程中，右值属性会丢失 -》完美转发可以解决
//{
//	Fun(t);
//}
//
//int main()
//{
//	PerfectForward(10); // rvalue ref
//
//	int a = 0;
//	PerfectForward(a); // lvalue ref
//	PerfectForward(std::move(a)); // rvalue ref
//
//	const int b = 8;
//	PerfectForward(b); // const lvalue ref
//	PerfectForward(std::move(b)); // const rvalue ref
//
//	return 0;
//}

struct Goods
{
	string _name;
	double _price;
	int _evaluation; // 评价
	// 比如：销量、综合评价
};

bool PriceCompare(const Goods& g1, const Goods& g2)
{
	return g1._price < g2._price;
}

bool EvaluationCompare(const Goods& g1, const Goods& g2)
{
	return g1._evaluation < g2._evaluation;
}

struct PriceCompareOBJ
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price < g2._price;
	}
};

struct EvaluationCompareOBJ
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._evaluation < g2._evaluation;
	}
};

//int main()
//{
//	// 最简单的lambda表达式, 该lambda表达式没有任何意义
//	[]{};
//
//	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
//	int a = 3, b = 4,c=5;
//	[a,b]{return a + b; }; // 代表捕捉a,b
//	[=]{return a + b; }; // 代表捕捉外边所有对象
//
//	// 写一个交换a、b的lamber
//	// mutable改变捕捉到的a、b拷贝可以改变
//	auto lamber_swap1 = [a, b]()mutable->void{int tmp = a; a = b; b = tmp; };
//	lamber_swap1(); // 不能发生交换，传值拷贝的方式捕捉a、b
//
//	// 正式的写法
//	auto lamber_swap2 = [&a, &b](){int tmp = a; a = b; b = tmp; };
//	lamber_swap2(); 
//
//	auto lamber_swap3 = [](int& a, int& b){int tmp = a; a = b; b = tmp; };
//	lamber_swap3(a, b);
//
//	auto lamber_swap4 = [&](){int tmp = a; a = b; b = tmp; };
//	lamber_swap4();
//
//	return 0;
//}

//int main()
//{
//	Goods gds[] = { { "苹果", 2.1,  5}, { "香蕉", 3, 4}, { "橙子", 2.2, 2}, { "菠萝", 1.5, 2} };
//	// 按价格/评价排序的三种写法
//	// 1、函数指针 C沿袭过来
//	PriceCompare(gds[0], gds[1]);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), PriceCompare);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), EvaluationCompare);
//
//	// 2、仿函数/函数对象 -> 比起函数指针的优势，即可作为类型在模板参数传递，也可以在函数参数作为对象
//	PriceCompareOBJ pcobj;
//	pcobj(gds[0], gds[1]);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), pcobj);
//
//	EvaluationCompareOBJ ecobj;
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), ecobj);
//
//	// 如果我们还是价格降序，评价的降序，销量升序降序，综合升序降序
//	// 我们会发现，我们要写很多个函数或者是仿函数，有没有更好的解决方式呢？-》labmber
//
//	// 3.labmber表达式  ->相比以上两种方式简单方便,如果熟悉labmber语法之后，代码可读性更强
//	auto priceLess = [](const Goods& g1, const Goods& g2)->bool
//	{
//		return g1._price < g2._price;
//	};
//
//	// 返回值可以省略，但是建议写上
//	auto priceGreater = [](const Goods& g1, const Goods& g2)
//	{
//		return g1._price > g2._price;
//	};
//	priceLess(gds[0], gds[1]);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), priceLess);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), priceGreater);
//
//	// 其实实际中更多的都懒得取名字，直接用
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//	{return g1._price < g2._price; });
//
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//	{return g1._price > g2._price; });
//
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//	{return g1._evaluation < g2._evaluation; });
//
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//	{return g1._evaluation > g2._evaluation; });
//
//	return 0;
//}

class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};

int main()
{
	// 函数对象
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);

	// lamber
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
	r2(10000, 2);
	return 0;
}