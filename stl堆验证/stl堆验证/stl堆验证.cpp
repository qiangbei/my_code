#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

void verify_heap();
void top_k(int *array,int n,int k);
void max_top_k(int *array,int n,int k);//��ȡ��С��k����
int main()
{
	int array[9] = {4,3,7,2,1,6,5,9,8};
	//verify_heap();
	top_k(array,9,4);
	max_top_k(array,9,3);
	cout<<"small_top_k: ";
	for (int k = 0;k < 3;k++)
	{
		cout<<array[k]<<"  ";
	}
	cout<<endl;
	return 0;
}

void verify_heap()
{
	int array[9] = {4,3,7,2,1,6,5,9,8};

	make_heap(array,array+9);
	//make_heap(array,array+9,greater<int>());//С��

	for (int i = 0;i < 9;i++)
	{
		cout<<array[i]<<"  ";
	}
	cout <<endl;
	/*
	for (int j = 0;j < 9;j++)
	{
		pop_heap(array,array+9-j);
		cout<<array[9-j-1]<<" ";
	}
	cout <<endl;
	*/
	sort_heap(array,array+9);
	for (int k = 0;k < 9;k++)
	{
		cout<<array[k]<<"  ";
	}
	cout <<endl;

}

void top_k(int *array,int n,int k)
{
	assert(array);
	make_heap(array,array+n,greater<int>());
	
	int k_deal = k%n;
	cout<<"min_top_k:";

	for (int i = 0;i < k_deal;i++)
	{
		pop_heap(array,array+n-i,greater<int>());//ÿһ�����ü���greater<int>()
		cout<<array[n-1-i]<<" ";
	}
	cout<<endl;

}

void max_top_k(int *array,int n,int k)//��ȡ����k����
{
	assert(k < n);
	make_heap(array,array+k,greater<int>());

	for (int i = k; i < n;i++)//ע�⵱���±�����Ӱ�쵽heap
	{
		if (array[i] > array[0])
		{
			swap(array[i],array[0]);
			make_heap(array,array+k,greater<int>());
		}
	}
	
}