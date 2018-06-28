#include<iostream>
#include<cstdio>
using namespace std;
int owner[100];
int eva[100];
int main()
{
	char c = 0; 
	int num = 0;
	int missing = 0;
	bool flag = true;
	while(c != '\n')
	{
		scanf("%c",&c);
		owner[c]++;
		num++;
	}
	c = 0;
	while(c!='\n')
	{
		scanf("%c",&c);
		if(owner[c] >=1)
		{
			num--;
			owner[c]--;
		}
		else
		{
			flag = false;
			missing ++;
		}
	}
	if(flag)
		cout << "Yes" <<' '<<num;
	else
		cout << "No "<<missing;
}
