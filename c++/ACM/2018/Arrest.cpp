#include<iostream>
#include<cstdio>
#include<string.h>
#include<vector>
using namespace std;
#define MAX 100001
vector<int> t;
int q[MAX][2];
int n;
int m;
int number = MAX;
bool flag = false;
void set_left(int u,int v)
{
	t[u] = 1; t[v] = 0;
}
void set_right(int u,int v)
{
	t[u] = 0; t[v] = 1;
}
void dfs(int i)
{
	vector<int> pre = t;
	if(i > n)
	{
		return ;
	}
	if(i == n)
	{
		flag = true;
		return;
	}
	if( ( t[q[i][0]]==-1 && t[q[i][1]]==-1)||
		(t[q[i][0]] == 1 && t[q[i][1]]==-1) ||
		(t[q[i][0]] == -1 && t[q[i][1]] == 0)	)
	{
	
		set_left(q[i][0],q[i][1]);
		dfs(i+1);
		
	}
	t = pre;
	if( ( t[q[i][0]]==-1 && t[q[i][1]]==-1)||
		(t[q[i][0]] == 0 && t[q[i][1]]==-1) ||
		(t[q[i][0]] == -1 && t[q[i][1]] == 1)	)
	{
	
		set_right(q[i][0],q[i][1]);
		dfs(i+1);

	}
	t = pre;
	if(i == 3 &&i < number)
	{
		number = i;
	}
}
int main()
{
	cin >> n >> m;
	t.resize(n+1,-1);
	for(int i = 1; i <= m; i++)	
	{
		scanf("%d%d", &q[i][0],&q[i][1]);
	}
	dfs(1);
	if(flag)
	{
		cout << "-1 ";
		for(int i = n;i>=0;i--)
		{
			if(t[i] == -1)
			{
				cout << i; break;
			}
		}

	}
	else
	{
		cout << "1 " << number; 
	}
}
