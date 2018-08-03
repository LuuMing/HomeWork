#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 10001
int adj[MAX][MAX];
int N;
int M;
bool visited[MAX];
int BFS(vector<int> v,int times)
{
	int count = v.size();
	if(times == 6 )
	{
		return v.size();
	}
	else
	{
		vector<int> c;
		for(auto & vv:v)
		{
			visited[vv] = true;
			for(int i = 1; i <= N;i++)
			{
				if(adj[vv][i] && !visited[i])
				{
					c.push_back(i);
				}
			}
		}
		count += BFS(c,++times);
	}
	return count;
}
int main()
{
	cin >> N >> M;
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < N;j++)
			adj[i][j] = (i==j)?1:0;
	}
	for(int i = 0; i < M;i++)
	{
		int a,b; 
		scanf("%d%d",&a,&b);
		adj[a][b] = adj[b][a] = 1;
	}
	for(int i = 1;i <= N;i++)
	{
		for(int i = 1; i <= N;i++) visited[i] = false;
		vector<int> t (1,i);
		printf("%d: %.2f%%\n",i,((double)BFS(t,0))/(double)N*100.0);
	}

}
