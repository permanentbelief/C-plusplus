#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//ģ���������

//template <unsigned int n> struct Sum_Solution
//{
//	enum Value
//	{
//		N = Sum_Solution<n - 1>::N + n
//	};
//};
//
//template<>  struct Sum_Solution <1>
//{
//	enum Value { N = 1 };
//};
//
//int main()
//{
//
//	cout << Sum_Solution<100>::N   << endl;
//	system("pause");
//
//}

//template <class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//
//void Test()
//{
//	char *p1 = "hello";
//	char *p2 = "hello ";
//
//	if (IsEqual(p1, p2))
//	{
//		cout << "���" << endl;
//	}
//	else
//		cout << "�����" << endl;
//}
//int main()
//{
//	Test();
//	system("pause");
//}


//template <class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//
////��char*���͵��ػ�
//template<>
//bool IsEqual<char*>(char*& left, char*& right)
//{
//	if (strcmp(left,right) == 0)
//		return true;
//	return false;
//}


//template <class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1,T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int,char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//
//int main()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//	system("pause");
//}

template <class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1,T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};


//�����ػ�

template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1,int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

// ��������ƫ�ػ�Ϊָ������
template <class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data() { cout << "Data<T1*,T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};


//��������ƫ�ػ�Ϊ��������
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//	Data(  const T1& d1, const T2& d2)
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//
//private:
//	 const T1 & _d1;
//	 const T2 & _d2;
//};
//
//int main()
//{
//	Data <double, int> d1;
//	Data <int*, double*> d2;
//	Data <int&, int&> d3(1,3);
//	system("pause");
//}
//
