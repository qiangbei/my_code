#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

void recursive_max_heap_shift_down(int *array,int start,int end);
void make_max_heap(int *array,int start,int end);
void nonrecursive_make_max_heap(int *array,int start,int end);
void  max_heap_shift_down(int *array,int start,int end);//����
void test_nonrecursive_max_heap(int *array,int n);
void heap_sort(int *array,int n);
int main()
{
	int array[9] = {4,3,7,2,1,6,5,9,8};

	cout<<"make_max_heap"<<endl;
	make_max_heap(array,0,9);
	for(int k = 0;k < 9;k++)
	{
		cout<<array[k]<<"  ";
	}
	cout<<endl;
	 
	for (int j = 9;j >1;j--)
	{
		swap(array[0],array[j-1]);
		
		recursive_max_heap_shift_down(array,0,j-1);//ԭ��������������С��д����j //���ӵ�8����ʼ
		cout<<"heap temp result:";
		for(int k = 0;k < j-1;k++)
		{
			cout<<array[k]<<" ";
		}
		cout<<endl;
	}
	cout<<"sort:";
	for(int k = 0;k < 9;k++)
	{
		cout<<array[k]<<"  ";
	}
	cout<<endl;
	/*
	for(int k = 1;k < 9;k++)
	{
		make_max_heap(array,k,8);
		cout<<array[k]<<endl;
	}
	*/
	int array_second[9] = {4,3,7,2,1,6,5,9,8};
	test_nonrecursive_max_heap(array_second,9);
	return 0;
}

//�ݹ�ķ�ʽ,����Ϊ[)����������Ϊ[]��ֻ�����������<end;
void recursive_max_heap_shift_down(int *array,int start,int end)//����
{
	int left_index = start*2+1;
	int right_index = start*2+2;
	int largest = start;//��Ľڵ�������������һ�����ڵ㣡
	if (left_index < end && array[left_index] > array[start])
	{
		largest = left_index ;
	}
	else
	{
		largest = start ;
	}
	
	if (right_index < end &&array[right_index] > array[largest])//���ڴ�ģ������ȱȽ����Ҵ�ģ����ڸ��ڵ�Ƚϣ�
	{
		largest = right_index;
	}

	if(largest != start) //������򽻻����Ҽ�����
	{
		 
		swap(array[largest],array[start]);
		//cout<<"array[largest]:"<<array[start]<<endl;
		recursive_max_heap_shift_down(array,largest,end);
	}
	
}

void make_max_heap(int *array,int start,int end)
{
	int len = end - start ;
	int parent = start + (len - 2)/2;//��һ�����ڵ�

	for (int i = parent; i >= start;i--)//����start�����и��ڵ㶼�õ���
	{
		recursive_max_heap_shift_down(array,i,end);//���ڵ�i
	}
}


//�ǵݹ�汾
void  max_heap_shift_down(int *array,int start,int end)//����
{
	int left_index = start*2+1;
	int right_index = start*2+2;
	int largest = start;//��Ľڵ�������������һ�����ڵ㣡
	
	while(left_index < end)
	{
		if (array[left_index] > array[start])
		{
			largest = left_index ;
		}
		else
		{
			largest = start ;//��Ϊ��ǰ���
		}
		
		if (right_index < end &&array[right_index] > array[largest]) 
		{
			largest = right_index;
		}
		if(largest != start) //������򽻻����Ҽ�����
		{
			swap(array[largest],array[start]);
			//����
			start = largest;
			left_index = 2*start + 1;
			right_index = left_index + 1;
		}
		else
		{
			break;
		}


	}

}

void nonrecursive_make_max_heap(int *array,int start,int end)
{
	int len = end - start ;
	int parent = start + (len - 2)/2;//��һ�����ڵ�

	for (int i = parent; i >= start;i--)//����start�����и��ڵ㶼�õ���
	{
		max_heap_shift_down(array,i,end);//���ڵ�i
	}
}

void heap_sort(int *array,int n)
{
	nonrecursive_make_max_heap(array,0,n);//�Ƚ��ѣ���һ�����ѶѶ��ŵ����

	for(int i = n-1;i >0;i--)
	{	
		swap(array[0],array[i]);//�������
		max_heap_shift_down(array,0,i);
	}
}

void test_nonrecursive_max_heap(int *array,int n)
{
	cout<<"original array:";
	for (int i = 0; i < n;i++)
	{
		cout<<array[i]<<"  ";
	}
	cout<<endl;
/*
	nonrecursive_make_max_heap(array,0,n);

	cout<<"max_heap array:";
	for (int j = 0; j < n;j++)
	{
		cout<<array[j]<<"  ";
	}
	cout<<endl;

	for (int k = n-1;k >= 1 ;k--)
	{
		swap(array[0],array[k]);
		max_heap_shift_down(array,0,k);//��һ�����л���
	}
	cout<<"sort:";
	for(int m = 0;m < n;m++)
	{
		cout<<array[m]<<"  ";
	}
	cout<<endl;
*/	

	cout<<"heap_sort:";

	heap_sort(array,n);

	for(int m = 0;m < n;m++)
	{
		cout<<array[m]<<"  ";
	}
	cout<<endl;
}
