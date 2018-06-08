#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int prime(int N)
{
	if( N == 2)  return true;
	if( N == 1) return false;
	for(int i = 2; i <= sqrt(N);i++)
	{
		if(N % i ==0)
			return 0;
	}
	return 1;
}
int p[100000];
int radix[100000];
int f = 1;
int get_prime(int i)
{
	if(p[i] != 0)
	{
		return p[i];
	}
	else 
	{
		for(int s = p[f-1]+1; f != i+1; s++)
		{
			if(prime(s))
			{
				p[f] = s;
				f++;
			}
		}
	}
	return p[i];
}
int main()
{
	long int N;
	cin >> N;
	if(N == 1)
	{
		printf("1=1");
		return 0;
	}
	long int o = N;
	long int t = 1;
	while(true)
	{	
		bool flag = true;
		for(int i = 1; ;i++)
		{
			if( N % get_prime(i)==0)
			{
				t *= get_prime(i);
				radix[i] ++;
				N /= get_prime(i);
				flag = false;
				break;
			}
		}
		if(t == o)
			break;
	}
	t = 1;
	printf("%ld=",o);
	for(int i = 1; t != o;i++)
	{
		if(radix[i]==0)
			continue;
		if(radix[i] == 1)
			printf("%d",get_prime(i));
		else
			printf("%d^%d",get_prime(i),radix[i]);
		t *= pow(get_prime(i),radix[i]);
		if(t != o)
		{
			printf("*");
		}
	}
}
