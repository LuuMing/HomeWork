#include<iostream>
using namespace std;
#define MAX 101
#define INF 999999
int N;
int M;
int adj[MAX][MAX];
bool visited[MAX];
int min_l = INF;
int min_v;
int connected = false;
void DFS(int v,int pre_v,int count,int m,int root)
{
	visited[v] = true;
	if(adj[v][pre_v] > m)
	{
		m = adj[v][pre_v];
	}
	if(count == N-1)
	{
		connected = true;
		if(m <= min_l)
		{
			min_l = m;
			min_v = root;
		}
	}
	for(int i = 1; i <= N;i++)
	{
		if(adj[v][i]!=INF && !visited[i])
		{
			DFS(i,v,count+1,m,root);
		}
	}
	visited[v] = false;
}
int main()
{
	cin >> N >> M;
	int v = -1;
	for(int i = 0; i <= N;i++)
		for(int j = 0;j <= N;j++)
			adj[i][j] = adj[j][i] = (i==j)?0:INF;
	for(int i = 0; i < M; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		adj[a][b] = adj[b][a] = c;
		if(i==0)
		{
			v = a;
		}
	}
	for(int i = 1; i <=  N;i++)
	{	
		for(int i = 1; i<= N;i++)visited[i] = false;
		DFS(i,i,0,-1,i);
	}
	if(connected)
	cout << min_v << min_l ;
	else
	cout << 0;
}
