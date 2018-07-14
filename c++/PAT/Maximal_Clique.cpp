#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 201
int edge[MAX][MAX];
int Nv,Ne,K;
int main()
{
	cin >> Nv >> Ne;
	for(int i = 0; i <  Ne;i++)
	{
		int e1,e2; scanf("%d%d",&e1,&e2);
		edge[e1][e2] = edge[e2][e1] = 1;
	}
	cin >> K;
	for(int i = 0; i < K;i++)
	{
		int M; scanf("%d",&M);
		vector<int> v(M);
		vector<int> s(Nv+1,0);
		bool iscliq = true;
		for(int j = 0; j < M; j++)
		{
			scanf("%d",&v[j]);
			s[v[j]] = 1;
		}
		for(int U = 0; U < M; U++)
		{
			if(!iscliq)
				break;
			for(int V = U + 1; V < M; V++)
			{
				if(edge[v[U]][v[V]] == 0)
				{
					iscliq = false;
				}
			}
		}
		if( !iscliq )
		{
			printf("Not a Clique\n");
			continue;
		}
		bool Max = false;
		for(int vv = 1; vv <= Nv; vv++)
		{
			bool flag = true;
			if(s[vv])
			continue;
			for(auto u: v)
			{
				if(edge[vv][u] == 0)
				{
					flag = false;
					break;
				}
			}
			if(flag)
				Max = true;
		}
		if(Max)
		
			printf("Not Maximal\n");
		else
			printf("Yes\n");
	}
}

