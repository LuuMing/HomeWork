/*
	n * m 个格子，从左上走到右下，最大能获得的值，输出其路径
*/
/*
测试输入：
4
4
1 10 3 8
12 2 9 6
5 7 4 11
3 7 15 5
测试输出：1 12 5 7 7 15 5
*/
#include<iostream>
#include<vector>
using namespace std;
int num[100][100];
int  dp[100][100];
int Select[100][100];
int N, M;
vector<int>  ans;
void dfs(int i ,int j )
{
	if(i==0)
	{
		ans.push_back(num[0][j]);
		return;
	}
	ans.push_back(num[i][j]);
	if(Select[i][j-1] && Select[i-1][j])
	{
		if(dp[i][j-1] > dp[i-1][j])
			dfs(i,j-1);
		else
			dfs(i-1,j);
	}
	else if(Select[i][j-1])
		dfs(i,j-1);
	else if( Select[i-1][j])
		dfs(i-1,j);
}
int main()
{
	cin >> N >> M;
	for(int i = 0; i < M;i ++)
		for(int j = 0; j < N;j++)
		cin >> num[i][j];
	for(int i = 0; i < M; i++)
	{
		dp[0][i] = num[0][i];
		Select[0][i] = 1;
	}
	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(j == 0)
			{
				dp[i][j] = num[i][j]+dp[i-1][j];
				Select[i][j] = 1;
			}
			else
			{
				dp[i][j] = num[i][j]+max(dp[i-1][j],dp[i][j-1]);
				if(dp[i-1][j] > dp[i][j-1])
					Select[i-1][j] = 1;
				else
					Select[i][j-1] = 1;
			}
		}
	}
	dfs(N-1,M-1);
	for(int i = ans.size() -1; i >= 0; i--)
		cout << ans[i] <<' ';
}
