#include<iostream>
using namespace std;
#define MAX 10001
int adj[MAX][MAX];
int N;
bool visited[MAX];
int length[MAX];
void DFS(int v,int root,int level,bool count = true)
{
	visited[v] = true;
	if(level > length[root] && count)
	{
		length[root] = level;
	}
	for(int i = 1; i <= N;i++)
	{
		if(adj[v][i] && !visited[i])
		{
			 DFS(i,root,level+1,true);
		}
	}
}
int list()
{
	int count = 0;
	for(int i = 1; i<= N;i++) visited[i] = false;
	for(int i = 1; i<= N;i++)
	{
		if(!visited[i])
		{
			DFS(i,visited[i],0,false);
			count ++;
		}
	}
	return count;
}
int main()
{
	cin >> N;	
	for(int i = 1; i < N; i++)
	{
		int a,b; cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
	}
	for(int i = 1; i <= N;i++)
	{
		DFS(i,i,1);
		for(int i = 1; i <= N;i++) visited[i] = false;
	}
	int components = list();
	if(components == 1)
	{
		int max = -1;
		for(int i = 1; i <= N;i++) if( length[i] > max ) max = length[i];
		for(int i =1; i <= N;i++)  
		{
			if(length[i] == max) 
				cout << i << endl;
		}
	}
	else
	{
		cout << "Error: " << components <<" components"; 
	}
}
