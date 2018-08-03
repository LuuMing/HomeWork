#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define MAX 10005
int adj[MAX][MAX];
bool visited[MAX];
int N;
int M;
int BFS(int v)
{
	for(int i = 1; i <= N;i++) visited[i] = false;
	queue<int> q;
	q.push(v);
	int level = 0;
	int back = q.back();
	int count = 0;
	while(!q.empty() && level != 7)
	{
		visited[q.front()] = true;
		count ++;
		for(int i = 1; i <= N; i++)
		{
			if(adj[q.front()][i] && !visited[i])
			{
				q.push(i);
			}
		}
		if(q.front() == back)
		{
			level ++;
			back = q.back();
		}
		q.pop();
	}
	return count;
}
int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a,b; cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;	
	}
	for(int i = 1; i <= N; i++)
	{
		printf("%d: %.2f%%\n",i,(double)BFS(i)/N*100);
	}
}
