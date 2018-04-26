#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define MAX 101
struct edge
{
	int v;
	int w;
};
vector<edge> e[MAX];
int indegree[MAX];
int finish[MAX];
bool End[MAX];
int N;
int M;
int TopSort()
{
	queue<int> q;
	for(int i = 0; i < N;i++)
	{
		if(indegree[i] == 0)
			q.push(i);
	}
	int count = 0;
	while( !q.empty() )
	{
		int u = q.front();
		q.pop();
		count++;
		for(int i = 0; i < e[u].size(); i++ )
		{
			finish[e[u][i].v] = max(finish[e[u][i].v],finish[u]+e[u][i].w);
			indegree[e[u][i].v] --;
			if(indegree[e[u][i].v] == 0)
				q.push(e[u][i].v);
		}
	}
	return count;

}
int main()
{
	cin >> N >> M;
	memset(End,true,MAX);
	for(int i = 0; i < M;i++)
	{
		int u,v,w; cin >> u >> v >> w;
		edge t; t.v = v; t.w = w;
		e[u].push_back(t);
		indegree[v] ++;
		End[u] = false;
	}
	int count = TopSort();
	if(count != N)
	{
		cout << "Impossible";
	}
	else
	{
		int max = -1;
		for(int i = 0 ; i < N; i++)
		{
			if(End[i])
			{
				if(finish[i] > max)
				{
					max = finish[i];
				}
			}
		}
		cout << max;
	}
}
