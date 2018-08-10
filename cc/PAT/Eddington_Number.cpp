/**************************
	@author:LuMing
	@date:18/8/10 14:17 ~ 14:39
**************************/
#include<iostream>
#include<map>
using namespace std;
map<int,int>m;
int main()
{
	int N; cin >> N;
	int max_m = -1;
	for(int i = 0; i < N;i++)
	{	
		int t; scanf("%d",&t);
		if(t > max_m)
			max_m = t;
		for(int j = t-1; j >= 0; j--)
		{
			m[j]++;
		}
	}
	int e = -1;
	for(auto i = m.rbegin(); i != m.rend(); i++)
	{
		if( i -> second >= i -> first)
		{
			cout << i->first;
			break;		
		}
	}
}
