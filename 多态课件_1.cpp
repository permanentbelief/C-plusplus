#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊȫ��" << endl;
	}
};
class Student : public Person
{
public:
	 virtual void BuyTicket()
	{
		cout << "��Ʊ���" << endl;
	}
};
void Func(Person &people)
{
	people.BuyTicket();
}
int main()
{
	Person Mike;
	Func(Mike);

	Student Johnson;
	Func(Johnson);
	system("pause");
}