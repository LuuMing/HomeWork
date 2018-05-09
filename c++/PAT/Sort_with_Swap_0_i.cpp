#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N;
int sum;
int num[100001];
int main()
{
	cin >> N;
	int p;
	for(int i = 0; i < N;i++)
	{
		scanf("%d",&num[i]);
		if(num[i] == 0)
			p = i;
	}
	while(true)
	{
		if(num[0] != 0)
		{
			for(int i = 0; i < N;i++)
			{
				if(num[i] == p)
				{
					swap(num[i],num[p]);
					p = i;
					sum++;
					break;
				}
			}
		}
		else
		{
			bool flag = false;
			for(int i = 0; i < N;i++)
			{
				if(num[i] != i)
				{
					flag = true;
					p = i;
					swap(num[0],num[i]);
					sum++;
					break;
				}
			}
			if(!flag)
			{
				break;
			}
		}	
	}
	cout << sum;
}
