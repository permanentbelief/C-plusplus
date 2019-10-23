#define _CRT_SECURE_NO_WARNINGS 1 
#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <cstdbool>

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
int Get_day(int _year, int _month)
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
public:
	/*friend ostream&(ostream& out,const Date& d)
	{
	out << d._day << d._month << d._day << endl;
	return out;
	}*/

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		if (year < 0 || month < 1 || month >12 || day < 1 || day > GetMonthDay(year, month))
		{
			cout << "非法输入" << endl;
		}
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

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
	Date operator+(int days)
	{
		/*int sum_day = days + _day;
		while (sum_day > Get_day(_year, _month))
		{
			sum_day -= Get_day(_year, _month); 两种调用方式：Date d2 = d1+10  (d1+200).Print()
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
		return *this;*/
		Date ret = *this; //拷贝构造
		ret._day += day;
		while

	}
	Date operator-(int days)
	{
		int dec_day = _day - days;
		while (dec_day < 0)
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
			dec_day += Get_day(_year, _month);
		}
		return *this;
	}
	int operator-(const Date& d);
	Date& operator++()
	{
		*this = *this + 1;
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
		*this = *this - 1;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp(*this);
		*this = *this - 1;
		return *this;
	}
	/*bool operator>(const Date& d)const
	{
		if (_year < d._year)
		{
			return false;
		}
		if (_year == d._year)
		{
			if (_month == d._month)
			{
				if (_day <= d._day)
				{
					return false;
				}
			}
			if (_month <= d._month)
			{
				return false;
			}
		}
		return true;

	}*/*/
	bool operator<(const Date& d)const
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day < d._day)
				{
					return true;
				}

			}
		}
		return false;
	}
	bool operator>=(const Date& d)const
	{
		return *this > d || *this == d;
	}
	//bool operator<(const Date& d)const
	//{
	//	return !(*this >= d);
	//}
	bool operator<=(const Date& d)const
	{
		return !(*this > d);
	}
	bool operator==(const Date& d)const
	{
		return _day == d._day && _year == d._year && _month == d._month;
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
int main()
{
	Date s(21, 21, 31);


	system("pause");
	return 0;
}