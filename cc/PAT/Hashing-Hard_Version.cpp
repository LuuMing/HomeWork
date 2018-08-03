#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
#define MAX 1001
unordered_map<int,int> m;
unordered_map<int,vector<int> > g;
struct edge
{
	int u,v;
};
int num[MAX];
int N;
void topSort()
{
	priority_queue<int,vector<int>,greater<int> >q;
	for(auto i:m)
	{
		if(i.second == 0)
			q.push(i.first);
	}

	while(!q.empty())
	{
		cout << q.top();
		int t = q.top();
		q.pop();
	
		vector<int> & v = g[t];
		for(auto i = v.begin(); i != v.end(); i++)
		{
			m[*i]--;
			if(m[*i] == 0)
			{
				q.push(*i);
			}
		}
		if(!q.empty())
			cout << ' ';
	}
}
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		scanf("%d",&num[i]);
		if(num[i] != -1)
			m[num[i]] = 0;
	}
	for(int i = 0; i < N;i++)
	{
		if(num[i] % N != i&&num[i]!=-1)
		{
			for(int j = (num[i]%N);num[j%N] != num[i];j++ )
			{
				g[num[j%N]].push_back(num[i]);
				m[num[i]]++;
			}
		}
			
	}
	topSort();
}

