#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 100000
using namespace std;
struct recorder
{
	char name[11];
	char id[11];
	int grade;
};
recorder r[MAX];
int N;
bool cmp(const recorder & r1, const recorder & r2)
{
	return r1.grade > r2.grade;
}
int main()
{
	int l_b,u_b;
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		scanf("%s%s%d",r[i].name,r[i].id,&r[i].grade);
	}
	cin >> l_b >> u_b;
	sort(r,r+N,cmp);
	bool flag =  true;
	for(int i = 0; i < N;i++)
	{
		if(r[i].grade >= l_b && r[i].grade <= u_b)
		{
			flag = false;
			printf("%s %s\n",r[i].name,r[i].id);
		}
	}
	if(flag)
	{
		cout << "NONE"<<endl;
	}
}
