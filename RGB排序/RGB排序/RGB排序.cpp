#include <iostream>
#include <cstdlib>
using namespace std;

void rgb_sort(char *array,unsigned int n);

int main()
{			  //RRRRRGGGGGBBBB
	char a[] = "BRGGGRRBBGRBRG";
			  //RRRRRGGGGGGGBBBBB
	char b[] = "GBRRRGBBGBRRBGGGG";
	          //RRRRRRRRGGGGGBBBBBB
	char c[] = "BBRRRGBBGBRRBGGGRRR";
			  //GGGGGGGGGGGGGGGGGG
	char d[] = "GGGGGGGGGGGGGGGGGG";
			  //RRRRRRRRRRRRRRRRR
	char e[] = "RRRRRRRRRRRRRRRRR";
			  //BBBBBBBBBBBBBBBBB
	char f[] = "BBBBBBBBBBBBBBBBB";
			  //RRRRRRRRRGGGBBBBBBBBB
	char g[] = "BBRRRBBBRBBGRGGBRBRRR";
	rgb_sort(a,strlen(a));
	cout<<"1:"<<a<<endl;
	rgb_sort(b,strlen(b));
	cout<<"2:"<<b<<endl;
	rgb_sort(c,strlen(c));
	cout<<"3:"<<c<<endl;
	rgb_sort(d,strlen(d));
	cout<<"4:"<<d<<endl;
	rgb_sort(e,strlen(e));
	cout<<"5:"<<e<<endl;
	rgb_sort(f,strlen(f));
	cout<<"6:"<<f<<endl;
	rgb_sort(g,strlen(g));
	cout<<"7:"<<g<<endl;

	return 0;
}

void rgb_sort(char *array,unsigned int n)
{
	int cur_left,cur_right;
	int index_i,index_j;
	
	cur_left = index_i = 0;
	cur_right = index_j = n-1;

	while(cur_left <= cur_right)//条件<=
	{
		while(cur_left <= cur_right && array[cur_left] == 'R')
		{
			cur_left++;
			array[index_i] = 'R';
			index_i ++ ;
		}
		while(cur_left <= cur_right && array[cur_right] == 'B')
		{
			cur_right--;
			array[index_j] = 'B';
			index_j--;
		}
		//以上考虑了相等指向同一个元素情况！
		if(cur_left > cur_right )break;
/* 不能用额外的空间
		char temp_left = array[cur_left] ;
		char temp_right = array[cur_right];//防止下面覆盖修改！
	 
		if(temp_left == 'B')
		{
			array[index_j] = 'B';
			index_j--;
		}
		if(temp_right == 'R')
		{
			array[index_i] = 'R';
			index_i ++ ;
		}
*/	
		if(array[cur_left] == 'B'&&array[cur_right] == 'R')
		{
			array[index_j] = 'B';
			index_j--;
			array[index_i] = 'R';
			index_i ++ ;

		}
		else if(array[cur_left] == 'B')//BG
		{
			array[index_j] = 'B';
			index_j--;
		}
		else if(array[cur_right] == 'R')//RG
		{
			array[index_i] = 'R';
			index_i ++ ;
		}
			
		cur_left++;
		cur_right--;
	}
	
	while(index_i <= index_j)
	{
		array[index_i] = 'G';
		index_i++;
	}

}