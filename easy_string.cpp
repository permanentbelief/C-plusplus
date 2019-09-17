#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
 namespace lth   // 定义命名空间是防止 与库里发生冲突
{
	class string
	{
	private:
		char* _str;
	public:
		// 构造函数
		string(const char * str = "") // 空字符串中有'\0'拷贝过去
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str); // 已经拷贝了'\0’过去

		}
		// 析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		//拷贝构造函数  s1(s2)
		string (const string& s)
			: _str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		// 赋值运算符   s1 = s2
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
	// cout <<   << endl; // 怎么调用？？？ 除了直接定义的时候 拷贝构造
	 cout << s3.c_str() << endl;
	 cout << s2.c_str() << endl;
	 s2 = s1;
	 cout << s2.c_str() << endl;
	 system("pause");
 }