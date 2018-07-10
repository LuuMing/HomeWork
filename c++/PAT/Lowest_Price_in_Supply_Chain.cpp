#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
#define MAX 100001
using namespace std;
int N;
double origin;
double r;
vector<int> v[MAX];
unordered_map<int ,int > m;
double Min = 99999999;
int num;
void dfs(int root, double current_value,int step)
{
	if( v[root].empty())
	{
		if(current_value  < Min)
		{
			Min = current_value;
			num = step;
		}
		m[step]++;
	}
	else
	{
		for(int i = 0; i < v[root].size(); i++)
		{
			dfs(v[root][i],current_value * (1.00 + r / 100.0),step+1);
		}
	}
}
int main()
{
	cin >> N >> origin >> r;
	for(int i = 0; i < N ;i++)
	{
		int k; scanf("%d",&k);
		for(int j = 0; j < k ;j++)
		{
			int t; scanf("%d",&t);
			v[i].push_back(t);
		}
	}
	dfs(0,origin,0);
	printf("%.4lf %d",Min,m[num]);
}
