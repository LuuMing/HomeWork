#include<iostream>
#include<queue>
using namespace std;
#define MAX 11
#define INF 99999
int adj[MAX][MAX];
int N;
int E;
bool visited[MAX];
void DFS(int v)
{
	visited[v] = true;
	cout << v << ' ';
	for(int i = 0; i < N;i++)
	{
		if(adj[v][i] != -INF && visited[i] ==false)
		{
			DFS(i);
		}
	}
}
void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while(!q.empty())
	{
		for(int i = 0; i < N;i++)
		{
			if(adj[q.front()][i]!=-INF && visited[i]==false)
			{
				q.push(i);
				visited[i] = true;
			}
		}
		cout << q.front() <<' ';
		q.pop();
	}
}
void List()
{
	for(int i = 0; i< N;i++)
	{
		visited[i] = false;
	}
	for(int i = 0; i < N;i++)
	{
		if(!visited[i])
		{
			cout << "{ ";
			DFS(i);
			cout << "}" << endl;
		}
	}
	for(int i = 0; i < N;i++)
	{
		visited[i] = false;
	}
	for(int i = 0; i < N;i++)
	{
		if(!visited[i])
		{
			cout << "{ " ;
			BFS(i);
			cout << "}" << endl;
		}
	}
}
int main()
{
	cin >> N >> E;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			adj[i][j] = (i==j)?0:-INF;
		}
	}
	for(int i = 0; i < E; i++)
	{
		int a,b;	cin >> a>>b;
		adj[a][b] = adj[b][a] = 1;
	}
	List();
}
