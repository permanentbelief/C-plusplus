#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>

using namespace std;

//namespace bit 
//{
//	class string//����Ķ���Сд�� ������Ҫ�����ռ����
//	{
//	public:
//		// һ�㲻������ ֱ���ڹ��캯���и�ȱʡֵ
//		//string()
//		//	//:_str(nullptr)
//		//	:_str(new char[1])
//		//{
//		//	*_str = '\0';
//		//}
//		// ����ʾ��
//		//string(const char* str = ��\0��) 
//		//string(const char* str = "\0")  ���Ҳ�� strlen() ���� 0
//		string(const char* str = "") //ע������� һ���ȱʡֵ���ܸ�(const char* str = nullptr)
//			//����������Ļ��� strlen��������'\0�������ã�����ͻ����
//			//:_str(str)
//			// ���ǰѳ����ϵ�ֵ����,�������¿�һ��ռ�
//			:_str(new char[strlen(str) + 1])// strlenֻ�㵽'\0'��+1�ǰ�'\0������
//		{
//			strcpy(_str, str); // while(*dst++ = * src++) �Ѿ�����'\0��
//		}
//		~string()
//		{
//			delete[] _str;
//		}
//		// string copy1(s1)
//		string(const string& s) //���
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// s1 = s3;
//		string& operator=(const string& s)
//		{
//			if (this != &s)// *this != s Ϊʲô�����ԣ���
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
//	// �����Ķ��� s1Ϊʲô�ڶ��ϣ�������
//	bit::string s1("hello");
//	//s1[0] = 'x'; //�����ڴ�Ĵ��� hello���ڳ����� �����޸� ����Ҫ���¿�һ��ռ�
//	//cout << s1.c_str() << endl;
//	//bit::string s2;
//	//cout << s2.c_str() << endl;// ��ʱ��char*���͵Ŀ�ָ�룬 cout��������һ���ַ������飬ֱ��ȥ
//	//// �������Ǹ�ֵ��ֱ������'\0�����������ڽ�������Ϊ����char*ָ��ռ��ϵ�ֵ�������ó���ͱ���
//	//bit::string copy1(s1);
//	//cout << copy1.c_str() << endl;//������� ���������ȵ������������ͷſռ䣬s1�ٴ��ͷſռ�
//	//// һ�οռ䲻���ͷ�����  ǳ������ֻ�ǰ�copy1��_strҲָ����s1��_str������Ҫ���
//	//// Ĭ�����ɵĿ������� ��ǳ����
//
//	//copy1[0] = 'h';
//	//cout << s1.c_str() << endl; // ָ��ͬһ��ռ䣬copy1�ı��Ӱ��s1�ĸı�
//	//cout << copy1.c_str() << endl;
//
//	bit::string s3 = "world"; //���������캯�����Ż�
//	s1 = s3;
//	cout << s1.c_str() << endl; // ����ǳ���� ����s1�Ŀռ䶪��-- �ڴ�й©�� Ȼ��s3�ռ��ͷ������Σ��������
//	system("pause"); 
//	return 0;
//}

// string ����ɾ��� 
namespace bit
{
	class string//����Ķ���Сд�� ������Ҫ�����ռ����
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
		// һ�㲻������ ֱ���ڹ��캯���и�ȱʡֵ
		//string()
		//	//:_str(nullptr)
		//	:_str(new char[1])
		//{
		//	*_str = '\0';
		//}
		// ����ʾ��
		//string(const char* str = ��\0��) 
		//string(const char* str = "\0")  ���Ҳ�� strlen() ���� 0
		string(const char* str = "") //ע������� һ���ȱʡֵ���ܸ�(const char* str = nullptr)
			//����������Ļ��� strlen��������'\0�������ã�����ͻ����
			//:_str(str)
			// ���ǰѳ����ϵ�ֵ����,�������¿�һ��ռ�
			:_str(new char[strlen(str) + 1])// strlenֻ�㵽'\0'��+1�ǰ�'\0������
		{
			strcpy(_str, str); // while(*dst++ = * src++) �Ѿ�����'\0��
			_size = strlen(str); // ����+1 '\0������������Ч�ַ�
			_capacity = _size; // �ռ��ܴ���ٸ� ��Ч�ַ��� ���������Ŀռ��С����һ��
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		// string copy1(s1)
		string(const string& s) //���
			:_str(new char[s._size + 1]) // Ҳ���Զ���capacity ���ֲ�ͬ�ķ���
			, _size(s._size)
			, _capacity(s._size)
		{
			strcpy(_str, s._str);
		}

		// s1 = s3;
		string& operator=(const string& s)
		{
			if (this != &s)// *this != s Ϊʲô�����ԣ���
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
				//������realloc  ��Ϊǰ���õ���new
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str); 
			if (_size + len > _capacity) //ע�����ﲻ��1�������е���Ч�Ŀռ� ���ռ�ʱǰ�涼�࿪��һ��
			{
				// ���� ����ֵ
			}
			// ���ݿ��� '\0������
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
//��һ�ַ��� һ����Ŀռ� һ����ֵ
//�ڶ��ַ��� ֻ����ֵһ����Ŀռ�
int main()
{
	bit::string s1("hello");
	// ԭ��ָ��  ʵ�ʾ���char*ָ��
	bit::string::iterator it1 = s1.begin(); //���������еĵ���������ָ��,���нӴ��ĵ���������
	while (it1 != s1.end())//������С��(Ҳû��������)��Ϊ����Ŀռ���������,�������ǰ��ڵ�ĵ�ַ��һ��С�ں���ڵ�ĵ�ַ
	{
		cout << *it1 << " ";
		++it1;

	}
	cout << endl;
	for (auto e : s1)// �ײ��ǵ������� ����������Ĺ淶�Ϳ��� ������s1.begin() s1.Begin()������
	{
		cout << e << " ";
	}
	system("pause");
}