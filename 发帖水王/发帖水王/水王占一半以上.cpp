#include <iostream>
#include <cassert>
using namespace std;

unsigned int find_id(unsigned int *array,unsigned int n);
unsigned int find_half_id(unsigned int *array,unsigned int n);
void find_3_more(unsigned int *array,unsigned int n,unsigned int *sel);

int main()
{
	unsigned int a[7] = {1,2,1,1,0,1,3};
	 
	cout<< find_id(a,7)<<endl;//assert(find_id(a,7) == 1);
	
	unsigned int b[6] = {1,2,1,1,0,3};
	cout<< find_half_id(b,6)<<endl;

	unsigned int c[6] = {1,2,3,1,0,1};
	cout<< find_half_id(c,6)<<endl;
	
	unsigned int d[11] = {0,2,3,4,2,3,4,8,3,4,2};
	unsigned int sel[3];
	find_3_more(d,11,sel);
	cout<<sel[0]<<"  ";
	cout<<sel[1]<<"  ";
	cout<<sel[2]<<"  ";
	cout<<endl;
	return 0;
}

//����һ�����ϵ�ˮ������
unsigned int find_id(unsigned int *array,unsigned int n)
{
	unsigned int sel = 0;
	unsigned int count = 0;

	for(unsigned int i = 0;i < n;i++)
	{
		if (count == 0)//��ǰ����Ϊ��ѡ�룡
		{
			sel = array[0];
		}
		else
		{
			if (sel == array[i])
			{
				count++;
			}
			else
			{
				count--;
			}
		
		}
	}
	
	return sel;
}

//����һ���ˮ��
//˼·��һ��Ļ����ض�Ϊż�������һ��Ԫ��Ҫô��ˮ����Ҫô����
//����ǣ���ÿ��Ԫ�ض������Ƚϣ����ΪN/2������N-1��Ԫ�ظ�����һ�����ϵ�ˮ��һ������
unsigned int find_half_id(unsigned int *array,unsigned int n)
{
	assert((n&1) == 0);
	unsigned int count = 0;
	
	for(unsigned int i = 0;i < n;i++)
	{
		if (array[i] == array[n-1])
		{
			count++;
		}
	}
	return count >= n/2 ? array[n-1] : find_id(array,n-1);

}

//3��������ID,ÿ������1/4. �����һ�����ϵ�ˮ����Ϊ���ƣ���
void find_3_more(unsigned int *array,unsigned int n,unsigned int *sel)
{
	unsigned int count[3] ;
	memset(sel,0,sizeof(unsigned int)*3);
	memset(count,0,sizeof(unsigned int)*3);
	for(unsigned int i = 0;i < n;i++)
	{
		if (count[0] == 0)//3��ĳ����ѡΪ0������ѡ�룬����
		{
			count[0] = 1;
			sel[0] = array[i];
		}
		else if (count[1] == 0)
		{
			count[1] = 1;
			sel[1] = array[i];
		}
		else if (count[2] == 0)
		{
			count[2] = 1;
			sel[2] = array[i];
		}
		else
		{
			if (sel[0] == array[i])//��ĳ����ѡ��ͬ
			{
				count[0]++;
			}
			else if (sel[1] == array[i])
			{
				count[1]++;
			}
			else if (sel[2] == array[i])
			{
				count[2]++;
			}
			else //û��û3����ѡ�е�һ��������
			{
				count[0]--;
				count[1]--;
				count[2]--;
			}

		}

	}
}