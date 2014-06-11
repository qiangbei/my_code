#include <iostream>
#include <algorithm>
#include <cassert>
#include "vld.h"
using namespace std;

int find_ugly(int k);
int main()
{

	int k;
	cin>>k;
	cout<<find_ugly(k)<<endl;

	return 0;
}

int find_ugly(int k)//1��Ϊ��һ������
{
	assert(k >= 0);
	
	int *array = new int[k];//��0��ʼ
	array[0] = 1;
	int index_2 = 0;
	int index_3 = 0;
	int index_5 = 0;
	int count = 1;
	while(count < k )
	{
		int min_val = min(array[index_2]*2,min(array[index_3]*3,array[index_5]*5));

		if (array[index_2]*2 == min_val) //������Сֵ��ǰ��һ�� ��2*3������
		{
			index_2++;
		}
		if (array[index_3]*3 == min_val)
		{
			index_3++;
		}
		if (array[index_5]*5 == min_val)
		{
			index_5++;
		}
		
		array[count] = min_val;
		count ++;

	}
	int res = array[k-1];
	delete array;
	return res;

}


bool is_ugly(int number)
{
	while (number % 2 == 0)
	{
		number = number / 2;
	}
	while (number % 3 == 0)
	{
		number = number / 3;
	}
	while (number % 5 == 0)
	{
		number = number / 5;
	}
	return number == 1;
}
