#include<iostream>
#include<cstdio>
#include<vector>
#define MAX 101
using namespace std;
int level[MAX];
int max_level;
struct person
{
	vector<int> v;
	bool root = true;
};
vector<int> roots;
int N;
int M;
person p[MAX];
void dfs(vector<int> root,int l)
{
	if(l > max_level)
		max_level = l;
	for(auto &i : root)
	{
		level[l]++;
		dfs(p[i].v,l+1);
	}
}
int main()
{
	int max_l = 1;
	cin >> N >> M;
	for(int i = 0; i < M ;i++)
	{
		int id,k;
		scanf("%d%d",&id,&k);
		for(int j = 0; j < k; j++)
		{
			int n; scanf("%d",&n);
			p[id].v.push_back(n);
			p[n].root = false;
		}
	}
	for(int i = 1; i <= N;i++)
	{
		if(p[i].root)
			roots.push_back(i);
	}
	dfs(roots,1);
	for(int i = 1; i <= max_level;i++)
	{
		if(level[i] > max_l)
			max_l = i;
	}	
	cout << level[max_l] << ' '<<max_l;
}
