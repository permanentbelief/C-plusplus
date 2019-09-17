#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 namespace lth   // ���������ռ��Ƿ�ֹ ����﷢����ͻ
{
	class string
	{
	private:
		char* _str;
	public:
		// ���캯��
		string(const char * str = "") // ���ַ�������'\0'������ȥ
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str); // �Ѿ�������'\0����ȥ

		}
		// ��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		//�������캯��  s1(s2)
		string (const string& s)
			: _str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		// ��ֵ�����   s1 = s2
		string& operator=(const string & s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str,s._str);
			}
			return *this;
		}

		char* c_str()
		{
			return _str;
		}
	};
 }
 int main()
 {
	 lth::string s1("hello");
	 cout << s1.c_str() << endl;
	 lth::string s2;
	 cout << s2.c_str() << endl;
	 lth::string s3(s1);
	// cout <<   << endl; // ��ô���ã����� ����ֱ�Ӷ����ʱ�� ��������
	 cout << s3.c_str() << endl;
	 cout << s2.c_str() << endl;
	 s2 = s1;
	 cout << s2.c_str() << endl;
	 system("pause");
 }