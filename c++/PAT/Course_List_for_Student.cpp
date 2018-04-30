#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 26*26*26*10+1
using namespace std;
int N;
int K;
vector<int> c[MAX];
int hash_id(char name[])
{
	int id = 0;
	for(int i = 0 ; i < 3; i++)
	{
		id = id * 26 + (name[i] -'A');
	}
	id = id * 10 + (name[3]-'0');
	return id;
}
int main()
{
	cin >> N >> K;
	char name[5];
	for(int i = 0; i < K;i++)
	{
		int cc,n; scanf("%d%d",&cc,&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%s",name);
			int id = hash_id(name);
			c[id].push_back(cc);
		}
	}
	for(int i = 0; i < N;i++ )
	{
		scanf("%s",name);
		int id = hash_id(name);
		printf("%s ",name);
		int n = c[id].size();
		printf("%d",n);
		sort(c[id].begin(),c[id].end());
		for(int i = 0; i < c[id].size();i++)
		{
			printf(" %d",c[id][i]);
		}
		printf("\n");
	}
}
