#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
long long int to_int(char c)
{
	if(c >='0'&&c<='9')
	{
		return c-'0';
	}
	else
	{
		return c-87;
	}
}
long long int to_decimal(string n,int radix)
{
	long long int result = 0;
	for(long long int i = n.size()-1,j = 0; i >= 0;i--,j++)
	{
		result +=to_int(n[i])*pow(radix,j);
	}
	return result;
}
long long int find_max(string n)
{
	long long int l = -1;
	for(int i = 0; i < n.size();i++)	
	{
		if(to_int(n[i])>l)	
		{
			l = to_int(n[i]);
		}
	}
	return l;
}

int main()
{
	string N1,N2;
	long long int tag;
	long long int radix;
	cin >> N1 >> N2 >> tag >> radix;
	if(tag == 2)
	{
		swap(N1,N2);
	}
	long long int decimal = to_decimal(N1,radix);
	long long int decimal2;
	long long int left = find_max(N2)+1, right = max(left,decimal+1),pivot = (left+right)/2;  //copy
	while(left <= right)                                                                        //binary search
	{
	        decimal2 = to_decimal(N2,pivot);
		if(decimal2 > decimal|| decimal2 < 0)                                               //!!!overflow
		{
			right = pivot - 1;
			pivot = (left + right)/2;
		}
		else if(decimal2 >=0 &&decimal2 < decimal)
		{
			left = pivot + 1;
			pivot = (left + right)/2;
		}
		else 
		{
			break;
		}
	}
	if(decimal2 == decimal)
	{
		cout << pivot;
	}
	else
	{
		cout << "Impossible";
	}
	
}
