#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
using namespace std;
int N;
int sum;
int num[100001];
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int t;  scanf("%d",&t);
		num[t] = i; //num[i] stands for: the element i is on position num[i]  
	}
	/*
	if use num[i] = t;
	then:
		num[i] stands for: the position i is element num[i]
	would make algorithm more complex to find non-order element
	*/
	int idx = 0;    //Do not need scan non-order element from begin
	while(true)
	{
		while( num[0] != 0)
		{	
			swap(num[0],num[num[0]]);
			sum++;
		}
		bool flag = false;
		for( ; idx < N;idx++)
		{
			if(num[idx] != idx)
			{
				flag = true;
				swap(num[0],num[idx]);
				sum++;
				break;
			}
		}
		if(!flag)
			break;
	}
	cout << sum;
}
