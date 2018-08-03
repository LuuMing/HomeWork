#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int windows[101];
struct customer
{
	int start;
	int process;
};
bool cmp(const customer & p1, const customer & p2)
{
	return p1.start < p2.start;
}
int main()
{
	int N;
	int K;
	cin >> N >> K;
	vector<customer> c;
	for(int i = 0; i < K;i++)
	{
		windows[i] = 8*3600;
	}
	for(int i = 0;i < N; i++)
	{
		int hh,mm,ss,pp;
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&pp);
		if( hh< 17)
		{
			c.push_back(customer{hh*3600+mm*60+ss,pp*60});	
		}
	}
	sort(c.begin(),c.end(),cmp);
	int total = 0;
	for(int i = 0; i < c.size(); i++)
	{
		sort(&windows[0],&windows[K]);
		if(c[i].start < windows[0])
		{
			total += windows[0] - c[i].start;
			windows[0] += c[i].process;
		}
		else
		{
			windows[0] = c[i].start + c[i].process;
		}
	}
	printf("%.1f",(double)total/ c.size()/60.0 );
}
