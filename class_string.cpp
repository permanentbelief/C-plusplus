#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//namespace lth
//{
//	class string
//	{
//	private:
//		char* _str;
//	public:
//		//string()// 构造函数
//		//	:_str(new char[1])
//		//{
//		//	*_str = '\0';
//		//}
//		string(const char* str = "")
//			:_str(new char[strlen(str) + 1])
//		{
//			// 已经拷贝'\0’
//			strcpy(_str, str); // while(*dst++ == *src++)
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		string(const string&s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//		// s1= s2 
//		string& operator=(const string& s) //出了作用域还在 带引用
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//				
//				//strcpy(_str, s._str); // 如果_str空间不够 会怎么办？
//				//free(s._str);
//			}
//			return *this;
//		}
//		char* c_str()
//		{
//			return _str;
//		}
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//	};
//}
//
//
//int main()
//{
//	lth::string s("hello");
//	cout << s.c_str() << endl;
//	lth::string t(s);
//	cout << t.c_str() << endl;
//	lth::string r;
//	cout << r.c_str() << endl;
//	r = t;
//	cout << r.c_str() << endl;
//
//	lth::string s1("hello");
//	s1[0] = 'x';
//	cout << s1.c_str() << endl;
//
//	lth::string copy1(s1);
//	cout << copy1.c_str() << endl;
//
//	copy1[0] = 'h';
//	cout << s1.c_str() << endl;
//	cout << copy1.c_str() << endl;
//	lth::string s2 = "world";
//	s1 = s2;
//	cout << s1.c_str() << endl;
//	system("pause");
//	return 0;
//}
namespace lth
{
	class string
	{
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
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
		const_iterator end() const
		{
			return _str + _size;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_str(new char[strlen(str) +1 ])
		{
			strcpy(_str, str);
			_size = strlen(str);
			_capacity = _size;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//string copy1(s1)
		string(const string&s)
			:_str(new char[strlen(s._str)+1])
			, _size(s._size)
			, _capacity(s._size) // 这个为什么不是s.capacity
		{
			//delete[] _str;
			strcpy(_str, s._str);

		}
		// s1 = s2
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
		const char* c_str()
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
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
		//reverse 扩容
		void reverse(size_t n)
		{
			if (n > _capacity)
			{
				char* new_str = new char[n+1];
				strcpy(new_str, _str);
				delete [] _str;
				_str = new_str;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//扩容
				reverse(_capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0'; // '\0'向后移动
		}
		// s1.append("111");
		void append(const char* str)
		{
			size_t len = strlen(str);
			size_t n = len + _size;
			if (n > _capacity)
			{
				reverse(n); // reverse中已把n置为_capacity
			}// 1 2 3 4 
			strcpy(_str + _size, str);//在_str+size位置处开始拷贝str
			_size += len;
		}
		//s1+= ch
		const string & operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		const string& operator+=(const string&s)
		{
			append(s._str);
			return *this;
		}
		void insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_capacity == _size)
			{
				reverse(_size+1);
			}
			// 方法1
			int end = _size +1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}
		void insert(size_t pos, const char* str)
		{
			int str_len = strlen(str);
			if (_size + str_len > _capacity)
			{
				reverse(_size + str_len); 
			}						   //  _str  9           str  str_len = 4
			int end = _size + str_len ; // lthchishi    i    laok
			while (end > pos)		//pos        7
			{
				_str[end ] = _str[end - str_len];
				end--;
			}
			//_str[_size + str_len] = '\0';
			for (int i = 0; i < str_len; i++)
			{
				_str[pos++] = str[i];
			}
		}
		bool operator>(const string& s) const
		{

		}
		bool operator==(const string& s) const
		{

		}
		bool operator>=(const string& s) const
		{

		}
		size_t find(char ch)
		{

		}
		size_t find(const char* str)
		{

		}
		//operator+
	};
}
//void test1()
//{
//	lth::string s1("hello");
//	cout << s1.c_str() << endl;
//	lth::string copy1(s1);
//	cout << copy1.c_str() << endl;
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		s1[i] = 'A';
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	lth::string::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//void test2()
//{
//	lth::string s("hello");
//	cout << s.capacity() << endl;
//
//	s += "world";
//	cout << s.c_str() << endl;
//	cout << s.capacity() << endl;
//	s += '!';
//	cout << s.capacity() << endl;
//	cout << s.size() << endl;
//	cout << s.c_str() << endl;
//}

void test3()
{
	lth::string s1(" change world");
	cout << s1.c_str() << endl;

	s1.insert(0, 'H');
	cout << s1.c_str() << endl;
	s1.insert(0, 'w');
	cout << s1.c_str() << endl;
	s1.insert(14, '2');
	cout << s1.c_str() << endl;
	s1.insert(13, "wo ai ni");
	cout << s1.c_str() << endl;
}
int main()
{
	//test1();
	//test2();
	 test3();
	system("pause");
}