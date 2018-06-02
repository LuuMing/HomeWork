#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

struct Person
{
	char name[9];
	int age;
	int worth;
	friend bool operator < (const Person & p1,const Person & p2)
	{
		return p1.age < p2.age;
	}
};
bool cmp2(const Person & p1,const Person & p2)
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
		int t = strcmp(p1.name,p2.name);
		if(t > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
int N;
int K;
vector<Person> p;
int main()
{
	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		Person t_p;
		scanf("%s%d%d",t_p.name,&t_p.age,&t_p.worth);
		p.push_back(t_p);
	}
	sort(p.begin(),p.end());
	for(int i = 0; i < K; i++)
	{
		int M,Amin,Amax;
		vector<Person> s;
		scanf("%d%d%d",&M,&Amin,&Amax);
		Person cmp_p; cmp_p.age = Amin;

		int n = 0;
		for(auto j = lower_bound(p.begin(),p.end(),cmp_p); j != p.end();j++)
		{
			if(j->age >= Amin && j->age<= Amax)
			{
				s.push_back(*j);
				n++;
			}
			if(j->age>Amax)
			{
				break;
			}
		}
		sort(s.begin(),s.end(),cmp2);
		printf("Case #%d:\n",i+1);
		for(int k = 0; k < s.size() && k < M;k++)
		{
			printf("%s %d %d\n",s[k].name,s[k].age,s[k].worth);
		}
		if(n==0)
			printf("None\n");
	}	
}
