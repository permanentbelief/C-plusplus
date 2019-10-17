#define _CRT_SECURE_NO_WARNINGS 1 
#include <assert.h>
#include <iostream>
using namespace std;
//// string 类的深浅拷贝问题
////namespace lth
////{
////	class string
////	{
////	public:
////		string()
////			:_str(new char[1])
////		{
////			*_str = '\0';
////		}
////		//string(const char* str = "\0")错误示范 可以的，结果正确。对C语言认识不够
//                                        ‘\0’  char不能给char*
////		//string(const char* str = nullptr)错误示范 strlen(str)又是空指针的解引用，发生错误
////
////		string(const char* str = "")
////			:_str(new char[strlen(str) + 1])
////		{
////			//已经拷贝了'\0'
////			strcpy(_str, str); //while(*dst++ = *src++_
////		}
//深浅拷贝问题：
//bit::string copy1(s1);
//cout << copy1.c_str() << endl;
//没写拷贝构造的话，编译器会自动生成一个拷贝构造函数，完成值拷贝（浅拷贝)
//两者都指向了 同一块空间
//
//copy属于main这个栈帧 出作用域得先调用它ed析构函数
////		~string()
////		{
////			delete[] _str;
////			_str = nullptr;
////		}
////		//string copy(s1)
////		string(const string&s)
////			:_str(new char[strlen(s._str)+1])//开了一样大的空间 再把数据拷贝下来 深拷贝
////		{
////			strcpy(_str, s._str);
////		}
////		//s1 = s2
////		//避免s1 = s1
////		string& operator=(const string& s)
////		{
////			if (this != &s)
////			{
////				delete[] _str;
////				_str = new char[strlen(s._str) + 1];
////				strcpy(_str, s._str);
////			}
////			return *this;
////		}
////		const char* c_str()
////		{
////			return _str;
////		}
////		char& operator[](size_t pos)
////		{
////			return _str[pos];
////		}
////	private:
////		char *_str;
////	};
////}
////int main()
////{
////	lth::string s1("hello world");
////	cout << s1.c_str() << endl;
////	s1[0] = 'x';
////	cout << s1.c_str() << endl;
////
////	lth::string copy1(s1);
////	cout << copy1.c_str() << endl;
////    string s2 = "world" 构造 + 拷贝构造 + 优化 单参数构造函数的类
////	copy1[0] = 'h';
////	cout << copy1.c_str() << endl;
////	cout << s1.c_str() << endl;
////
////
////	lth::string s2 = "change world";
////	s1 = s2;
////	cout << s1.c_str() << endl;
////	cout << s2.c_str() << endl;
////
////	system("pause");
////}
namespace lth
	//模拟实现 增删查改
{
	class string
	{
	public:
		typedef const char* const_iterator;
		typedef char* iterator;
		const_iterator begin() const
		{
			return _str;
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
			_size = strlen(str);
			_capacity = _size;
		}
		~string()
		{
			delete[] _str;
			_str = NULL;
			_capacity = _size = 0;
		}
		//string copy1(s1)
		string(const string& s)
			:_str(new char[(s._size) + 1])
			, _size(s._size)
			, _capacity(s._size)
		{
			strcpy(_str, s._str);
			
		}
		

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				_size = s._size;
				_capacity = s._capacity;
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		
		}
		void reserve(size_t n)//多开n个空间
		{
			
				char* tmp = new char[n+ _size + 1]; //这里调用的char* tmp 会调用析构函数释放吗？？
												    //这里得多开一个空间存放'\0’
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				//_size = _size + n;
				//_capacity = _capacity + n;
				_capacity = n+_size;
		
		
		}
	/*	void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[]
			}
		}*/
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity);
			}
			//数据插入进去
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';

		}
		void append(const char* str)
		{
			if (strlen(str) + _size > _capacity)
			{
				reserve(strlen(str) + _size - _capacity );

			}
			//我的方法
		/*	for (int i = 0; str[i] != '\0'; i++)
			{
				_str[_size++] = str[i];
			}
			_str[_size] = '\0';*/
			
			strcpy(_str + _size, str);//从_str+_size的位置开始将str拷贝过来
			_size += strlen(str);
		}
		//s1 += ch
		const string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const string& operator+=(const string& s)
		{
			append(s._str);
			return *this;
		}
		const string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void insert(size_t pos, char ch)
		{
			if (_capacity == _size)
			{
				reserve(_capacity * 2); //多开这么多个空间
			}
			// 指定的位置不同 方法一
			//for (int i = _size; i >= pos + 1; i--)
			//{
			//	_str[i] = _str[i- 1]; // 原来的'\0’被 整体后移的值覆盖住了 所以要重新添加'\0’
			//}
			for (int i = _size - 1; i >= pos; i--)
			{
				_str[i + 1] = _str[i];
			}
			_size += 1;
			_str[pos] = ch;
			_str[_size] = '\0';
		
		}
		void insert(size_t pos, const char* str)
		{
			int len = strlen(str);
			
			if (strlen(str) + _size > _capacity)
			{
				reserve(strlen(str) + _size - _capacity);
			}
			for (int i = _size + len; i >= pos + len; i--)
			{
				_str[i] = _str[i - len];
			}
		//	memcpy(_str + pos, str, sizeof(char)*len); 一步到位的方法 当然也可以用for循环
			for (int i = pos; i <= len + pos - 1; i++) // 拷贝str的len个数过去就好了
			{
				_str[i] = *(str++);
			}
			_size = len + _size;
		}
		bool operator>(const string & s)  const
		{
			const char* str1 = _str;
			const char* str2 = s._str;
			while (*str1&& *str2)
			{
				if (*str1 > *str2)
				{
					return true;
				}
				else if (*str1 < *str2)
				{
					return false;
				}
				else
				{
					++str1;
					++str2;
				}
			}
			if (*str1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
			
		bool operator==(const string& s) const
		{
			const char* str1 = _str;
			const char* str2 = s._str;
			while (*str1 && *str2)
			{
				if (*str1 != *str2)
				{
					return false;
				}
				else
				{
					++str1;
					++str2;
				}
			}
			if (*str1 || *str2)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}
		size_t find(char ch)
		{
			for (int i = 0; i <= _size; i++)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}
			return -1;
		}
		char find(const char* str) //子串
		{
			assert(str);
			const char* str1 = _str;
			//const char* str2 = str;
			while (*str1)
			{
				const char* str3 = str1 ;
				const char* str4 = str; //子串
				while ( (*str1) && (*str4 ) &&  *str4 == *str3)
				{
					str3++;
					str4++;
				}
				if ( str4 != NULL )
				{
					return *str1;
				}
				str1++;
			}
			return NULL;
		}
		string operator+(const string& s)
		{
			string tmp(*this);
			this->append(s._str);
			return tmp;

		}
		friend ostream& operator<<(ostream& out, const string& s)
		{
			out << s.c_str() << endl;
			return out;
		}
		friend istream operator>>(istream& in, const string& s)
		{
			//输入什么啊
		}
				// getline
		const char* c_str() const 
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		size_t size()
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;

		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	};
}
int main()
{
	lth::string s("woyou");
	s.append("money");
	cout << s << endl;
	cout << s.c_str() << endl;
	//s.append("11111111111111111111111");
	//cout << s.c_str() << endl;
	s.insert(4, 'A');
	cout << s.c_str() << endl;
	s.insert(4, "hello");
	cout << s.c_str() << endl;
	s.insert(4, "hello");
	cout << s.c_str() << endl;
	lth::string t(s);
	cout << t.c_str() << endl;
	cout << s.operator==(t) << endl;
	cout << s.operator>(t) << endl;
	cout << s.find('Z') << endl;
	lth::string s1("woyou");
	cout << s1 << endl;
	//lth::string s2("you");
	cout << s.find("you") << endl;

	//cout << s.c_str() << endl;
	//s.push_back('a');
	//cout << s.c_str() << endl;
	//s.push_back('b');
	//cout << s.c_str() << endl;

	//s.push_back('c');
	//cout << s.c_str() << endl;

	//s.push_back('d');
	//cout << s.c_str() << endl;

	//s.push_back('e');
	//cout << s.c_str() << endl;
	//




//	cout << s.c_str() << endl;

	system("pause");
}

////实现一个简单的string
////class my_string
////{
////private:
////	char* _str;
////public:
////	my_string(const char* str = "")
////		:_str(new char[strlen(str) + 1])
////	{
////		strcpy(_str, str);
////	}
////	//my_string s2(s1)
////	my_string(const my_string& s)
////		:_str(new char[strlen(s._str) + 1])
////	{
////		strcpy(_str, s._str);
////	}
////	my_string& operator=(const my_string& s)
////	{
////		if (this != &s)
////		{
////			delete[] _str;
////			_str = new char[strlen(s._str) + 1];
////			strcpy(_str, s._str);
////		}
////		return *this;
////	}
////	~my_string()
////	{
////		delete[] _str;
////	}
////};
//// 现代写法-> 小聪明 简单
//class my_string
//{
//private:
//	char* _str;
//public:
//	my_string(const char* str = "")
//		:_str(new char[strlen(str)+1])
//	{
//		strcpy(_str, str);
//	}
//	//my_string s2(s1)
//	my_string(const my_string&s)
//		:_str(nullptr)
//	{
//		my_string tmp(s._str);
//		swap(tmp._str, _str);
//	}
//	my_string& operator=(mystring s)
//	{
//		swap()
//	}
//	~my_string()
//	{
//		if (_str)
//			delete[] _str;
//	}
//}