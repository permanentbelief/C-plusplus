#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	/*if(nums.size() == 0)
	{
	return 0;
	}*/
	int count = 0;
	int j = 0;
	for (int i = 0; i < nums.size() - 1; i++)  // 为什么nums[i]为什么访问不到！！ 
	{
		if (nums[i] == nums[i + 1]) 
		{
			for (int k = i; k < nums.size() - 1; k++)
			{
				nums[k] = nums[k + 1];
			}
			j++;

		}

	}
	for (int i = 0; i < nums.size() - j ; i++)
	{
		count++;
	}
	return count;
}
int main()
{
	vector<int> v ;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	//v.push_back(2);
	//v.push_back(3);
	cout << removeDuplicates(v) << endl;
	system("pause");

}
//int FindGreatestSumOfSubArray(vector<int> array)
//{
//
//	int max1 = 0;
//	//int max  = 0;
//	int tmp_i = 0;
//	int f_max = 0; //算出从arr[i]开始区间上最大的数
//	vector<int> tmp(array);//// 1 -2 3 10 -4 7 2 -5     // 17
//	for (int i = 0; i < array.size(); i++)
//	{
//		max1 = array[i];
//		f_max = array[i];
//		for (int j = i + 1; j < array.size(); j++)
//		{
//			max1 += array[j];
//			if (f_max < max1)
//			{
//				f_max = max1;
//			}
//
//		}
//		tmp[tmp_i] = f_max;
//		tmp_i++;
//	}
//	int max = tmp[0];
//	for (size_t i = 0; i < tmp.size() - 1; i++)
//	{
//		max = tmp[i];
//		if (tmp[i] < tmp[i + 1])
//		{
//			max = tmp[i + 1];
//		}
//		else
//		{
//			max = tmp[i];
//		}
//	}
//	return tmp[0];
//}// 1 -2 3 10 -4 7
//int main()
//{
//	vector<int>s;
//	s.push_back(1);
//	s.push_back(-2);
//	s.push_back(3);
//	s.push_back(10);
//	s.push_back(-4);
//	s.push_back(7);
//	s.push_back(2);
//	s.push_back(-5);
//	cout << FindGreatestSumOfSubArray(s) << endl;
//	system("pause");
//
//
//}
//namespace lth
//{
//	template< class  T>
//	
//	class vector
//	{
//	public:
//		typedef T* iterator; //迭代器在这里是指针 可以是char* int*
//		// 构造函数
//		vector()
//			:_start(nullptr)
//			, _finish(nullptr)
//			, _end_of_stage(nullptr)
//		{
//
//		}
//		vector
//	private:
//		T* _start;
//		T* _finish;
//		T* _end_of_stage;
//		
//	}
//}