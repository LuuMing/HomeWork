#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int N;
int K;

struct info
{
	char r_num[15];
	int grade;
	int local_number;
	int rank;
	int local_rank;
};

bool cmp(const info & i1,const info & i2)
{
	if(i1.grade != i2.grade)
		return i1.grade > i2.grade;
	else
	{ 
		int mark = strcmp( i1.r_num, i2.r_num);
		if(mark>0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
int main()
{
	vector<info> total;
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		scanf("%d",&K);
		vector<info> local(K);
		for(int j = 0; j < K; j++)
		{
			scanf("%s%d",local[j].r_num,&local[j].grade);
			local[j].local_number = i+1;
		}
		sort(local.begin(),local.end(),cmp);
		local[0].local_rank = 1;
		for(int k = 1; k < K; k++)
		{
			if(local[k].grade == local[k-1].grade)
			{
				local[k].local_rank = local[k-1].local_rank;
			}
			else
			{
				local[k].local_rank = k+1;
			}
		}
		total.insert(total.end(),local.begin(),local.end());
	}
	sort(total.begin(),total.end(),cmp);
	total[0].rank = 1;
	for(int i = 1; i < total.size(); i++)
	{
		if(total[i].grade == total[i-1].grade)
		{
			total[i].rank = total[i-1].rank;
		}
		else
		{
			total[i].rank = i+1;
		}
	}
	cout << total.size()<<endl;
	for(int i = 0; i < total.size();i++)
	{
		printf("%s %d %d %d\n",total[i].r_num,total[i].rank,total[i].local_number,total[i].local_rank);
	}
}
