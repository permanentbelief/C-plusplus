#pragma once

#include <vector>
#include <iostream>
using namespace std;


template <class T, size_t InitNum = 100>
class ObjectPool
{
public:

	T* &NextObj(T* obj)
	{
		return *(T**)obj;
	}
	ObjectPool()
	{
		_NumSize = sizeof(T) > sizeof(T*) ? sizeof(T) : sizeof(T*);
		_start = (char*)malloc(sizeof(_NumSize)*InitNum);
		_end = _start + sizeof(_NumSize)*InitNum;
		_freeList = NULL;
	}
	T* New()
	{
		T* obj = nullptr;
		if (_freeList != nullptr)
		{
			obj = _freeList;
			_freeList = NextObj(obj);
		}
		else
		{
			if (_start == _end)
			{
				_start = (char*)malloc(InitNum * _NumSize);
				_end = _start + InitNum;
			}

			obj = (T*)_start;
			_start += _NumSize;
		}

		new(obj)T;
		return obj; 
	}
	

	void Delete(T* ptr)
	{
		ptr->~T();
		NextObj(ptr) = _freeList;
		_freeList = ptr;


	}

private:
	char* _start;
	char* _end;
	size_t _NumSize;
	
	T* _freeList;
};

void TestObjectPool()
{
	ObjectPool <int> pool;
	int *p1 = pool.New();
	int *p2 = pool.New();
	int *p3 = pool.New();

	pool.Delete(p1);
	pool.Delete(p2);
	pool.Delete(p3);

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	int*p4 = pool.New();
	int*p5 = pool.New();
	int*p6 = pool.New();

	cout << p4 << endl;
	cout << p5 << endl;
	cout << p6 << endl;

}