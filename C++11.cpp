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
//	//C++11ʹ���˳�ʼ���б�ʹ���ʼ����C++98�޷�����ͨ������Ҫѭ����ֵ
//	vector<int> v = { 1, 3, 5, 7, 9 };
//	
//	//�������͵ĳ�ʼ��
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

//RTTI ����ʱ����ʶ�� 
// typeid ֻ�ܲ鿴���Ͳ�����������������
// dynamic_cast ֻ��Ӧ���ں����麯���ļ̳���ϵ��


//decltype ���ݱ��ʽ��ʵ���������ݳ��������ʱ���õ�����



//�Ƶ���������ֵ������

void* GetMemory(size_t size)
{
	return malloc(size);
}
//
//int main()
//{

	// �Ƶ���������

	/*cout << typeid(decltype(GetMemory)).name() << endl;

	cout << typeid(decltype(GetMemory(9.00))).name() << endl;*/
	//// �Ƶ���������
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

//C++���ڿ��������������һЩĬ�ϵĳ�Ա������
// ���캯�� �������캯���� ��������أ�����������&��const&���ء��ƶ����졢�ƶ���������Ⱥ���


//class A
//{
//public:
//	A() = default;
//
//	// ��ʾȱʡ���캯�����ɱ���������
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
	// void bar() final; // ������û��bar�麯�����Ա���д
};

class B final : A  //ָ��B�ǲ����Ա��̳е�
{
	//void foo();  //Error: ��A���Ѿ���final�ˣ������Ա��̳�
	//void foo() override; // Error�� ��A���Ѿ���final�� 
};

//class C : B  //�Ѿ���final��
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
//	//a��b������ֵ
//	//��ֵ�ȿ��Է���=�����Ҳ���Է���=���Ҳ�
//
//	a = b;
//	b = a;
//
//	const int c = 30;
//
//	// c = a;// Eorro c���ܷ���=��ߣ�����c������ֵ
//
//	cout << &c << endl;
//
//	
//    //	b + 1 = 2;
//	// ����ʧ�ܣ� b+1�Ľ��ֻ��һ����ʱ������û�о�������ƣ�Ҳ����ȡ��ַ
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