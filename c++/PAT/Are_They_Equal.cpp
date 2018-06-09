#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> v_a,v_b;
int N;
int get_pow(float & a)
{
	int n = 0;
	if(a == 0)
	{
		return n;
	}
	if( a>=1)
	{	
		while(a >= 1)
		{
			a /= 10;
			n++;
		}
	}
	else
	{
		while( a <= 0.1)
		{
			a *= 10;
			n--;
		}
	}
	return n;
}
void get_valid(vector<int> & v,float f,int N)
{
	if(f == 0)
		return;
	while( N > 0)
	{
		if(f >= 1.00)
		{
			v.push_back(f);	
			N--;
			f -=float( int(f) );
		}
		else
		{
			f *= 10;
		}
	}
}
int main()
{
	float a,b;
	cin >> N >> a >>b;
	int pow_a = get_pow(a);
	int pow_b = get_pow(b);
	get_valid(v_a,a,N);
	get_valid(v_b,b,N);
	if(v_a == v_b)
	{
		if( pow_a != 0)
			printf("YES %.3f*10^%d",a,pow_a);
		else
			printf("YES %.3f",a);

	}
	else
	{
		printf("NO %.3f",a);
		if(pow_a !=0)
		printf("*10^%d",pow_a);
		printf(" %.3f",b);
		if(pow_b != 0)
		printf("*10^%d",pow_b);
	}
	
}
