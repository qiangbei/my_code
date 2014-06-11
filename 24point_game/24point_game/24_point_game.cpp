#include "vld.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
using namespace  std;
const double ess = 1E-6;
const int point_num = 24;
bool point_game(vector<double> vec_num,int n,vector<string> my_str,vector<string> &result);
int main()
{
	int array[]={11,8,3,5};//11,8,3,5 || 8,8,2 || 12,2,2,12||7,8,9,5
	vector<double> vec_num(array,array+4);
	vector<string> result;
	vector<string> my_str;

	stringstream stream_str;
	for(int k = 0;k < vec_num.size();k++)
	{
		string str_a ;
		stream_str.clear();
		stream_str<<vec_num[k];
		stream_str>>str_a;
		my_str.push_back(str_a);
	}

	if(point_game(vec_num,vec_num.size(),my_str,result))cout<<"find"<<endl;//Î´´òÓ¡¹ý£¡£¡
	
	for (int i = 0;i < result.size();i++)
	{
		cout<<result[i]<<endl;
	}
	

	return 1;
}

bool point_game(vector<double> vec_num,int n,vector<string> my_str,vector<string> &result)
{
	
	if(n == 1)
	{

		if (abs(vec_num[0]- point_num)< ess )
		{
			result.push_back(my_str[0]);
			return true ;
		}
		else
		{
			return false;
		}
	}
	else
	{	
		bool flag = false;
		for (int i = 0 ;i < n;i++)
		{
			for (int j = i+1 ;j < n;j++)
			{
				string str_temp ;
				double a , b ;
				a = vec_num[i];
				b = vec_num[j];
				
				//+
				string str_a(my_str[i]);
				string str_b(my_str[j]);

				str_temp = "(" +str_a+"+"+str_b+")";
				my_str[i] = str_temp;
				my_str[j] = my_str[n-1] ;
				vec_num[j] = vec_num[n-1];
				vec_num[i]= a+b;

				flag |= point_game(vec_num,n-1,my_str,result);
				 
				//»Ö¸´
				/*
				my_str[i] = str_a;
				my_str[j] = str_b;
				vec_num[i] =a;
				vec_num[j] =b;
				*/
				

				//a-b
			    str_temp = "(" +str_a+"-"+str_b+")";
				my_str[i] = str_temp;
				my_str[j] = my_str[n-1] ;
				vec_num[j] = vec_num[n-1];
				vec_num[i]= a-b;

				flag |=point_game(vec_num,n-1,my_str,result);
				 
				//»Ö¸´
				 /*
				my_str[i] = str_a;
				my_str[j] = str_b;
				vec_num[i] =a;
				vec_num[j] =b;
				*/

				//b-a
				str_temp = "(" +str_b+"-"+str_a+")";
				my_str[i] = str_temp;
				my_str[j] = my_str[n-1] ;
				vec_num[j] = vec_num[n-1];
				vec_num[i]= b-a;

				flag |= point_game(vec_num,n-1,my_str,result);
				 
				//»Ö¸´
				 /*
				my_str[i] = str_a;
				my_str[j] = str_b;
				vec_num[i] =a;
				vec_num[j] =b;
				*/

				//a/b
				if(b != 0)
				{
					str_temp = "(" +str_a+"/"+str_b+")";
					my_str[i] = str_temp;
					my_str[j] = my_str[n-1] ;
					vec_num[j] = vec_num[n-1];
					vec_num[i]= a/b;

					flag |= point_game(vec_num,n-1,my_str,result);
						 
					//»Ö¸´
					 /*
					my_str[i] = str_a;
					my_str[j] = str_b;
					vec_num[i] =a;
					vec_num[j] =b;		
					*/
				}
				
				if(a != 0)
				{
					str_temp = "(" +str_b+"/"+str_a+")";
					my_str[i] = str_temp;
					my_str[j] = my_str[n-1] ;
					vec_num[j] = vec_num[n-1];
					vec_num[i]= b/a;

					flag |= point_game(vec_num,n-1,my_str,result);
					//»Ö¸´
					/*
					my_str[i] = str_a;
					my_str[j] = str_b;
					vec_num[i] =a;
					vec_num[j] =b;
					*/	 
				}

				//*
				str_temp = "(" +str_a+"*"+str_b+")";
				my_str[i] = str_temp;
				my_str[j] = my_str[n-1] ;
				vec_num[j] = vec_num[n-1];
				vec_num[i]= a*b;

				flag |= point_game(vec_num,n-1,my_str,result);
				//»Ö¸´	
				
				my_str[i] = str_a;
				my_str[j] = str_b;
				vec_num[i] =a;
				vec_num[j] =b;
				
			}
		}
		return flag;
	}
return false;

}