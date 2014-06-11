#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

struct Fraction
{
	int Denominator;
	int numerator;
};

int gcd(int x,int y);
int simple_gcd(int x,int y);
Fraction deal_num(string str);

int main()
{
	cout<<"start"<<endl;
	string str;
	cin>>str;
	Fraction frac;
	frac = deal_num(str);
	cout<<frac.Denominator<<"/"<<frac.numerator<<endl;
	cout<<"end"<<endl;
	return 1;
}
//未考虑数值大溢出问题！！
Fraction deal_num(string str)
{
	int pos_dot;
	int pos_Bracket1;
	int pos_Bracket2;

	pos_dot = str.find('.');
	pos_Bracket1 = str.find('(',pos_dot+1);
	pos_Bracket2 = str.find(')',pos_Bracket1+1);
	
	int len_a,len_b;
	string str_a(str.substr(pos_dot+1,pos_Bracket1-pos_dot-1));
	string str_b(str.substr(pos_Bracket1+1,pos_Bracket2-pos_Bracket1-1));
	len_a = str_a.size();
	len_b = str_b.size();

	unsigned int a;
	unsigned int b;
	stringstream str_stream(str_a);
	str_stream>>a;
	str_stream.clear();
	str_stream.str("");
	str_stream<<str_b; //出问题
	str_stream>>b;
	str_stream.clear();
	
	int temp_a,temp_b;
	temp_a = (int)pow((float)10,len_a); //容易溢出
	temp_b = (int)pow((float)10,len_b);
	Fraction frac;
	frac.Denominator = a*(temp_b - 1)+b;
	frac.numerator = temp_a*(temp_b - 1);//容易溢出
	
	int gcd_val = gcd(frac.Denominator,frac.numerator);
	frac.Denominator /= gcd_val;
	frac.numerator /= gcd_val;

	return frac;
}


int gcd(int x,int y)
{
	if (x < y)
	{
	  return gcd(y,x);//用小的 --或者直接互换
	}
	if(y == 0)return x;

	if ((x&0x1) == 0)//偶数
	{
		if((y&0x1) == 0)//偶数
		{
			return 2*gcd(x>>1,y>>1);
		}
		else//奇数
		{
			return gcd(x>>1,y);
		}
	}
	else//奇数
	{
		if((y&0x1) == 0)
		{
			return gcd(x,y>>1);
		}
		else//奇数
		{
			return gcd(y,x-y);
		}
	}


}

int simple_gcd(int x,int y)
{
   return !y?x:simple_gcd(y,x%y);
}