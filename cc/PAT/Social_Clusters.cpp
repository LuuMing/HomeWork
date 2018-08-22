/******************
	@date: 18/8/22 10:15~10:35
	@autor: LuMing
******************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10001
int N;
int visit[MAX];
vector<int> hobby[MAX];
vector<int> p[MAX];
vector<int> result;
int total = 0;
bool cmp(const int & i1, const int & i2)
{
	return i1 > i2;
}
void dfs(int v)
{
	int i,j;
	total++;
	visit[v] = 1;
	for(i = 0; i < p[v].size(); i++)
	{
		for(j = 0; j < hobby[p[v][i]].size();j++)
		{
			if(!visit[hobby[p[v][i]][j]])
			{
				dfs(hobby[p[v][i]][j]);
			}
		}
	}
}
int main()
{
	int i,k,j,h;
	cin >> N;
	for(i = 0; i < N;i++)
	{
		scanf("%d: ",&k);
		for(j = 0; j< k; j++)
		{
			scanf("%d",&h);
			p[i].push_back(h);
			hobby[h].push_back(i);
		}
	}
	for(i = 0; i < N;i++)
	{
		total = 0;
		if(!visit[i])
		{
			dfs(i);
			result.push_back(total);
		}
		
	}
	sort(result.begin(),result.end(),cmp);
	cout <<result.size() << endl;
	for(i = 0; i < result.size();i++)
	{
		cout << result[i];
		if(i!= result.size() - 1)
				cout << ' ';
	}
}
