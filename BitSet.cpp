#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <bitset>
using namespace std;

void TestBit()
{
	bitset<100> t;
	t.set(1);
	t.set(50);
	cout << t.size() << endl;  //位图中的大小
	cout << t.count() << endl; //位图中1的个数
	if (t.test(50))
		cout << "是1" << endl;
	else
		cout << "是0" << endl;
	if (t.test(2))
		cout << "2是1" << endl;
	else
		cout << "2是0" << endl;

	t.reset(50); //置0
	cout << t.count() << endl;
	if (t.test(50))
		cout << "50是1" << endl;
	else
		cout << "50是0" << endl;
}

int main()
{
	TestBit();
	system("pause");
}