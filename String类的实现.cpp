#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>



#include <cassert>


using namespace std;

class String
{
public:
	typedef const char* const_Iterator;
	typedef char* Iterator;
	Iterator begin()
	{
		return _str;
	}
	Iterator end()
	{
		return _str + _size;
	}
	const_Iterator Begin() const
	{
		return _str;
	}
	const_Iterator End() const
	{
		return _str + _size;
	}
	String(const char* str = "")  //字符串有'\0’ 也可以写成"\0"
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str); // while(*dst++ = *src++)
		_size = strlen(str); // 不用+1.'\0' 不算它的有效字符
		_capacity = _size;  //  不用+1，最多能存多少个有效字符，真正的空间大小还要比_capacity大一个
	}
	~String()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}
	String(const String&s)
		:_str(new char[s._size + 1])
		, _size(s._size)  // 开 值一样大的空间
		, _capacity(s._size) //开 值一样大的空间
	{
		strcpy(_str, s._str);
	}
	const char* c_str()
	{
		return _str;
	}
	String& operator=(String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	const char& operator[](size_t pos) const
	{
		return _str[pos];
	}

	void push_back(char c)
	{
		if (_size == _capacity)
		{
			size_t newcapcity = _capacity == 0 ? 2 : _capacity*2 ;
			char* str = new char[newcapcity + 1];
			strcpy(str, _str);
			delete[] _str;
			_str = str;
			_capacity = newcapcity;
		}

		_str[_size] = c;
		_size++;
		_str[_size] = '\0';

	}

	void reserve(size_t n)  // 数据不够，开空间
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void append(const char* str)
	{
		int len = strlen(str);
		if (strlen(str) + _size > _capacity)
		{
			char* tmp = new char[strlen(str) + _size + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = strlen(str) + _size;
		}
		
		//方法一
		strcpy(_str + _size, str);
		//方法二
		//for (int i = _size; i < _size + len; i++)
		//{
		//	_str[i] = str[i - _size];
		//}
		_size += len;
		_str[_size] = '\0';
	}

	const String &operator += (char ch)
	{
		push_back(ch);
		return *this;

	}
	const String& operator += (const char* str)
	{
		append(str);
		return *this;
	}
	const String&  operator += (const String& s)
	{
		append(s._str);
		return *this;
	}

	void insert(size_t pos, char ch)
	{
		assert(pos < _size);
		
		if (_size == _capacity)
		{
			reserve(_capacity*2);
		}
		int end = _size;
		while (end >= (int)pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		_str[pos] = ch;
		++_size;
	}
	void insert(size_t pos, const char* str)
	{

	}
	bool operator>(const String& s)
	{
		const char* str1 = _str;
		const char* str2 = s._str;
		while (*str1 && *str2)
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
		else if (*str2)
		{
			return false;
		}
		else
		{
			return false;
		}
	}
	bool operator<(const String& s)
	{
		return  !(*this > s);
	}
	bool operator ==(const String& s)
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
			return false;
		return true;
	}
	bool operator>=(const String& s)
	{
		return *this > s || *this == s;
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

//实现一个简单的string 现代写法
class MyString
{
private:
	char* _str;
public:
	MyString(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	MyString(const MyString& s)
	{

	}

};
int main()
{
	/*String s1("12234")*/;
	//for (int i = 0; i < s1.size(); i++)
	//{
	//	
	//	cout << s1[i] << " ";
	//}
	//cout << endl;
	String s1("123");
	//s1.push_back('2');
	//s1.push_back('3');
	//s1.push_back('2');
	//s1.push_back('3');
	//s1.push_back('2');
	//s1.push_back('3');
	//s1.push_back('2');
	//s1.push_back('3');
	//cout << s1.c_str() << endl;
	//s1.append("asdadadadasddddddaaaaaaaaaaaaaaa");
	//s1 += "ABC";
	//cout << s1.c_str() << endl;
	s1.insert(0,'c');
	cout << s1.c_str() << endl;

	/*string s = "litianhao.sina.com.gz";
	size_t first = s.find('.');
	while (first != string::npos)
	{
		size_t second = s.find('.', first + 1);
		if (second != string::npos)
		{
			cout << s.substr(first,second - first) << endl;
		}
		else
		{
			cout << s.substr(first, s.size() - first) << endl;
		}
		first = second;
	}
	cout << s << endl;
	cout << s.c_str() << endl;*/
	system("pause");
}