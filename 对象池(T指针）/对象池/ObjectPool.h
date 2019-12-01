#pragma once

#include <vector>
#include <time.h>
#include <string>

// 对象池的实现 针对于一个知道类型的对象
//我们通过对象池 来比较普通向内存中申请空间
//和我们直接向我们的内存池中申请空间的性能对比
template <class T, size_t initNum = 10000> //设定内存池中取出的最大数量为100
class ObjectPool
{
public:
	ObjectPool()
	{
		//这一步的原因是如果对象是char类型的，只有一个字节，那么它里面就不能有4个字节存指向下一个
		//节点的指针了。因为char是一个字节，所以sizeof(T)要和sizeof(T*）比较一下，存取大的。
		//如果是对象T是char类型的，sizeof(char)<sizeof(char*),所以先给char对象开辟四个字节，
		//就可以存_freeList链表中下一个节点的地址了。尽管是char是一个字节的，存进去之后只占
		//最低的一个字节8位
		_itemSize = sizeof(T) < sizeof(T*) ? sizeof(T*) : sizeof(T);
		//给_freeList开辟这么大的空间进行维护，initNum*_itemSize：节点数*每个对象的字节数
		_start = (T*)malloc(initNum*_itemSize);
		_end = _start + initNum;
		_freeList = nullptr;  //给链表初始化为空
	}

	T*& Nex_Obj(T* obj)
	{
		//强转出T**在解引用肯定是T*,在32位和64位都可以表示对象的大小，
		//解决了平台不统一的问题，适应32位和64位机器
		// 比如对象是int ， int**在解引用是int*， 在32位下是4，在64位下是8.都可以平台统一

		//强转成（T**)在解引用后， 就是寻求下一个位置，到达_freeList的下一个位置
		return  *(T**)obj; 
	
	}
	T* New()
	{
		//1.如果freeList有对象，优先到freeList链表中获取 空间
		//2.要是freeList中没有对象，再到内存池中去取
		T* obj = nullptr;
		if (_freeList != nullptr)
		{
			obj = _freeList;
			_freeList = Nex_Obj(obj);
		}
		else
		{
			if (_start == _end) // 如果内存池中没有数据
			{
				_start = (T*)malloc(initNum *_itemSize);//再开initNum个空间
				_end = _start + initNum; //end指向末尾
			}
			// 空间足够 从内存池中取数据
			obj = _start;  //_start 是char* ，得强转成T*,才可以给T*类型的变量赋值
			//obj就是从内存池中取出的一段地址
			_start += 1; //向后移动一个节点的itemSize;
		}
		//new的 定位表达式
		new(obj)T;

		return obj;
	}
	void Delete(T* ptr)
	{
		ptr->~T(); //先调用析构函数清理空间上的资源

		Nex_Obj(ptr) = _freeList; //释放链表 将空间归还给_freeList, 头插归还
		_freeList = ptr;
	}

private:
	T* _start;
	T* _end;       //管理内存池指针
	size_t _itemSize; 

	T* _freeList;     //链表指针
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


void BenchMark()                //性能分析
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
	cout << "直接系统申请内存：" << end1 - begin1 << endl;


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

	cout << "Pool 申请内存： " << end2 - begin2 << endl;
}
