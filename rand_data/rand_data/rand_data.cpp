#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int rand_5();
int rand_4();
int find_n(int n);
int main()
{
	srand((unsigned int)time(NULL));//不能放在函数内，只能用一次！
	int count[5] = {0,0,0,0,0};
	int find_arr[10];
	memset(find_arr,0,sizeof(int)*10);

	for (int i = 0;i < 10000 ;i++)
	{
		count[rand_5()] ++;
		find_arr[find_n(10)]++;
	}
	for (int i = 0;i < 5 ;i++)
	{
		cout<<count[i]<<"  ";
	}
	cout<<endl;
	for (int i = 0;i < 10 ;i++)
	{	
		cout<<find_arr[i]<<"  ";
	}
	cout<<endl;
	return 0;
}

int rand_5()//rand3 产生 rand5
{
	int num;
	
	
	do 
	{
		num = 3*(rand()%3) + rand()%3;
	} while (num >= 5);
	
	return num ;
}

int rand_4()//rand5  -- 》》 rand_4
{
	int num;
	do 
	{
		num = rand()%5;
	} while (num >= 4); //丢弃

	return num;
}

int find_n(int n)//n个找一个数 1/n的概率,前提不知道n的总大小情况
{
	int count = 1;//不能为0
	int select = 0;
	while( count <= n)//此处只是退出一个条件，实际情况不知道n大小,特别是流对象
	{
		if (rand()%count == 0)
		{
			select = count;
		}
		count++;
	}
	return select-1;
}