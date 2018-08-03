#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define MAX 10001
vector<int> adj[MAX];
int visited[MAX];
int N;
int max_length;
int length[MAX];
set<int> s;
int find(int a,int * pre)
{
	if(pre[a] == a)
	{
		return a;
	}
	else
	{
		pre[a] = find(pre[a],pre);
		return pre[a];
	}
}
void merge(int a,int b,int * pre)
{
	int set_A = find(a,pre);
	int set_B = find(b,pre);
	if(set_A == set_B) return;
	else 
		pre[set_A] = set_B;
}
void DFS(int v, int l)
{
	visited[v] = true;
	length[v] = l;
	max_length = max(l,max_length);
	for(int i = 0; i < adj[v].size();i++)
	{
		if( !visited[adj[v][i]])
			DFS(adj[v][i],l+1);
	}
}
int main()
{
	int * pre = (int * )malloc(sizeof(int) * MAX);
	int components = 0;
	cin >> N; for(int i = 1; i <= N;i++) pre[i] = i;
	for(int i = 1; i< N;i++)
	{
		int a,b; cin >> a >> b;
		merge(a,b,pre);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1; i<= N;i++)
	{
		if(pre[i] == i) components++;
	}
	if(components==1)
	{
		DFS(1,1);
		for(int i = 1; i <= N;i++)
		{
			visited[i]  = false;
			if(length[i] == max_length)  s.insert(i);
		}
		DFS(*s.begin(),1);
		for(int i = 1; i <= N;i++)
		{
			if(length[i] == max_length) s.insert(i);
		}
		for(auto &i:s) cout << i << endl;
	}
	else
	{
		cout << "Error: "<<components<<" components";
	}
	return 0;
}
