#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;
// 继承概念
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "ahao";
//	int _age = 18;
//};
//class Student : public Person
//{
//protected:
//	int _stuid; //学号
//
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; //工号
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	system("pause");
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name <<"wang hu"<< endl;
//	}
//protected:
//	string _name; 
//private:
//	int _age;
//};
//class Student : public Person
//{
//protected:
//	int _stunum;
//};
//int main()
//{
//	Student s;
//	//s.Print();
//	system("pause");
//}
//class Person
//{
//protected:
//	string _name; 
//	string _sex;
//	int _age;
//};
//class Student : public Person
//{
//public:
//	int _No;
//};
//void Test()
//{
//	Student sobj;
//
//	//子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person * pp = &sobj;
//	Person& rp = sobj;
//
//	// 基类对象不能赋值给派生类对象
//	//sobj = pobj;
//
//	//基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &pobj;
//	Student* ps1 = (Student*)pp;
//	ps1->_No = 10;
//
//	pp = &pobj; // 父类指针 指向父类兑现
//	Student* ps2 = (Student*)pp;
//	ps2->_No = 10;
//}
//
//int main()
//{
//
//}
class Person
{
protected:
	string _name = "小李子";
	int _num = 111;

};