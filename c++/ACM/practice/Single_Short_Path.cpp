#include<iostream>
#include<cstdio>
#include<vector>
#define INF 99999
#define MAX 2501
using namespace std;
int N;
int M;
int s;
int t;
int adj[MAX][MAX];
struct node
{
	int u;
	int weight;
};
void dijkstra(int v)
{
	int D[MAX];
	bool visited[MAX];
	for(int i = 1; i <= N;i++)
	{
		D[i] = adj[v][i];
		visited[i] = false;
	}
	visited[v] = true;
	for(int i = 1; i <= N;i++)
	{
		int num = -1;
		int min = 99999;
		for(int j = 1; j <= N; j++ )
		{
			if(D[j] < min && !visited[j])
			{
				num = j;
				min = D[j];
			}
		}
		if(num == -1)
			break;
		visited[num] = true;
		for(int j = 1; j <= N;j++)
		{
			if( D[num] + adj[num][j] < D[j] && !visited[j])
			{
				D[j] = D[num] + adj[num][j];
			}
		}
	}
	printf("%d",D[t]);
}
int main()
{
	cin >> N >> M >> s >> t;
	for(int i = 1; i <= N;i++)
	{
		for(int j = 1; j <= N;j++)
		{
			adj[i][j] = adj[j][i] = (i==j)?0:INF;
		}
	}
	for(int i = 0; i < M ; i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adj[u][v] = adj[v][u] = w;
	}
	dijkstra(s);
}
