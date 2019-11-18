#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "ÂòÆ±È«¼Û" << endl;
	}
};
class Student : public Person
{
public:
	 virtual void BuyTicket()
	{
		cout << "ÂòÆ±°ë¼Û" << endl;
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