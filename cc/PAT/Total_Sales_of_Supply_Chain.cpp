#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#define MAX 100001
using namespace std;
vector<int> p[MAX];
int N;
double P,r;
double total;
void DFS(int v,int times)
{
	if(p[v][0] < 0)
	{
		total += -p[v][0]* ( P* pow((1.0+r/100.0),times));
	}
	else
	{
		for(int i = 0; i < p[v].size();i++)
		{
			DFS(p[v][i],times+1);
		}		
	}
}
int main()
{
	cin >> N >> P >> r;
	for(int i = 0; i < N; i++)
	{
		int k;
		scanf("%d",&k);
		if(k!=0)
		for(int j = 0;j < k;j++)
		{
			int id; scanf("%d",&id);
			p[i].push_back(id);
		}
		else
		{
			int total;
			scanf("%d",&total);
			p[i].push_back(-total);
		}
	}
	DFS(0,0);
	printf("%.1lf",total);
}
	
