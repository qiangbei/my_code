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
	 
	for(int m = 0; m < 10;m++)//����
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
	//int temp[10] = {1,10,100,1000,1000,10000,100000,1000000,10000000��100000000};//�ȵȲ��
	return num/temp%10;//ȡĳһλ������õķ�ʽ���
}

//BASE �������óɹ̶��� 0- 9�����ֵ���Ը��������Լ���10���
void radix_sort(int *array,int n,int base,int max_num)
{
	
	int *count = new int[base];//������ΪͰ����
	int *p_array = new int[n];

	for(int i = 0; i < max_num;i++)
	{
		memset(p_array,0,sizeof(int)*n);
		memset(count,0,sizeof(int)*base);

		for(int k = 0; k < n;k++)//��ʼ��count����һ��
		{
		  count[get_pos(array[k],i)]++;
		  
		}
 
		for(int k = 1; k < base;k++)//��ʼ��count����һ��
		{
		   count[k] += count[k-1];  //�ұ߽磡
		}
	
		//for(int j = 0; j <= n-1;j++)//�����ĩβ��ʼ�������������
		for (int j = n-1; j >= 0;j--)
		{	 
			p_array[count[get_pos(array[j],i)]-1] = array[j];
			count[get_pos(array[j],i)]-- ;//����ֵ����
		}
		
		for(int m = 0; m < n;m++) 
		{
			array[m] = p_array[m];
		}
	}
	 
	delete [] count;//��Դ�ͷŵ���ȷ!
	delete [] p_array; 
}

void counting_sort(int *array,int n)
{

	int *count = new int[10];//������ΪͰ����
	int *p_array = new int[n];

	memset(count,0,sizeof(int)*10);
	for(int k = 0; k < n;k++)//��ʼ��count����һ��
	{
		count[array[k]]++;

	}

	for(int k = 1; k < 10;k++)//��ʼ��count����һ��
	{
		count[k] += count[k-1];  //�ұ߽磡

	}

	//for(int j = 0; j <= n-1;j++)//�����ĩβ��ʼ�������������
	for (int j = n-1; j >= 0;j--)
	{	 
		p_array[count[array[j]]-1] = array[j];
		count[array[j]]-- ;//����ֵ����
	}

	for(int m = 0; m < n;m++) 
	{
		array[m] = p_array[m];
	}
 

	delete [] count;//��Դ�ͷŵ���ȷ!
	delete [] p_array; 
}