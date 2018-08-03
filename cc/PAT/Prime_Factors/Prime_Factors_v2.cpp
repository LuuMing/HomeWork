#include<iostream>
#include<cstdio>
#include<limits.h>
#include<math.h>
#define MAX 100000
using namespace std;
int visit[MAX];
int prime[100000];
void sieve(int n)
{
	int m = (int) sqrt(n+0.5)	;
	for(int i = 2; i <= m;i++) if(!visit[i])
		for(int j = i*i; j <=n;j+=i)
			visit[j] = 1;
}
int get_prime(int n)
{
	sieve(n);
	int c = 0;
	for(int i = 2; i <= n;i++) if (!visit[i])
		prime[c++] = i;
	return c;
}
int main()
{
	get_prime(MAX);
	long int N; cin >> N;
	printf("%ld=",N);
	if(N == 1)
	{
		printf("1");
		return 0;
	}
	for(int i = 0; N > 1;i++)
	{
		int times = 0;
		while(N % prime[i] ==0)
		{
			times ++;
			N /= prime[i];
		}
		if(times == 1)
		printf("%d",prime[i]);
		if (times >1)
		printf("%d^%d",prime[i],times);
		if( N > 1 & times != 0)
		printf("*");
	}
}
