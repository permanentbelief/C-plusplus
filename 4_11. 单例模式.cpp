#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


// 只能在堆上

class HeapOnly
{
public:
	static HeapOnly* GetHeapObj()
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}
private:
	HeapOnly()
	{
		cout << "HeapOnly()" << endl;
	}
	HeapOnly(const HeapOnly& h) = delete;
};
class A
{
public:
	static A& GetA()
	{
		return A();
	}
private:
	A()
	{}
	//C++ 98直接就定义成私有，类外不能访问
	A(const A& a);

	//C++11 就直接将拷贝构造给屏蔽掉
	//A(const A& a) = delete;     
};
int main()
{
	cout << &A::GetA() << endl;
	cout << &A::GetA() << endl;
	system("pause");
}
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
	//StackOnly(StackOnly& s);

};
//int main()
//{
//	StackOnly s = StackOnly::CreateObject();
//	cout << &s << endl;
//	StackOnly ss(s);
//	cout << &ss << endl;
//	//cout << &StackOnly::CreateObject() << endl;
//	//cout << &(StackOnly::CreateObject().CreateObject()) << endl;
//	//cout << &StackOnly::CreateObject() << endl;
//	system("pause");
//}
class StackOnly1
{
public:
	StackOnly1()
	{}
private:
	//定制专属的operator new 和delete,但是我不实现，你就没办法new了
	void * operator new(size_t size);
	void operator delete(void* p);

};

//int main()
//{
//	StackOnly1*p = new StackOnly1;
//	delete p;
//}
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{

	}
};

//class A :public NonInherit
//{
//	A()
//	{
//
//	}
//};
//class A final
//{
//
//};

//int main()
//{
//	
//	HeapOnly* newheap = HeapOnly::GetHeapObj();
//	//HeapOnly newheap1(*newheap);
//	HeapOnly* s;
//	s = newheap;  //还需探讨
//	system("pause");
//}


//单例模式




//class Singleton
//{
//public:
//	static Singleton& GetInstance()
//	{
//		return _sInst;
//	}
//private:
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//
//	static Singleton _sInst;
//};
//
//Singleton Singleton::_sInst;
//
//int main()
//{
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	system("pause");
//}

//#include <mutex>
//class Singleton
//{
//public:
//	static Singleton& GetInstance()
//	{
//		//双检查锁的效率问题
//		if (_spInst == nullptr)
//		{
//			//_smtx.lock();
//			if (_spInst == nullptr)
//			{
//				_spInst = new Singleton;
//			}
//			//_smtx.unlock();
//		}
//
//		return *_spInst;
//	}
//
//	// 一般没有必要释放对象，进程结束后以后自动释放
//	// 但是可以提供主动释放的接口
//	static void DelInstance()
//	{
//		_smtx.lock();
//		if (_spInst == nullptr)
//		{
//			delete _spInst;
//			_spInst = nullptr;
//		}
//		_smtx.unlock();
//	}
//private:
//	// 构造函数私有化
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//
//	static Singleton* _spInst;
//	static mutex _smtx;
//};
//
//Singleton* Singleton::_spInst = nullptr;
//mutex Singleton::_smtx;


//int main()
//{
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//
//	system("pause");
//}

//int main()
//{
//
//	int i = 10;
//	//隐式类型转换
//	double d = static_cast<double>(i); //类型相近，相关类型
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	//显示的强制类型转换
//	int address = reinterpret_cast<int>(p);
//
//	cout << p << endl;
//	cout << address << endl;
//
//
//	volatile const int a = 2;
//	int *p1 = const_cast<int*>(&a); 
//	*p1 = 3;
//	cout << a << endl;
//	system("pause");
//
//
//}

//class A
//{
//public:
//	virtual void f()
//	{}
//
//	int _a;
//};
//
//class B : public A
//{
//	int _b;
//};
//
//void fun(A* pa)
//{
//
//}
//
//int main()
//{
//	A* pa = new A;
//	B* pb = dynamic_cast<B*>(pa);
//	cout << pb << endl;
//	system("pause");
//}

typedef void(*FUNC)();

//int DoSomething(int i)
//{
//	cout << "DoSomething" << endl;
//	return i;
//}
//
//int main()
//{
//	FUNC f = reinterpret_cast<FUNC> (DoSomething);
//	f();
//	system("pause");
// }
