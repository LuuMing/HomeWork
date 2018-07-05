#include<iostream>
#include<unordered_set>
#include<vector>
#include<cstdio>
#define MAX 1001
using namespace std;
vector<int> edge[MAX];
vector<int> indegree;
vector<int> o;
int main()
{
	int N, M;
	cin >> N >> M;
	indegree.resize(N+1);
	for(int i = 0; i < M; i++)
	{
		int w,v; scanf("%d%d",&w,&v);
		edge[w].push_back(v);
		indegree[v]++;
	}
	int  K; cin >> K;
	for(int i = 0; i < K; i++)
	{
		bool flag = true;
		vector<int> in = indegree;
		for(int j = 0; j < N; j++)
		{
			int t;
			scanf("%d",&t);
			if(in[t] == 0)
			{
				for(auto k:edge[t])
				{
					in[k]--;
				}
			}
			else
			{
				flag = false;
			}
		}
		if(!flag)
			o.push_back(i);
	}
	for(int i = 0; i < o.size();i++)
	{
		cout << o[i];
		if( i != o.size() - 1)
			cout << ' ';
	}
}
