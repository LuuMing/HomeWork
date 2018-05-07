#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAX 10001
using namespace std;
int N;
int K;
int M;
struct person
{
	int total;
	int score[6] = {-1,-1,-1,-1,-1,-1};
	int id;
	bool pass = false;
};
person p[MAX];
int problem[6];
bool cmp(const person & p1, const person &p2)
{
	if(p1.total != p2.total)
	{
		return p1.total > p2.total;
	}
	else 
	{
		int num1 = 0; int num2 = 0;
		for(int i = 1; i <= K;i++)
		{	
			if(p1.score[i] == problem[i])
				num1++;
			if(p2.score[i] == problem[i])
				num2++;
		}
		if(num1 != num2)
			return num1 > num2;
		else
			return p1.id < p2.id; 
	}	
}
int main()
{
	cin >> N >> K >> M;
	for(int i = 1; i <= K; i++)	cin >> problem[i];
	for(int i = 0; i < M; i++)
	{
		int id,p_id,score;
		scanf("%d%d%d",&id,&p_id,&score);
		p[id].score[p_id] = max(p[id].score[p_id],score);
		if(p[id].score[p_id] == -1)
			p[id].score[p_id] = 0;
		else
			p[id].pass = true;
	}
	for(int i = 1; i <= N; i++)
	{
		p[i].id = i;
		for(int j = 1; j <= K;j++)
		{
			if(p[i].score[j] != -1)
			p[i].total += p[i].score[j];
		}
	}
	sort(p+1,p+N+1,cmp);
	int rank = 1;
	int pre_total = p[1].total;
	for(int i = 1; i <= N ; i++)
	{
		if(p[i].pass )
		{
			if(p[i].total != pre_total)
			{
				rank = i;	
				pre_total = p[i].total;
			}
			printf("%d %05d %d",rank,p[i].id,p[i].total);
			for(int j = 1; j <= K;j++)
			{
				if(p[i].score[j]>=0)
					printf(" %d",p[i].score[j]);
				else
					printf(" -");
			}
				printf("\n");
		}
	}
}
