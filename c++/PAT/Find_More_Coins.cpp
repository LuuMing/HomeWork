#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 10001
using namespace std;
vector<int> ans;
int N, M;
int price[MAX];
int dp[MAX][101];//dp[i][j] stand for use coins form 0-i, the value sum up to j
int pre[MAX][101];//pre[i][j] stand for whether current coin i was used in dp[i][j]
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N;i++)
		scanf("%d",&price[i]);
	sort(price+1,price + N+1, cmp);
	for( int i = 0; i <= N; i++)
	{
		dp[i][0] = 1;// use coins[0-i] could reach value 0
	}
/*
	if use coins i, then we could reach dp[i][0~price[i]]
*/
	for(int i = 1; i <= N; i++)
	{
		for(int j = price[i]; j <= M; j++) // use coins[i], could reach [0 ~ M-price[i]]
		{
			if(dp[i-1][j - price[i]] == 1)
			{
				dp[i][j] = 1;
				pre[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	if(!dp[N][M])
		printf("No Solution\n"); // if use coins from 0 - N-1, couldn't reach M , NO solution.
	while(N > 0)
	{
		if(pre[N][M] == 1)
		{
			ans.push_back(price[N]);
			M = M - price[N];
		}
		N --;
	}
	for(int i = 0; i < ans.size();i++)
	{
		printf("%d",ans[i]);
		if( i != ans.size() - 1)
			printf(" ");
	}
}
