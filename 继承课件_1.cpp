#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;
// �̳и���
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
//	int _stuid; //ѧ��
//
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; //����
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
//	//���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person * pp = &sobj;
//	Person& rp = sobj;
//
//	// ��������ܸ�ֵ�����������
//	//sobj = pobj;
//
//	//�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &pobj;
//	Student* ps1 = (Student*)pp;
//	ps1->_No = 10;
//
//	pp = &pobj; // ����ָ�� ָ�������
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
	string _name = "С����";
	int _num = 111;

};