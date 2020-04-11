#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


// ֻ���ڶ���

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
	//C++ 98ֱ�ӾͶ����˽�У����ⲻ�ܷ���
	A(const A& a);

	//C++11 ��ֱ�ӽ�������������ε�
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
	//����ר����operator new ��delete,�����Ҳ�ʵ�֣����û�취new��
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
//	s = newheap;  //����̽��
//	system("pause");
//}


//����ģʽ




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
//		//˫�������Ч������
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
//	// һ��û�б�Ҫ�ͷŶ��󣬽��̽������Ժ��Զ��ͷ�
//	// ���ǿ����ṩ�����ͷŵĽӿ�
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
//	// ���캯��˽�л�
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
//	//��ʽ����ת��
//	double d = static_cast<double>(i); //����������������
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	//��ʾ��ǿ������ת��
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
