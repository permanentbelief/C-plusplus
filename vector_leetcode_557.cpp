#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
class Solution {
public:
	void reverseString(string s, int start, int end)
	{
		while (start < end)
		{
			swap(s[start], s[end]);
			start++;
			end--;
		}
	}
	string reverseWords(string s) {
		int count = 0;
		int t = 0;
		string::iterator it = s.begin();
		while (it != s.end())
		{

			count++;
			it++;
			if (*it == ' ')
			{
				reverseString(s, t, t + count);
				t = count;
				count = 0;
				it++;
			}

		}
		return s;

	}
};
