/**************************
	@author:LuMing
	@date:18/8/10 ???~15:07
**************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int E[ 100001];
int N;
int main() 
{
	int N; cin >> N;
	for(int i = 0; i < N;i++)
	{	
		scanf("%d",E+i);
	}
	sort(E,E+N);
	int ans  = 0;
	for(int i = 0; i < N ;i++)
	{
		if(E[i] > N - i)
		{
			ans = N-i;
			break; 
		}
	}
	cout << ans;
}
