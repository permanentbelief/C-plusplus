#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <list>
using namespace std;

int main()
{
	//���캯��
	list<int> l1;
	list<int> l2(4, 100);
	list<int> l3(l2.begin(), l2.end());
	list<int> l4(l3);
	//������Ϊ����������l5
	int array[] = { 16, 2, 77, 29 };
	list<int> l5 (array, array + sizeof(array) / sizeof(int));

	//�õ�������ʽ��ӡl5�е�Ԫ��
	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto e : l5)
	{
		cout << e << " ";
	}
	cout << endl;
    //�����ӡ����
	cout << "�����ӡlist" << endl;
	for (list<int>::reverse_iterator it = l5.rbegin(); it != l5.rend(); it++)
	{
		//*it = 10;
		cout << *it << " ";
		

	}
	cout << endl;
	//cout << "const��������ӡlist" << endl;
	//for (list<int>::const_iterator it = l5.cbegin(); it != l5.cend(); it++)
	//{
	//	//*it = 10; //���� �����ǿ��޸ĵ���ֵ
	//	cout << *it << " ";
	//}
	//cout << endl;
	cout << "const�����������ӡlist" << endl;
	for (list<int>::const_reverse_iterator it = l5.crbegin(); it != l5.crend(); it++)
	{
		//*it = 10; const ���������ɱ��޸�
		cout << *it << " ";
	}
	system("pause");
	
}