#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <assert.h>
using namespace std;

 namespace lth 
{
	 template <class T>
	
	 class vector
	 {
		
	 public:
		 typedef T* iterator;
		 vector()
			 :_start(nullptr)
			 , _finish(nullptr)
			 , _end_of_storage(nullptr)
		 {
		 }
		/* vector<vector<int>& v)
		 {
			 _start = new T[v.size()];
			 memcpy(_start, v._start, sizeof(T)*v.size());
			 _finish = v.size() + _start;
			 _end_of_storage = _start + v.size();
		 }*/
		 vector<T>& operator=(vector<T> v)
		 {
			 swap(v);
			 return *this;
		 }
		 ~vector()
		 {
			 if (_start)
			 {
				 delete[] _start;
				 _start = _finish = _end_of_storage = nullptr;
			 }
		 }
		 void swap(vector<T>& v)
		 {
			 swap(_start, v._start);
			 swap(_finish, v._finish);
			 swap(_end_of_storage, v._end_of_storage);
		 }
		 void resize(size_t n, const T&value = T()) //开辟n个空间 并完成初始化工作
		 {
			 if (n < size())
			 {
				 _finish = _start + n;
				 return;
			 }
			 if (n > capacity())
			 {
				 reverse(n); //开辟n个空间
			 }
			 //这里是中和两种情况 1. 最后一个地方在_end_of_storage 右边     2.最后一个地方在_end_of_storage与 finish 
			 // 然后再继续进行填值
			 while (_finish != _start + n)
			 {
				 *finish = val;
				 ++_finish;
			 }
		 }
		 void reserve(size_t n)
		 {
			 if (n > capacity())
			 {
				 size_t sz = size();
				 T* tmp = new T[n];
				
					 memcpy(tmp, _start, sizeof(T)*sz);
					 delete _start;
			
				 
				 _start = tmp;
				 _finish = tmp + sz;
				 _end_of_storage = tmp + n;
			 }
		
		 }
		 void push_back(const T& x)
		 {
			 if (capacity() == size())
			 {
				 size_t newcapacity = (capacity() == 0) ? 2 : capacity() * 2;
				 reserve(newcapacity);
			 }
			_start[size()] = x;
			 _finish++;                 //注意这里一定是先插入 后++  ++会使size()的值+1  插入到越界的地方
		 }
		 void insert(iterator pos, const T&x)
		 {
			 if (capacity() == size())
			 {
				 size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				 reserve(newcapacity);
			 }
			 iterator end = _finish;
			 while (end+1 != pos)
			 {
				 *(end + 1) = *end;
				 end--;
			 }
			 _finish++;  //在这里_finish++ 放在前面 和放在*pos = x 后面结果一样
			 *pos = x;
			
		 }
		 void erase(iterator pos)
		 {
			 assert(pos >= _start && pos < _start +size()); // 1 2
			 while (pos != _start + size())
			 {
				 *pos = *(pos + 1);
				 pos++;
			 }
			 _finish--;
			 
		 }
		 iterator begin()
		 {
			 return  _start;
		 }
		 iterator end() 
		 {
			 return _finish();
		 }
		 size_t size() 
		 {
			 return _finish - _start;
		 }
		 size_t capacity()
		 {
			 return _end_of_storage - _start;
		 }
		 T& operator[](size_t n)
		 {
			 return _start[n];
		 }
		 const T& operator[](size_t n) const
		 {
			 return _start[pos];
		 }
	 private:
		 iterator _start;
		 iterator _finish;
		 iterator _end_of_storage;


	 };
 }
 int main()
 {
	 lth::vector<int> l;
	 l.push_back(3);
	 l.push_back(4);
	 l.push_back(5);
	 l.push_back(6);
	 l.push_back(7);

	 lth::vector<int>::iterator iter = l.begin();
	 while (iter != l.end())
	 {
		 cout << *iter << " ";
		 ++iter;
	 }
	 cout << endl;

	 //有问题！！！
	/* for (auto e : l)
	 {
		 cout << e << " ";
	 }
	 cout << endl;
	 
	 lth::vector<int>::iterator iter =  l.begin();
	 while (iter != l.end())
	 {
		 cout << *iter << endl;
		 iter++;
	 }
	 cout << endl;*/

	
	 system("pause");
 }