#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

void recursive_max_heap_shift_down(int *array,int start,int end);
void make_max_heap(int *array,int start,int end);
void nonrecursive_make_max_heap(int *array,int start,int end);
void  max_heap_shift_down(int *array,int start,int end);//下溯
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
		
		recursive_max_heap_shift_down(array,0,j-1);//原先问题出在这里，不小心写成了j //即从第8个开始
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

//递归的方式,区间为[)，若想区间为[]则只需更改条件，<end;
void recursive_max_heap_shift_down(int *array,int start,int end)//下溯
{
	int left_index = start*2+1;
	int right_index = start*2+2;
	int largest = start;//大的节点索引，当做下一个父节点！
	if (left_index < end && array[left_index] > array[start])
	{
		largest = left_index ;
	}
	else
	{
		largest = start ;
	}
	
	if (right_index < end &&array[right_index] > array[largest])//大于大的（或者先比较左右大的，在于父节点比较）
	{
		largest = right_index;
	}

	if(largest != start) //不相等则交换，且继续！
	{
		 
		swap(array[largest],array[start]);
		//cout<<"array[largest]:"<<array[start]<<endl;
		recursive_max_heap_shift_down(array,largest,end);
	}
	
}

void make_max_heap(int *array,int start,int end)
{
	int len = end - start ;
	int parent = start + (len - 2)/2;//第一个父节点

	for (int i = parent; i >= start;i--)//包括start，所有父节点都得调整
	{
		recursive_max_heap_shift_down(array,i,end);//父节点i
	}
}


//非递归版本
void  max_heap_shift_down(int *array,int start,int end)//下溯
{
	int left_index = start*2+1;
	int right_index = start*2+2;
	int largest = start;//大的节点索引，当做下一个父节点！
	
	while(left_index < end)
	{
		if (array[left_index] > array[start])
		{
			largest = left_index ;
		}
		else
		{
			largest = start ;//作为当前大的
		}
		
		if (right_index < end &&array[right_index] > array[largest]) 
		{
			largest = right_index;
		}
		if(largest != start) //不相等则交换，且继续！
		{
			swap(array[largest],array[start]);
			//更新
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
	int parent = start + (len - 2)/2;//第一个父节点

	for (int i = parent; i >= start;i--)//包括start，所有父节点都得调整
	{
		max_heap_shift_down(array,i,end);//父节点i
	}
}

void heap_sort(int *array,int n)
{
	nonrecursive_make_max_heap(array,0,n);//先建堆，在一个个把堆顶放到最后

	for(int i = n-1;i >0;i--)
	{	
		swap(array[0],array[i]);//放置最后
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
		max_heap_shift_down(array,0,k);//下一个进行回溯
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
