#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

void test1()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(4);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::const_reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	auto pos = find(s.begin(), s.end(), 5);
	set<int>::iterator ret = s.find(2);
	if (ret != s.end())
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
	if (ret != s.end())
	{
		s.erase(ret);
	}
	s.erase(4);
	auto its = s.begin();
	while (its != s.end())
	{
		cout << *its << " ";
		its++;
	}
	cout << endl;
}

void test2()
{
	map<string, string>  dict;
	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(pair<string, string>("insert", "����"));
	dict.insert(pair<string, string>("string", "�ַ���"));
	dict.insert(make_pair("erase", "ɾ��"));
	dict.insert(make_pair("boom", "��ը"));
	map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		//pair<K,V>& operator*()
		cout << dit->first << "-" << dit->second << endl;
		// pair<K,V>* operator->()
		cout << (*dit).first << "-" << (*dit).second << endl;
		++dit;
	}
	cout << endl;

	string str;
	while (cin >> str)
	{
		auto ret = dict.find(str);
		if (ret != dict.end())
		{
			cout << ret->second << endl;
		}
		else
		{
			cout << "û���ҵ��˵���" << endl;
		}
	}
}

void test3()
{
	string strs[] = { "ƻ��", "�㽶", "�㽶","ƻ��","����" };
	map<string, int> countMap;
	for (auto str : strs)
	{
		map<string, int>::iterator ret = countMap.find(str);
		if (ret == countMap.end())
		{
			countMap.insert(make_pair(str,1));
		}
		else
		{
			ret->second++;
		}
	}
	map<string, int>::iterator ret = countMap.begin();
	while (ret != countMap.end())
	{
		cout << ret->first << ":" << ret->second << endl;
		ret++;
	}
	cout << endl;
}


void test4()
{
	string strs[] = { "ƻ��", "�㽶", "�㽶", "ƻ��", "����" };
	map<string, int> countMap;
	for (auto str : strs)
	{
		/*pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}*/
		countMap[str]++;
	}
	map<string, int>::iterator ret = countMap.begin();
	while (ret != countMap.end())
	{
		cout << ret->first << ":" << ret->second << endl;
		ret++;
	}
	cout << endl;
}

template <class K, class V>
inline pair<K, V> make_pair1(const K&k, const V&v)
{
	return pair<K, V>(k, v);
}
void test_map()
{
	string strs[] = { "ƻ��", "����", "��ݮ", "�ƹ�", "⨺���" };
	map<string, int> countMap;
	for (auto&e : strs)
	{
		map<string, int>::iterator ret = countMap.find(e);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			countMap.insert(make_pair1(e, 1));
		}
	}
	map<string, int>::iterator it = countMap.begin();
	while (it != countMap.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	cout << endl;
}

//[]��ʵ��
//template <class K, class V>
//inline V& operator[](const K& k)
//{
//	pair<map<K, V>::iterator, bool> ret = insert(make_pair(k, V()));
//	return ret.first->second;
//}

void test_map2()
{
	string strs[] = { "ƻ��", "����", "��ݮ", "�ƹ�", "⨺���" };
	map<string, int> countMap;
	for (auto& e : strs)
	{
		countMap[e]++;
	}
	countMap["�㽶"] = 5;

}

void test_map3()
{
	string strs[] = { "ƻ��", "����", "��ݮ", "��ݮ" };
	map<string, int> countMap;
	for (auto& e : strs)
	{
		pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	for (auto& e : countMap)
	{
		cout << e.first << "---" << e.second << endl;
		
	}
	cout << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test_map();
	//test_map2();
	test_map3();
	system("pause");
}