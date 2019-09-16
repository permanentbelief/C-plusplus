#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>

using namespace std;

//namespace bit 
//{
//	class string//库里的都是小写的 ，所以要命名空间隔离
//	{
//	public:
//		// 一般不会这样 直接在构造函数中给缺省值
//		//string()
//		//	//:_str(nullptr)
//		//	:_str(new char[1])
//		//{
//		//	*_str = '\0';
//		//}
//		// 错误示范
//		//string(const char* str = ‘\0’) 
//		//string(const char* str = "\0")  结果也对 strlen() 还是 0
//		string(const char* str = "") //注意这里！！ 一般给缺省值不能给(const char* str = nullptr)
//			//如果这样给的话， strlen函数会找'\0’解引用，程序就会崩溃
//			//:_str(str)
//			// 不是把常量上的值给我,而是重新开一块空间
//			:_str(new char[strlen(str) + 1])// strlen只算到'\0'，+1是把'\0’算上
//		{
//			strcpy(_str, str); // while(*dst++ = * src++) 已经拷贝'\0’
//		}
//		~string()
//		{
//			delete[] _str;
//		}
//		// string copy1(s1)
//		string(const string& s) //深拷贝
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// s1 = s3;
//		string& operator=(const string& s)
//		{
//			if (this != &s)// *this != s 为什么不可以？？
//			{
//				delete[] _str;
//				_str  = new char(strlen(s._str) + 1);
//				strcpy(_str, s._str);
//				
//			}
//			return *this;
//		}
//		const char* c_str()
//		{
//			return _str;
//		}
//		char& operator[](size_t pos)
//		{
//			return _str[pos];
//		}
//	private:
//		char* _str;
//	};
//}
//int main()
//{
//	// 创建的对象 s1为什么在堆上？？？？
//	bit::string s1("hello");
//	//s1[0] = 'x'; //访问内存的错误 hello是在常量区 不能修改 所以要重新开一块空间
//	//cout << s1.c_str() << endl;
//	//bit::string s2;
//	//cout << s2.c_str() << endl;// 此时是char*类型的空指针， cout把他当成一个字符串数组，直接去
//	//// 解引用那个值，直到遇到'\0’结束，存在解引用行为。找char*指向空间上的值，解引用程序就崩了
//	//bit::string copy1(s1);
//	//cout << copy1.c_str() << endl;//程序崩溃 出作用域，先调用析构函数释放空间，s1再次释放空间
//	//// 一段空间不能释放两次  浅拷贝，只是把copy1的_str也指向了s1的_str，所以要深拷贝
//	//// 默认生成的拷贝函数 是浅拷贝
//
//	//copy1[0] = 'h';
//	//cout << s1.c_str() << endl; // 指向同一块空间，copy1改变会影响s1的改变
//	//cout << copy1.c_str() << endl;
//
//	bit::string s3 = "world"; //单参数构造函数的优化
//	s1 = s3;
//	cout << s1.c_str() << endl; // 还是浅拷贝 上面s1的空间丢了-- 内存泄漏。 然后s3空间释放了两次，程序崩了
//	system("pause"); 
//	return 0;
//}

// string 的增删查改 
namespace bit
{
	class string//库里的都是小写的 ，所以要命名空间隔离
	{
	public:
		typedef const char* const_iterator;
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		// 一般不会这样 直接在构造函数中给缺省值
		//string()
		//	//:_str(nullptr)
		//	:_str(new char[1])
		//{
		//	*_str = '\0';
		//}
		// 错误示范
		//string(const char* str = ‘\0’) 
		//string(const char* str = "\0")  结果也对 strlen() 还是 0
		string(const char* str = "") //注意这里！！ 一般给缺省值不能给(const char* str = nullptr)
			//如果这样给的话， strlen函数会找'\0’解引用，程序就会崩溃
			//:_str(str)
			// 不是把常量上的值给我,而是重新开一块空间
			:_str(new char[strlen(str) + 1])// strlen只算到'\0'，+1是把'\0’算上
		{
			strcpy(_str, str); // while(*dst++ = * src++) 已经拷贝'\0’
			_size = strlen(str); // 不用+1 '\0’不算它的有效字符
			_capacity = _size; // 空间能存多少个 有效字符， 比他真正的空间大小还大一个
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		// string copy1(s1)
		string(const string& s) //深拷贝
			:_str(new char[s._size + 1]) // 也可以都是capacity 两种不同的方法
			, _size(s._size)
			, _capacity(s._size)
		{
			strcpy(_str, s._str);
		}

		// s1 = s3;
		string& operator=(const string& s)
		{
			if (this != &s)// *this != s 为什么不可以？？
			{
				delete[] _str;
				_str = new char(s._size + 1);
				strcpy(_str, s._str);
				_capacity = s._capacity;
				_size = s._size;

			}
			return *this;
		}
		const char* c_str()
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		size_t size()
		{
			return _size;
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				//不能用realloc  因为前面用的是new
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str); 
			if (_size + len > _capacity) //注意这里不加1，算已有的有效的空间 开空间时前面都多开了一个
			{
				// 扩容 扩差值
			}
			// 数据拷贝 '\0’后移
		}
		const string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		operator >
		operator <
		operator ==
		operator >=
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
//第一种方法 一样大的空间 一样的值
//第二种方法 只开与值一样大的空间
int main()
{
	bit::string s1("hello");
	// 原生指针  实际就是char*指针
	bit::string::iterator it1 = s1.begin(); //并不是所有的迭代器都是指针,现有接触的迭代器都是
	while (it1 != s1.end())//不能用小于(也没错在这里)因为数组的空间是连续的,但链表的前面节点的地址不一定小于后面节点的地址
	{
		cout << *it1 << " ";
		++it1;

	}
	cout << endl;
	for (auto e : s1)// 底层是迭代器， 满足迭代器的规范就可以 必须是s1.begin() s1.Begin()不可以
	{
		cout << e << " ";
	}
	system("pause");
}