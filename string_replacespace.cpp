#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
using namespace std;
//class Solution
//{
//public  :
//	string replaceSpace(string str) // 这块不行 所以就加个:
//	{
//		// write code here
//		string ret;
//		for (size_t i = 0; i < str.size(); i++)
//		{
//			if (str[i] == ' ')
//			{
//				ret += "%20";
//			}
//			if (str[i] != ' ')
//			{
//				ret += str[i];
//			}
//		}
//		return ret;
//	}
//};
//int main()
//{
//	//string s("hello world ");
//	cout << Solution::replaceSpace("hello world") << endl; // 这怎么调用啊？？
//	system("pause");
//}
 string replaceSpace(string str)
	{
		// write code here
	 string ret;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				ret += "%20";
			}
			if (str[i] != ' ')
			{
				ret += str[i];
			}
		}
		return ret;
	}
 int main()
 {
	 string s("hello world  ");
	 cout << replaceSpace(s) << endl;
	 system("pause");
 }