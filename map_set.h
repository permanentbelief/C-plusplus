#include <map>
#include <set>
#include <string>
#include <queue>
#include <functional>

// set key -> 快速查找在不在
void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(2);
	s.insert(4);

	// [begin, end)
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::iterator ret = s.find(2);
	if (ret != s.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

	//if (ret != s.end())
	//{
	//	s.erase(ret);
	//}
	s.erase(20); // ->it = find ->erase(it)
	s.erase(2);

	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// map key/value -> 字典、统计次数
void test_map1()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(pair<string, string>("string", "字符串"));

	/*map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		cout << (*dit).first <<":"<<(*dit).second << endl;
		++dit;
	}
	cout << endl;*/

	//auto dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	// pair<K,V>& operator*()
	//	cout << (*dit).first << ":" << (*dit).second << endl;

	//	// pair<K,V>* operator->()
	//	cout << dit->first << ":" << dit->second << endl;

	//	++dit;
	//}
	//cout << endl;

	string str;
	while (cin>>str)
	{
		auto ret = dict.find(str);
		if (ret != dict.end())
		{
			cout << ret->second << endl;
		}
		else
		{
			cout << "没有此单词，请重新输入" << endl;
		}
	}
}

void test_map2()
{
	string strs[] = { "苹果", "香蕉", "香蕉", "苹果", "香蕉", "苹果", "香蕉", "香蕉", "草莓" };
	map<string, int> countMap;
	for (auto str : strs)
	{
		// 1.在 ++次数
		// 2.不在 insert pair<水果,1>
		//map<string, int>::iterator ret = countMap.find(str);
		auto ret = countMap.find(str);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			//pair<string, int> p1(str, 1);
			//countMap.insert(p1);
			countMap.insert(pair<string, int>(str, 1));
		}
	}

	pair<string, int> p1;
	pair<string, int> p2("香蕉", 1);
}

void test_map3()
{
	string strs[] = { "苹果", "香蕉", "香蕉", "苹果", "香蕉", "苹果", "香蕉", "香蕉", "草莓" };
	map<string, int> countMap;
	for (auto str : strs)
	{
		//pair<map<string, int>::iterator, bool> ret = countMap.insert(pair<string, int>(str, 1));
		auto ret = countMap.insert(pair<string, int>(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
}
//template<class K, class V>
//inline pair<K, V> make_pair(const K& k, const V& v)
//{
//	return pair<K, V>(k, v);
//}

void test_map4()
{
	string strs[] = { "苹果", "香蕉", "香蕉", "苹果", "香蕉", "苹果", "香蕉", "香蕉", "草莓" };
	map<string, int> countMap;
	for (auto str : strs)
	{
		countMap[str]++;  // 小作业->为什么？insert
	}

	countMap["西瓜"];

	map<string, string> dict;
	dict["insert"];

	dict.insert(make_pair("left", "左边"));
	// 不能修改
	dict.insert(make_pair("left", "剩余"));
	// 修改
	auto dit = dict.find("left");
	dit->second = "剩余";

	// 修改
	dict["left"] = "左边";

	// 插入+修改
	dict["sort"] = "排序";


	//countMap.insert(pair<string, int>(k, map_type()));
	// 等价于
	//countMap.insert(make_pair(k, map_type()));

	/*cout << string() << endl;
	cout << int() << endl;*/
}

struct CountCompare
{
	bool operator()(const pair<string, int>& l, const pair<string, int>& r)
	{
		return l.second > r.second;
	}
};

//void GetFavoriteFruit(const vector<string>& fruits, size_t k)
//{
//	// 1.统计出水果出现次数
//	map<string, int> countMap;
//	for (auto& e: fruits)
//	{
//		countMap[e]++;
//	}
//	// 2.找出大家最喜欢吃的水果
//	// 数组、vector、deque(不推荐)
//	//vector<pair<string, int>> v(countMap.begin(), countMap.end());
//	vector<pair<string, int>> v;
//	for (auto& e : countMap)
//	{
//		v.push_back(e);
//	}
//
//	// O(N*logN)
//	sort(v.begin(), v.end(), CountCompare());
//
//	for (size_t i = 0; i < k; ++i)
//	{
//		cout << v[i].first << ":" << v[i].second << endl;
//	}
//}

//void GetFavoriteFruit(const vector<string>& fruits, size_t k)
//{
//	// 1.统计出水果出现次数
//	map<string, int> countMap;
//	for (auto& e : fruits)
//	{
//		countMap[e]++;
//	}
//	// 2.找出大家最喜欢吃的水果
//	// 最大的前K个，创建成一个小堆
//	priority_queue<pair<string, int>, vector<pair<string, int>>, CountCompare> pq;
//	size_t i = 0;
//	for (auto& e : countMap)
//	{
//		if (i < k)
//		{
//			pq.push(e);
//			++i;
//		}
//		else
//		{
//			// O(logK)*N
//			if (e.second > pq.top().second)
//			{
//				pq.pop();
//				pq.push(e);
//			}
//		}
//	}
//}

void GetFavoriteFruit(const vector<string>& fruits, size_t k)
{
	// 1.统计出水果出现次数
	map<string, int> countMap;
	for (const auto& e : fruits)
	{
		countMap[e]++;
	}
	// 2.找出大家最喜欢吃的水果  map是排序+key去重
	multimap<int, string, greater<int>> sortMap;
	for (const auto& e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}

	// 或者不用仿函数，用反向迭代器倒着遍历
}


void test_map5()
{
	vector<string> v = { "苹果", "香蕉", "香蕉", "苹果", "香蕉", "苹果", "香蕉", "香蕉", "草莓", "西瓜", "榴莲", "榴莲", "火龙果","火龙果", "火龙果" };
	GetFavoriteFruit(v, 3);
}


void test_set2()
{
	multiset<int> ms;
	ms.insert(3);
	ms.insert(1);
	ms.insert(3);
	ms.insert(4);
	ms.insert(2);

	for (const auto& e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
}