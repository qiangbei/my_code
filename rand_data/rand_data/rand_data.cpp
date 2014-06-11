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
	srand((unsigned int)time(NULL));//���ܷ��ں����ڣ�ֻ����һ�Σ�
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

int rand_5()//rand3 ���� rand5
{
	int num;
	
	
	do 
	{
		num = 3*(rand()%3) + rand()%3;
	} while (num >= 5);
	
	return num ;
}

int rand_4()//rand5  -- ���� rand_4
{
	int num;
	do 
	{
		num = rand()%5;
	} while (num >= 4); //����

	return num;
}

int find_n(int n)//n����һ���� 1/n�ĸ���,ǰ�᲻֪��n���ܴ�С���
{
	int count = 1;//����Ϊ0
	int select = 0;
	while( count <= n)//�˴�ֻ���˳�һ��������ʵ�������֪��n��С,�ر���������
	{
		if (rand()%count == 0)
		{
			select = count;
		}
		count++;
	}
	return select-1;
}