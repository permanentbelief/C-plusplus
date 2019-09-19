#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	// ��һ�ֱ�����ʽ �����±������[]
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	// �ڶ��ֱ�����ʽ ��Χfor ��ʵ�ײ���ǵ�����
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	// �����ֱ�����ʽ ������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	// ������ �Ӻ���ǰ���� �Ӻ���ǰ���
	// ��ȡ����һ��λ�� ��end()ԭ����λ����ͬ
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	// ע��rbeginָ�����vector���һ��Ԫ�ص���һλ��
	// ��ʵ���ȼ��� �ڽ����÷���
}
void test_vector2()
{
	//���캯��
	vector<int> v2;
	vector<int> v3(4, 100);
	vector<int> v4(v3.begin(), v3.end());//���������г�ʼ��
	vector<int> v5(++v3.begin(), --v3.end()); //��������ʼ��ֻ��λ�ò�ͬ
}
void test_vector3()
{
	cout << int() << endl;
}
void test_vector4()
{
	vector<int> v;
	v.reserve(100); //capacity����100�����ռ���֪�����ٿռ�ʱ����ǰ���ã��������ݴ���������Ч�� ���Ҳ�������
	v.resize(100); // capacity �� size��������100 ͬʱ���ʼ������ȱʡֵ���ϡ�
}
void test_vector5()
{
	vector<int> v; //   size  capacity
	v.resize(10);  //     10     10
	v.resize(20);  //     20     20
	v.resize(10);  //     10     20
}
void test_vector6()
{
	int a[] = { 1, 2, 3, 4 };
	//ָ�������Ȼ�ĵ�����
	vector<int>v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	auto pos = find(v.begin(), v.end(), 3);
	//cout << pos << endl;
	v.insert(pos, 30);
	//v.erase(pos); ������ʧЧ
}
int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	test_vector6();
	system("pause");
}