#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define MAX 51
int N;
int b[MAX];
int main()
{
	cin >> N;
	memset(b,0,MAX);
	for(int i = 0; i < N; i++)
	{
		int t;
		scanf("%d",&t);
		b[t]++;	
	}
	for(int i = 0; i < MAX; i++)
	{
		if(b[i]!=0)
		{
			printf("%d:%d\n",i,b[i]);
		}
	}
}
