#include <iostream>
#include <vld.h>
using namespace std;
int get_pos(int num,int count);
void radix_sort(int *array,int n,int base,int max_num);
void counting_sort(int *array,int n);

int main()
{
	int A[10] = {12,23,34,48,51,17,16,15,19,15};
	radix_sort(A,10,10,2);
	 
	for(int m = 0; m < 10;m++)//回收
	{
		cout<<A[m]<<"  ";
    }
	cout<<endl;
	int b[10] = {2,3,4,8,1,7,6,5,9,5};
	counting_sort(b,10);
	for(int m = 0; m < 10;m++) 
	{
		cout<<b[m]<<"  ";
	}
	return 1;
}


int get_pos(int num,int count)
{
	int temp = 1 ;
	for(int i = 1;i <= count;i++)
	{
		temp *=10;
	}
	//int temp[10] = {1,10,100,1000,1000,10000,100000,1000000,10000000，100000000};//等等查表
	return num/temp%10;//取某一位数，最好的方式查表！
}

//BASE 可以设置成固定的 0- 9，最大值可以给定，或自己给10最大
void radix_sort(int *array,int n,int base,int max_num)
{
	
	int *count = new int[base];//基数即为桶子数
	int *p_array = new int[n];

	for(int i = 0; i < max_num;i++)
	{
		memset(p_array,0,sizeof(int)*n);
		memset(count,0,sizeof(int)*base);

		for(int k = 0; k < n;k++)//初始化count遍利一次
		{
		  count[get_pos(array[k],i)]++;
		  
		}
 
		for(int k = 1; k < base;k++)//初始化count遍利一次
		{
		   count[k] += count[k-1];  //右边界！
		}
	
		//for(int j = 0; j <= n-1;j++)//分配从末尾开始！否则出错！！！
		for (int j = n-1; j >= 0;j--)
		{	 
			p_array[count[get_pos(array[j],i)]-1] = array[j];
			count[get_pos(array[j],i)]-- ;//索引值减少
		}
		
		for(int m = 0; m < n;m++) 
		{
			array[m] = p_array[m];
		}
	}
	 
	delete [] count;//资源释放的正确!
	delete [] p_array; 
}

void counting_sort(int *array,int n)
{

	int *count = new int[10];//基数即为桶子数
	int *p_array = new int[n];

	memset(count,0,sizeof(int)*10);
	for(int k = 0; k < n;k++)//初始化count遍利一次
	{
		count[array[k]]++;

	}

	for(int k = 1; k < 10;k++)//初始化count遍利一次
	{
		count[k] += count[k-1];  //右边界！

	}

	//for(int j = 0; j <= n-1;j++)//分配从末尾开始！否则出错！！！
	for (int j = n-1; j >= 0;j--)
	{	 
		p_array[count[array[j]]-1] = array[j];
		count[array[j]]-- ;//索引值减少
	}

	for(int m = 0; m < n;m++) 
	{
		array[m] = p_array[m];
	}
 

	delete [] count;//资源释放的正确!
	delete [] p_array; 
}