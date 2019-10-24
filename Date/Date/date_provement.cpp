#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>


using namespace std;

bool Is_leapyear(int _year)
{
	if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int GetMonthDay(int _year, int _month)
{
	static int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (_month < 0 || _month >12)
	{
		cout << "输入的月份不符合要求" << endl;
		return 0;
	}
	if (Is_leapyear(_year) && _month == 2)
	{
		return 29;
	}
	else
	{
		return months[_month];
	}
}
class Date
{
	friend istream& operator>>(istream& in, const Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);
	
public:
	
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (!(year < 0 || month < 1 || month >12 || day < 1 || day > GetMonthDay(year, month)))
		{
			
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法输入" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	
		
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	
	void Print()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day;
		cout << endl;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+=(int days)
	{
		_day += days;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			if (_month == 12)
			{
				_month = 1;
				_year++;
			}
			else
			{
				_month += 1;
			}
		}
		return *this;
	}

	
	Date operator+(int days)// 需要拷贝构造两次 用+=(不需要调用拷贝构造函数)重载+
	{
		Date tmp = *this;
		tmp += days;
		return tmp;

		/*Date ret = *this;
		ret._day += days;
		while (ret._day > GetMonthDay(_year, _month))
		{
			ret._day -= GetMonthDay(_year, _month);
			if (ret._month == 12)
			{
				ret._month = 1;
				ret._year++;
			}
			else
			{
				ret._month += 1;
			}
		}
		return ret;*/
	}
	Date operator-=(int days)
	{
		_day -= days;
		while (_day <= 0)
		{
			if (_month == 1)
			{
				_month = 12;
				_year--;
			}
			else
			{
				_month--;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	Date operator-(int days)
	{
		Date tmp(*this);
		tmp -= days;
		return tmp;
	}
	
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp(*this);
		*this = *this - 1;
		return *this;
	}
	//正确的
	/*bool operator>(const Date& d)
	{
		if (this->_year > d._year)
		{
			return true;
		}
		else if (this->_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
		}
		return false;
	}*/
	//我写的 只判断false 
	bool operator>(const Date& d)const // 1222   3     3                 1222 3 3
	{
		if (_year < d._year)
		{
			return false;
		}
		else if (_year == d._year)
		{
			if (_month == d._month)
			{
				if (_day <= d._day)
				{
					return false;
				}
			}
			else if (_month < d._month)
			{
				return false;
			}
		}
		return true;

	}
	int dec_day(const Date& d)
	{
		int count = 0;
		while(*this < d)
		{
			++(*this);
			count++;
		}
		while(*this > d)
		{
			--(*this);
			count++;
		}
		return count;
	}
	bool operator>=(const Date& d)const
	{
		return *this > d || *this == d;
	}
	bool operator<(const Date& d)const
	{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)const
	{
		return !(*this > d);
	}
	bool operator==(const Date& d)const
	{
		return (_day == d._day && _year == d._year && _month == d._month);
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
private:
	int _year;
	int _month;
	int _day;
};
istream& operator>>(istream& in, const Date& d)
{
	in >> d._year;
	in >> d._month;
	in >> d._day;
	return in;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day;
	return out;
}
void test1()
{
	Date s(21, 21, 31);
	s.Print();
	Date tmp(s);
	tmp.Print();
	Date s1;
	s1.Print();

	Date d = s1;
	d.Print();
	tmp = s1;
	tmp.Print();

	cout << (s1 > s) << endl;
}

void test2()
{
	Date d1(2019, 10, 25);
	/*Date d2(2018,9,9);
	Date d3 = d2 += 20;
	d2.Print();
	d3.Print();*/
	(d1+ 7).Print();
	d1.Print(); //调用+= 代码复用 实现+ ， *this不变 d1不实现++;

	//d1.Print();
	//d2.Print();
	//cout << (d1 == d2) << endl;
}
void test3() //减法
{
	Date d1(2019, 2, 28);
	Date d2;
	(d1 -= 28).Print();
	Date d3;
	cout << "d3的默认值";
	d3.Print();
	(d3 - 27).Print();
	cout << "d3减完天数后d3的值";
	d3.Print();
	(d3 -= 27);
	cout << "d3-=27后，d3的值：";
	d3.Print();
	d1.Print();
	(d1++).Print();
	
	d1.Print();
	(++d1).Print();

	d1.Print();
	d2 = d1;
	d2.Print();
	d2 = (d1++);
	d1.Print();
	d2.Print();
}
void test4()
{
	Date d1(20, 1, 1);
	Date d2(20, 1, 31);
	cout << d1.dec_day(d2) << endl;
	/*d1.Print();
	(d1++).Print();
	d1.Print();

	d2.Print();
	(++d2).Print();
	d2.Print();*/
}
void test5()
{
	Date s(2019,2,39);
	cout << s << endl;
	

}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	system("pause");
	return 0;
}