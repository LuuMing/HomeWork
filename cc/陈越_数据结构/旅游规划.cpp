#include<iostream>
#include<vector>
using namespace std;
#define MAX 501
#define INF 999999
int adj[MAX][MAX];
int cost[MAX][MAX];
int path[MAX];
int N;
int M;
int S;
int D;
int dist[MAX];
int C[MAX];
void dijkstra(int v)
{
	bool visited[MAX];
	for(int i = 0; i < N; i++)
	{
		C[i] = cost[v][i];
		dist[i] = adj[v][i];
		visited[i] = false;
	}
	visited[v] = true;
	while(1)
	{
		int num = -1;
		int min_l = INF;
		for(int i = 0; i < N; i++)
		{
			if(!visited[i] && dist[i] < min_l)
			{
				num = i;
				min_l = dist[i];
			}
		}
		if(num == -1)
		{
			break;
		}
		visited[num] = true;
		for(int i = 0; i < N;i++)
		{
			if(!visited[i] && adj[num][i]!= INF)
			{
				if(dist[num] + adj[num][i] < dist[i] )
				{
					C[i] = C[num] + cost[num][i];
					dist[i] = dist[num] + adj[num][i];
					path[i] = num;
				}
				else if(dist[num] + adj[num][i] == dist[i])
				{
					if(C[num] + cost[num][i] < C[i])
					{
						C[i] = C[num] + cost[num][i];
						path[i] = num;
					}
				}
			}
		}
	}
}
int main()
{
	cin >> N >> M >> S >> D;
	for(int i = 0; i < N;i++)
	{
		path[i] = -1;
		for(int j= 0; j < N;j++)
			adj[i][i] = adj[j][i] = (i==j)?0:INF;
	}
	for(int i = 0; i < M; i++)
	{
		int a,b,c,d; cin >> a >>b >> c >> d;
		adj[a][b] = adj[b][a] = c;
		cost[a][b] = cost[b][a] = d;
	}
	dijkstra(S);

	cout << dist[D] <<' '<< C[D];
}
