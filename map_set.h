#include <map>
#include <set>
#include <string>
#include <queue>
#include <functional>

// set key -> ���ٲ����ڲ���
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
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
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

// map key/value -> �ֵ䡢ͳ�ƴ���
void test_map1()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(pair<string, string>("insert", "����"));
	dict.insert(pair<string, string>("string", "�ַ���"));

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
			cout << "û�д˵��ʣ�����������" << endl;
		}
	}
}

void test_map2()
{
	string strs[] = { "ƻ��", "�㽶", "�㽶", "ƻ��", "�㽶", "ƻ��", "�㽶", "�㽶", "��ݮ" };
	map<string, int> countMap;
	for (auto str : strs)
	{
		// 1.�� ++����
		// 2.���� insert pair<ˮ��,1>
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
	pair<string, int> p2("�㽶", 1);
}

void test_map3()
{
	string strs[] = { "ƻ��", "�㽶", "�㽶", "ƻ��", "�㽶", "ƻ��", "�㽶", "�㽶", "��ݮ" };
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
	string strs[] = { "ƻ��", "�㽶", "�㽶", "ƻ��", "�㽶", "ƻ��", "�㽶", "�㽶", "��ݮ" };
	map<string, int> countMap;
	for (auto str : strs)
	{
		countMap[str]++;  // С��ҵ->Ϊʲô��insert
	}

	countMap["����"];

	map<string, string> dict;
	dict["insert"];

	dict.insert(make_pair("left", "���"));
	// �����޸�
	dict.insert(make_pair("left", "ʣ��"));
	// �޸�
	auto dit = dict.find("left");
	dit->second = "ʣ��";

	// �޸�
	dict["left"] = "���";

	// ����+�޸�
	dict["sort"] = "����";


	//countMap.insert(pair<string, int>(k, map_type()));
	// �ȼ���
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
//	// 1.ͳ�Ƴ�ˮ�����ִ���
//	map<string, int> countMap;
//	for (auto& e: fruits)
//	{
//		countMap[e]++;
//	}
//	// 2.�ҳ������ϲ���Ե�ˮ��
//	// ���顢vector��deque(���Ƽ�)
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
//	// 1.ͳ�Ƴ�ˮ�����ִ���
//	map<string, int> countMap;
//	for (auto& e : fruits)
//	{
//		countMap[e]++;
//	}
//	// 2.�ҳ������ϲ���Ե�ˮ��
//	// ����ǰK����������һ��С��
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
	// 1.ͳ�Ƴ�ˮ�����ִ���
	map<string, int> countMap;
	for (const auto& e : fruits)
	{
		countMap[e]++;
	}
	// 2.�ҳ������ϲ���Ե�ˮ��  map������+keyȥ��
	multimap<int, string, greater<int>> sortMap;
	for (const auto& e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}

	// ���߲��÷º������÷�����������ű���
}


void test_map5()
{
	vector<string> v = { "ƻ��", "�㽶", "�㽶", "ƻ��", "�㽶", "ƻ��", "�㽶", "�㽶", "��ݮ", "����", "����", "����", "������","������", "������" };
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