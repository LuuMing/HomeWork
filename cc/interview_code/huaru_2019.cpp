/*
	@author: LuMing
	@Date: 18/9/19
题目描述：工人有 N 个苹果需要搬运，每次搬走 1 个或者 2 个。共有多少种方案？
*/

#include<stdio.h>
int total = 0;
void dfs(int N)
{
	if( N < 0 ) return;
	if( N == 0 )
	{ 
		total ++;
		return;
	}
		dfs( N - 2);
		dfs ( N - 1);
}
int main()
{
	int N; scanf("%d",&N);
	dfs(N);
	printf("%d",total);
}
