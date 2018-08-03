#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct person
{
	int id;
	char name[9];
	int grade;
};
class cmp
{
	int mode;
	
public:
	cmp(int m)
	{
		mode = m;
	}
	bool operator () (const person & p1,const person &p2)
	{
		if(mode == 1)
		{
			return p1.id < p2.id;
		}
		else if(mode == 2)
		{
			string name1 = p1.name;
			string name2 = p2.name;
			if(name1 != name2)
			{
				return name1 < name2;
			}
			else
			{
				return p1.id < p2.id;
			}
		}
		else
		{
			if(p1.grade != p2.grade)
			{
				return p1.grade < p2.grade;
			}
			else
			{
				return p1.id < p2.id;
			}
		}
	}
};


int main()
{
	int N,mode;
	cin >> N >> mode;
	vector<person> p(N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %s %d",&p[i].id,p[i].name,&p[i].grade);
	}
	sort(p.begin(),p.end(),cmp(mode));
	for(auto &i:p)
	{
		printf("%06d %s %d\n",i.id,i.name,i.grade);
	}
}
