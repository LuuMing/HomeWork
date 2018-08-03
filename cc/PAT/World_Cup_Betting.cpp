#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	double result = 1;
	char output[3];
	for(int i = 0;i < 3;i++)
	{
		double t = 0;
		double max = 0;
		int num = 0;
		for(int j = 0;j < 3;j++)
		{
			cin >> t;
			if(t > max)
			{
				max = t;
				num = j;
			}
		}
		if(num == 0)
		{
			output[i] = 'W';
		}
		else if(num == 1)
		{
			output[i] = 'T';
		}
		else
		{
			output[i]='L';
		}
		result *= max;
	}
	result = (result*0.65-1)*2;
	for(int i = 0;i < 3;i++) printf("%c ",output[i]);
	printf("%.2f",result);
}
