#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	int cnt = 0;
	int N; cin >> N; double total = 0;
	for(int i = 0; i < N;i++)
	{
		bool flag = true;
		double t;
		char tmpa[50]; char tmpb[50];
		scanf("%s",tmpa);
		sscanf(tmpa,"%lf",&t);
		sprintf(tmpb,"%.2lf",t);
	
		for(int i = 0; i < strlen(tmpa);i++)
		{
			if(tmpa[i] != tmpb[i])
				flag = false;
		}
		if(!flag || t > 1000 || t < -1000 )
		{	
			printf("ERROR: %s is not a legal number\n",tmpa);
		}
		else
		{
			cnt ++;
			total += t;
		}
	}
	if(cnt == 0 )
		printf("The average of 0 numbers is Undefined");
	else if (cnt == 1)
		printf("The average of 1 number is %.2f",total);
	else
		printf("The average of %d numbers is %.2f",cnt,total/double(cnt));
	
}

