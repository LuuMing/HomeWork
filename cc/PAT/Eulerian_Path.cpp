#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int N;
int M;
int degree[510];
vector<int> e[510];
int visit[510];
bool connect = true;
int n = 0;
void dfs(int v)
{
	n++;
	visit[v] = 1;
	for(int i = 0; i < e[v].size();i++)
	{
		if(!visit[e[v][i]])
			dfs(e[v][i]);
	}
}
int main()
{
	cin >> N >> M;
	for(int i = 0; i < M;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		degree[u]++;
		degree[v]++;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int odd = 0;
	for(int i = 1; i <= N;i++)
	{
		printf("%d",degree[i]);
		if(degree[i] % 2 != 0)
			odd++;
		if( i != N)
			printf(" ");
	}
	dfs(1);
	printf("\n");
	
	if(n != N)
	{
		printf("Non-Eulerian");
		return 0;
	}
	if(odd == 2)
		printf("Semi-Eulerian");
	else if ( odd == 0)
		printf("Eulerian");
	else
               printf("Non-Eulerian");

}
