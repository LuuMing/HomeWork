#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#define MAX 500
using namespace std;
struct edge
{
	int v;
	int w;
	int D;
};
vector<edge> forward_e[MAX];
vector<edge> backward_e[MAX];
int N,M;
int indegree[MAX];
int outdegree[MAX];
int Earliest[MAX];
int Lastest[MAX];
void TopSort()
{
	queue<int> q;
	for(int i = 1; i <= N; i++ )
	{
		if(indegree[i] == 0)
		{
			q.push(i);
		}
	}
	int cnt = 0;
	while(!q.empty())
	{
		int v = q.front();
		q.pop(); cnt++;
		for(int i = 0; i < forward_e[v].size(); i++)
		{
			Earliest[forward_e[v][i].v] = 
max(Earliest[forward_e[v][i].v],Earliest[v]+forward_e[v][i].w); 
			indegree[forward_e[v][i].v]--;
			if(indegree[forward_e[v][i].v] == 0)
			{
				q.push(forward_e[v][i].v);
			}
		}
	}
	if(cnt == N)
	{
		int max = -1;
		int num;
		for(int i = 1; i<= N;i++)
			if(indegree[i]==0&&Earliest[i] > max)
			{	max = Earliest[i]; num = i; }
		Lastest[num] = max;
		cout << max << endl;
		for(int i = 1; i <= N;i++)
		{
			if(outdegree[i] == 0)
			{
				q.push(i);
			}
		}
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			for(int i = 0; i < backward_e[v].size();i++)
			{
				Lastest[backward_e[v][i].v] = 
min(Lastest[backward_e[v][i].v],Lastest[v]-backward_e[v][i].w);
				outdegree[backward_e[v][i].v]--;
				if(outdegree[backward_e[v][i].v] ==0)
				{
					q.push(backward_e[v][i].v);
				}
			}
		}
		for(int i = 1; i <= N;i++)
		{
			int temp = -1;
			for(int j = forward_e[i].size()-1; j >= 0 ;j--)
			{
				forward_e[i][j].D = Lastest[forward_e[i][j].v]-
Earliest[i] - forward_e[i][j].w;	
				if(forward_e[i][j].D == 0)
				{
					cout << i << "->" <<forward_e[i][j].v<<endl;
				}
			}
						
		}
		
	}
	else
	{
		cout << 0; return;
	}
}
int main()
{

	cin >> N >> M;
	memset(Lastest,999999,MAX);	
	for(int i = 0; i < M;i++)
	{
		int u,v,w; cin >> u >> v >> w;
		edge t; t.v = v; t.w = w;
		forward_e[u].push_back(t);
		edge t2; t2.v = u; t2.w = w;
		backward_e[v].push_back(t2);
		indegree[v] ++;
		outdegree[u]++;
	}
	TopSort();
}
