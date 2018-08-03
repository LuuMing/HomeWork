#include<iostream>
#include<cstdio>
#include<math.h>
#define MAX 100001
using namespace std;
int Tsize,N,M;
int H[MAX];
bool prime(int n)
{
	if( n == 1)	 return false;
	if (n == 2) 	return true;
	for(int i = 2 ; i <= sqrt(n);i++)
	{
		if( n % i == 0 )
			return false;
	}
	return true;
}
void set()
{
	if(prime(Tsize))
		return;
	for(; !prime(Tsize); Tsize++);
}
int getPosition(int num)
{
	return num % Tsize;
}
int main()
{
	cin >> Tsize >> N >> M;
	set();
	for(int i = 0; i < Tsize;i++)
		H[i] = -1;
	for(int i = 0; i < N ;i++)
	{
		int di = 0;
		int elem; scanf("%d",&elem);
		bool flag = false;
		while( di  < Tsize)
		{
			int p = getPosition(elem + di* di);
			if(H[p]  == -1)
			{
				flag = true;
				H[p] = elem;
				break;
			}
			di++;
		}
		if( !flag)
			printf("%d cannot be inserted.\n",elem);
	}
	int cnt = 0;
	for(int i = 0; i < M; i++)
	{
		int elem; scanf("%d",&elem);
		int di = 0;
		bool flag = true;
		while(di < Tsize)
		{
			cnt ++;
			int p = getPosition(elem + di*di);
			if(H[p] == elem || H[p] == -1)
			{
				flag = false;
				break;
			}
			di++;
		}
		if( flag) 
			cnt += 1;
	}
	printf("%.1f",(double)cnt / M);
}
