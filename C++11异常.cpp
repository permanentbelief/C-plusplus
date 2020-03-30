#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//double Division(int a, int b)
//{
//	//当b == 0时 抛异常， 抛出异常可以是任意类型的对象
//
//	if (b == 0)
//		throw  "分母不为0";
//	else
//		return  double(a) / double(b);
//}
//
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//
//int main()
//{
//	try{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unkown exception" << endl;
//	}
//	system("pause");
//}
//


//double Division(int a, int b)
//{
//	if (b == 0)
//	{
//		throw "Division by zero conditon!";
//	}
//	return (double)a / (double)b;
//}
//
//void Func()
//{
//	int *array = new int[10];
//
//	try{
//		int len = 0;
//		int time = 0;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;
//	}
//
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//
//	system("pause");
//}

//
//
//class Exception
//{
//protected:
//	char* _errmsg;
//	int _id;
//
//public:
//	Exception( char* err, int id)
//		:_errmsg(err)
//		, _id(id)
//	{
//	}
//
//	virtual void Print() const = 0;
//};
//
//class SqlException : public Exception
//{
//public:
//	SqlException( char* err, int id)
//		:Exception(err, id)
//	{}
//
//	virtual void Print() const
//	{
//		cout << "SqlException:" << _errmsg << "+" << _id << endl;
//	}
//};
//
//class CacheException : public Exception
//{
//};
//
//class HttpServerException :public Exception
//{
//public:
//	HttpServerException( char* err, int id)
//		:Exception(err, id)
//	{
//
//	}
//	virtual void Print() const 
//	{
//		cout << "HttpServerException: " << _errmsg << "+" << _id << endl;
//	}
//};
//#include <windows.h>
//void Start()
//{
//	if (rand() % 3 == 0)
//	{
//		throw SqlException("sql语句错误", 1);
//	}
//	if (rand() % 7 == 0)
//	{
//		throw SqlException("操作数据库没有权限\n", 2);
//	}
//
//	if (rand() % 5 == 0)
//	{
//		throw HttpServerException("网络错误", 3);
//	}
//
//	Sleep(1000);
//}
//
//int main()
//{
//	while(1)
//	{
//		try
//		{
//			Start();
//		}
//		catch (const Exception& e)
//		{
//			e.Print();
//		}
//		catch(...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//}