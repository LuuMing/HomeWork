#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N;
int n;
int num[100001];

void to_p_zero(int p)
{
	if(p == 0)
	{
		return ;
	}
	else
	{
		for(int i = 0; i < N;i++)
		{
			if(num[i] == p)
			{
				n++;
				swap(num[i],num[p]);
				 to_p_zero(i);
				break;
			}
		}
	}
}
int main()
{
	cin >> N;
	int p = 0;
	int nn = 0;
	for(int i = 0; i < N;i++)
	{
		scanf("%d",&num[i]);
		if(num[i] == 0)
			p = i;
	}
	while(true)
	{
		bool flag = true;
		to_p_zero(p);
		for(int i = 0; i < N; i++)
		{
			
			if(num[i]!=i)
			{
				flag = false;
				p = i;
				swap(num[0],num[i]);
				n++;
				break;
			}
		}
		if(flag)
			break;
	}
		cout << n + nn ;
}
