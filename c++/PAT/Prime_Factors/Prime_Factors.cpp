#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long int N,S,t;
	cin >> N;
	S = N;
	t = 1;
	cout << N <<"=";
	if( N == 1)
	{
		cout << 1 ;
		return 0;
	}
	for(long int i = 2; i*i <= N;i++)
	{
		int j = 0;
		while(N % i ==0)
		{
			j++;
			N/= i;
			t *= i;
		}
		if( j  == 1)
			printf("%ld",i);
		if( j > 1)
			printf("%ld^%d",i,j);
		if( t != S && j)
		{
			printf("*");
		}
	}	
	if(N > 1)
	{
		printf("%ld",N);
	}
}
