#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 1005
using namespace std;
struct mooncake
{
	double total;
	double profit ;
};
bool cmp(const mooncake & m1,const mooncake & m2)
{
	return m2.total * m1.profit > m1.total * m2.profit;
}
mooncake m[MAX];
int N;
double D;
int main()
{
	double p = 0;
	cin >> N >> D;
	for(int i = 0; i < N;i++)
		scanf("%lf",&m[i].total);
	for(int i = 0; i < N;i++)
	{
		scanf("%lf",&m[i].profit);
	}
	sort(m,m+N,cmp);
	for(int i = 0; D>0 && i < N;i++)
	{
		double sell = min(D,m[i].total);
		p +=  sell/ m[i].total * m[i].profit;
		D -= sell;
		
	}	
	printf("%.2lf",p);
	
}

