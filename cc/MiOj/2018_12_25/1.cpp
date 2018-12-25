/*
	小米兔跳格子
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
	while(cin.getline(line,1000000))
	{
	char *p = strtok(line," ");
	while(p)
	{
		sscanf(p,"%d",&num);
		p = strtok(NULL," ");
		if(i + num > max_reach)
		max_reach=  (i + num);
		if( max_reach == i && p!=NULL)
		{	
			flag = 0;
		}
		if(!p)
			break;
		i++;
		
	}
	if(i == 0)
		printf("true\n");
	else if(flag)
		printf("true\n");
	else
		printf("false\n");
	i = 0;
	max_reach = 0;
	flag = 1;
	}
	
	return 0;
}
