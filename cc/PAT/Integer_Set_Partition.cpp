/*************************
	@author: LuMing
	@date: 18/8/17 12:50~13:13
*************************/
#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;
int num[MAX];
int main()
{
	int s1 = 0, s2 = 0;
	int n1 = 0,  n2 = 0;
	int N; cin >> N;
	for(int i = 0; i < N;i++)
	{
		scanf("%d",num+i);
	}
	sort(num,num+N);
	if(N % 2 == 0)
	{
		int i = 0, j = N-1;
		for(i = 0; i < N/2; i++)
		{
			s1 += num[i];
			n1++;
		}
		for(j = N/2; j < N; j++)
		{
			s2 += num[j];
			n2++;
		}
		cout << n1 - n2 <<' '<<abs(s1 - s2);
		return 0;
	}
	else
	{
		int i = 0, j = N-1;
		while( i != j)
		{
			s1 += num[i];
			n1 ++;
			s2 += num[j];
			n2++;
			i++, j--;
		}
	
		if( abs(s1 + num[i] - s2) > abs(s2 + num[i] - s1)  )
		{
			n1++;
			cout << n1 - n2 <<' ' << abs(s1 + num[i] - s2);
		}
		else
		{
			n2++;
			cout << abs(n1 - n2) <<' ' << abs(s2 + num[i] - s1);
		}
	}
}
