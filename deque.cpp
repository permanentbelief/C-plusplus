#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>

#include <deque>
using namespace std;
void PrintDeque(const deque<int>& d)
{
	for (const auto& e : d)
	{
		cout << e << " ";
	}
	cout << endl;
}
//����deque�Ĺ��캯��
void TestDeque1()
{
	//����յ�˫�˶���
	deque<int> d1;

	//��10��ֵΪ5��Ԫ�ع���˫�˶���
	deque<int> d2(10, 5);
	PrintDeque(d2);
	// ����������乹��˫�˶���
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3);

	//��d3��������d4
	deque<int> d4(d3);
	PrintDeque(d4);
	PrintDeque(d4);
}
// ����deque�ĵ�����
void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int>d(array, array + sizeof(array) / sizeof(array[0]));

	//�����������ӡdeque��Ԫ��
	for (auto it = d.cbegin(); it != d.cend(); ++it)
	{
		cout << *it << " ";
	}
		
	cout << endl;

	//��������������ӡdeque��Ԫ��
	for (auto it = d.crbegin(); it != d.crend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void TestDeque3()
{
	// �б��ʼ��
	deque<int>d1{ 3, 4, 5 };
	//��deque��β������5��ͷ������1������ӡ
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;
	d1.emplace_back(7);
	d1.emplace_front(1);
	PrintDeque(d1);

	//��deque��beginλ�ò���Ԫ��0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);

	//ɾ��deque���ײ���β��Ԫ��
	d1.pop_front();
	d1.pop_back();
	PrintDeque(d1);
	d1.erase(d1.begin());
	d1.erase(d1.end()-1);//ɾ��β��Ԫ�����±���end-1��
	PrintDeque(d1);
}
int main()
{
	//TestDeque1();
	//TestDeque2();
	TestDeque3();
	system("pause");
}