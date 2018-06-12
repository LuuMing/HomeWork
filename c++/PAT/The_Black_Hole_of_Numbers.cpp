#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
bool check(char * num)
{
	for(int i = 1; num[i] != 0;i++ )
	{
		if(num[i] != num[i-1])
			return false;
	}

	return true;
}
char num[10];
int main()
{
	scanf("%s",num);
	if(strcmp(num,"6174") == 0)
	{
		printf("6174 - 6174 = 0000");
		return 0;
	}
	num[4] = 0;
	for(int i = 3;i >=0;i-- )
		if(num[i] == 0)
			num[i] = '0';
	while(!check(num)&& strcmp(num,"6174")!=0 )
	{
		sort(num,num+strlen(num));
		int a = 0,b = 0;
		for(int i = 0; num[i]!=0;i++)
			a =10* a + (num[i]- '0');
		for(int i = strlen(num)-1; i >= 0;i--)
			b =10* b + (num[i] - '0');
		int result = b - a;
		printf("%04d - %04d = %04d\n",b,a,result);
		int j = 3;
		while(result)
		{
			num[j] = (result % 10) + '0';
			j--;
			result /= 10;
		}
		while(j >= 0)
		{
			num[j] = '0';
			j--;
		}
	}


		sort(num,num + 4);
		int a = 0,b = 0;
		for(int i = 0; i < 4;i++)
			a =10* a + (num[i]- '0');
	if(check(num))
	{
	
		printf("%04d - %04d = 0000",a,a);
	}
}
