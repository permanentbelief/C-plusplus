#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;
#include "ObjectPool.h"

void test()
{
	int a = 0;
	int *p = &a;
	cout << p << endl;
	cout << p + 1 << endl;
	string str("abcdef");
	cout << sizeof(string) << endl;
	cout << sizeof(str) << endl;
	cout << sizeof(string*) << endl;

}

int main()
{
	//TestObjectPool();
	BenchMark();
	//test();
	system("pause");
}