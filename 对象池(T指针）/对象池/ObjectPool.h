#pragma once

#include <vector>
#include <time.h>
#include <string>

// ����ص�ʵ�� �����һ��֪�����͵Ķ���
//����ͨ������� ���Ƚ���ͨ���ڴ�������ռ�
//������ֱ�������ǵ��ڴ��������ռ�����ܶԱ�
template <class T, size_t initNum = 10000> //�趨�ڴ����ȡ�����������Ϊ100
class ObjectPool
{
public:
	ObjectPool()
	{
		//��һ����ԭ�������������char���͵ģ�ֻ��һ���ֽڣ���ô������Ͳ�����4���ֽڴ�ָ����һ��
		//�ڵ��ָ���ˡ���Ϊchar��һ���ֽڣ�����sizeof(T)Ҫ��sizeof(T*���Ƚ�һ�£���ȡ��ġ�
		//����Ƕ���T��char���͵ģ�sizeof(char)<sizeof(char*),�����ȸ�char���󿪱��ĸ��ֽڣ�
		//�Ϳ��Դ�_freeList��������һ���ڵ�ĵ�ַ�ˡ�������char��һ���ֽڵģ����ȥ֮��ֻռ
		//��͵�һ���ֽ�8λ
		_itemSize = sizeof(T) < sizeof(T*) ? sizeof(T*) : sizeof(T);
		//��_freeList������ô��Ŀռ����ά����initNum*_itemSize���ڵ���*ÿ��������ֽ���
		_start = (T*)malloc(initNum*_itemSize);
		_end = _start + initNum;
		_freeList = nullptr;  //�������ʼ��Ϊ��
	}

	T*& Nex_Obj(T* obj)
	{
		//ǿת��T**�ڽ����ÿ϶���T*,��32λ��64λ�����Ա�ʾ����Ĵ�С��
		//�����ƽ̨��ͳһ�����⣬��Ӧ32λ��64λ����
		// ���������int �� int**�ڽ�������int*�� ��32λ����4����64λ����8.������ƽ̨ͳһ

		//ǿת�ɣ�T**)�ڽ����ú� ����Ѱ����һ��λ�ã�����_freeList����һ��λ��
		return  *(T**)obj; 
	
	}
	T* New()
	{
		//1.���freeList�ж������ȵ�freeList�����л�ȡ �ռ�
		//2.Ҫ��freeList��û�ж����ٵ��ڴ����ȥȡ
		T* obj = nullptr;
		if (_freeList != nullptr)
		{
			obj = _freeList;
			_freeList = Nex_Obj(obj);
		}
		else
		{
			if (_start == _end) // ����ڴ����û������
			{
				_start = (T*)malloc(initNum *_itemSize);//�ٿ�initNum���ռ�
				_end = _start + initNum; //endָ��ĩβ
			}
			// �ռ��㹻 ���ڴ����ȡ����
			obj = _start;  //_start ��char* ����ǿת��T*,�ſ��Ը�T*���͵ı�����ֵ
			//obj���Ǵ��ڴ����ȡ����һ�ε�ַ
			_start += 1; //����ƶ�һ���ڵ��itemSize;
		}
		//new�� ��λ���ʽ
		new(obj)T;

		return obj;
	}
	void Delete(T* ptr)
	{
		ptr->~T(); //�ȵ���������������ռ��ϵ���Դ

		Nex_Obj(ptr) = _freeList; //�ͷ����� ���ռ�黹��_freeList, ͷ��黹
		_freeList = ptr;
	}

private:
	T* _start;
	T* _end;       //�����ڴ��ָ��
	size_t _itemSize; 

	T* _freeList;     //����ָ��
};

//void TestObjectPool()
//{
//	ObjectPool<int> pool;
//	int *p1 = pool.New();
//	int *p2 = pool.New();
//	int *p3 = pool.New();
//
//	pool.Delete(p1);
//	pool.Delete(p2);
//	pool.Delete(p3);
//
//	cout << p1 << endl;
//	cout << p2 << endl;
//	cout << p3 << endl;
//
//	int *p4 = pool.New();
//	int *p5 = pool.New();
//	int *p6 = pool.New();
//
//	pool.Delete(p4);
//	pool.Delete(p5);
//	pool.Delete(p6);
//
//	cout << p4 << endl;
//	cout << p5 << endl;
//	cout << p6 << endl;
//}


void BenchMark()                //���ܷ���
{
	size_t n = 1000000;
	
	vector<string*>v1;
	v1.reserve(n);
	size_t begin1 = clock();
	for (size_t i = 0; i < n; i++)
	{
		v1.push_back(new string);
	}
	for (size_t i = 0; i < n; i++)
	{
		delete v1[i];
	}
	size_t end1 = clock();
	v1.clear();
	cout << "ֱ��ϵͳ�����ڴ棺" << end1 - begin1 << endl;


	vector<string*>v2;
	v2.reserve(n);
	ObjectPool<string> pool;
	size_t begin2 = clock();

	for (size_t i = 0; i < n; i++)
	{
		v2.push_back(pool.New());
	}
	for (size_t i = 0; i < n; i++)
	{
		pool.Delete(v2[i]);
	}
	size_t end2 = clock();

	v2.clear();

	cout << "Pool �����ڴ棺 " << end2 - begin2 << endl;
}
