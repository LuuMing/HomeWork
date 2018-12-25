/*
	数数字游戏
*/
#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);  
	int  flag = 1;
	int num;
	int max_reach = -1;
	char space ;
	int i = 0;
	char line[1000001];
	int f[10000];
	f[0] = 1;
	f[2] = 2;
	for(int i = 3; i<= 10000;i++)
		f[i] = f[i-1] + f[i - 2];
	while(cin.getline(line,1000000))
	{
		int num1,num2;
		sscanf(line,"%d %d",&num1,&num2);
		int sum = num1 + num2;
		int t = 0;
		while(sum > 0)
		{
			sum -= f[t];
			t++;
		}
		if(t % 2 == 0)
			printf("Xiaoai Win\n");
		else
			printf("Xiaobing Win\n");
	}
	
	return 0;
}
