#include<iostream>
#include<cstdio>
using namespace std;
long int min_multi(long int a,long int b)
{
	if(b > a )
		swap(a,b);
	long int org_b = b;
	long int org_a = a;
	while(b != 0)
	{
		int t_a = a;
		a = b;
		b = t_a % b;	
	}
	return org_b *org_a/ a;
	
}
long int gdc(long int a,long int b)
{
	while(b != 0)
	{
		int t_a = a;
		a = b;
		b = t_a % b;	
	}
	return a;
}
int num[101];
int den[101];
int main()
{
	int N;
	cin >> N;
	long int denominator = 1;
	long int numerator = 0;
	for(int i = 0; i < N;i++)
	{
		scanf("%d/%d",num+i,den+i);
		denominator = min_multi(denominator,den[i]);			
	}
	for(int i = 0; i < N;i++)
	{
		numerator += (denominator / den[i])*num[i];
	}
	if(numerator ==0 )
	{
		cout << 0;  return 0;
	}
	bool flag = true;
	if(numerator / denominator  != 0)
	{
		cout << numerator / denominator;
		numerator -= (numerator / denominator)* denominator;
		flag = false;	
	}
	if( numerator  != 0 )
	{	
		long int g = gdc(numerator , denominator);
		if(!flag)
		cout << ' ';
		if(g< 0)
		cout<<-numerator / g <<'/'<<denominator/-g ;
		else
		cout<<numerator / g <<'/'<<denominator/g ;
	}
		
}