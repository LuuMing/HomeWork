#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;
vector<int> school[101];
int cap[101];
int N,M,K;
struct apply
{
	int num;
	int GE,GI;
	int choice[6];
};
apply a[40001];
bool cmp(const apply & a1,const apply & a2)
{
	if( a1.GE+ a1.GI != a2.GE + a2.GI)
	 	return a1.GE + a1.GI > a2.GE+a2.GI;
	else
		return a1.GE > a2.GE;
}
int main()
{
	cin >> N >> M >> K;
	for(int i = 0; i < M;i++)
		scanf("%d",cap+i);
	for(int i = 0; i < N; i++)
	{
		scanf("%d%d",&a[i].GE,&a[i].GI);
		for(int j = 0; j < K; j++)
		{
			scanf("%d",a[i].choice+j);
		}
		a[i].num = i;
	}
	sort(a,a+N,cmp);
	int pre = a[0].GI + a[0].GE;
	int pre_school = a[0].choice[0];
	int pre_GE = a[0].GE;
	school[a[0].choice[0]].push_back(a[0].num);
	for(int i = 1; i < N;i++)
	{
		bool flag = true;
		for(int j = 0;j < K; j++)
		{
			if(school[a[i].choice[j]].size() < cap[a[i].choice[j]])
			{
				flag = false;
				school[a[i].choice[j]].push_back(a[i].num);
				pre_school = a[i].choice[j];
				break;
			}
			if(a[i].GE == pre_GE && a[i].GI + a[i].GE == pre && a[i].choice[j] == pre_school)
			{
				flag = false;
				school[a[i].choice[j]].push_back(a[i].num);
				pre_school = a[i].choice[j];
				break;
			}
		}
		if( flag )
			pre_school = -1;
		pre = a[i].GI + a[i].GE;
		pre_GE = a[i].GE;
	}
	for(int i = 0; i < M; i++)
	{
		sort(school[i].begin(),school[i].end());
		for(int j = 0; j < school[i].size();j++)
		{
			printf("%d",school[i][j]);
			if( j != school[i].size() - 1)
			printf(" ");
		}
		printf("\n");
	}
}
