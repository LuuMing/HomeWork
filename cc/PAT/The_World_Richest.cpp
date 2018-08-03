#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int K;
struct Person
{
	char name[10];
	int age;
	int worth;
	friend bool operator < (const Person & p1,const Person & p2)
	{
		return p1.age < p2.age;
	}
};
Person p[100001];
bool cmp(const Person & p1,const Person & p2)
{
	if(p1.worth != p2.worth)
	{
		return p1.worth > p2.worth;
	}
	else if (p1.age != p2.age)
	{
		return p1.age < p2.age;
	}
	else
	{
		int  t = strcmp(p1.name,p2.name);
		if( t  > 0)
			return false;	
		else
			return true;
	}

}
int main()
{
	cin >> N >> K;
	for(int i = 0; i < N;i++)
	{
		scanf("%s%d%d",p[i].name,&p[i].age,&p[i].worth);
	}
	sort(p,p+N,cmp);
	for(int i = 0; i < K;i++)
	{
		int M,A_min,A_max;
		int cnt = 0;
		scanf("%d%d%d",&M,&A_min,&A_max);
		printf("Case #%d:\n",i+1);
		Person t_p;
		t_p.age = A_min;
		for(auto j = lower_bound(p,p+N,t_p); j != (p + N) && cnt < M;j++)
		{
			if(j->age >= A_min && j->age <= A_max)
			{
				printf("%s %d %d\n",j->name,j->age,j->worth);
				cnt++;
			}
		}
		if(cnt == 0)
			printf("None\n");
	}	
}
