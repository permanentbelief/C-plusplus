#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // ����
	int _age = 18; // ����
};
// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��
//Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�����
//Print���Կ�����Ա�����ĸ��á�
class Student : public Person
{
protected:
	int _stuid; // ѧ��
};
class Teacher : public Person
{
protected:
	int _jobid; // ����
};
int main()
{
	Student s;
	Teacher t; s.Print();
	t.Print();
	system("pause");
	return 0;
}