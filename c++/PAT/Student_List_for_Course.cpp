#include<iostream>
#include<vector>
#include<cstdio>
#include<unordered_map>
#include<set>
using namespace std;
int N;
int K;
unordered_map<int,set<string> >m;
int main()
{
	cin >> N >> K;
	char name[6];
	int C;
	for(int i = 0; i < N;i ++)
	{
		int c;
		scanf("%s%d",name,&C);
		for(int j = 0; j < C;j++)
		{
			scanf("%d",&c);
			m[c].insert(name);
		}	
	}
	for(int i = 1; i <= K; i++)
	{
		printf("%d %d\n",i,m[i].size());
		for(auto &j:m[i])
		{
			printf("%s\n",j.c_str());
		}
	}
}
