#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct person
{
	string ID;
	int HH;
	int MM;
	int SS;
	int l_HH;
	int l_MM;
	int l_SS;
};
bool come_cmp(const person & p1,const person & p2)
{
	if (p1.HH!=p2.HH)
	{
		return p1.HH < p2.HH;
	}else if(p1.MM!=p2.MM)
	{
		return p1.MM < p2.MM;
	}else
	{
		return p1.SS < p2.SS;	
	}
}
bool leave_cmp(const person & p1,const person & p2)
{
	if (p1.l_HH!=p2.l_HH)
	{
		return p1.l_HH > p2.l_HH;
	}else if(p1.l_MM!=p2.l_MM)
	{
		return p1.l_MM > p2.l_MM;
	}else
	{
		return p1.l_SS > p2.l_SS;	
	}
}
int main()
{
	int N;
	cin >> N;
	vector<person> people(N);
	for(int i = 0; i < N;i++)
	{
		cin >> people[i].ID;
		scanf("%d:%d:%d %d:%d:%d",&people[i].HH,&people[i].MM,&people[i].SS,&people[i].l_HH,&people[i].l_MM,&people[i].l_SS);
	}
	sort(people.begin(),people.end(),come_cmp);
	cout << people[0].ID <<' ';
	sort(people.begin(),people.end(),leave_cmp);
	cout << people[0].ID;
}
