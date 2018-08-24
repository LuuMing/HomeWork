/*****************
	@author: LuMing
	@date: 18/8/24 19:50~20:26
*****************/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
vector<int> tmp;
int tmp_total = 0;
vector<int> result;
int result_max;
int N,K,P;
bool found = false;
bool cmp(const int & i1, const int & i2)
{
	return i1 > i2;
}
void dfs(int N,int stp)
{

	if(stp == K && N == 0)
	{
		if(tmp_total > result_max)
		{
			result_max = tmp_total;
			result = tmp;
		}
		return;
	}
	if(N < 0 || stp >= K )
		return;
	for(int i = N-1; i >= 1; i--)
	{
		tmp.push_back(i);
		tmp_total += i;
		dfs(N - pow(i,P),stp+1);
		tmp_total -= i;
		tmp.pop_back();
	}

}
int main()
{
	cin >> N >> K >> P;
	dfs(N,0);
	if(result.size() > 0)
	{
		sort(result.begin(),result.end(),cmp);
		printf("%d = ",N);
		for(int i = 0; i < result.size();i++)
		{
			printf("%d^%d",result[i],P);
			if(i!=result.size()-1)
			{	
				printf(" + ");
			}
		}
	}
	else
	{
		cout << "Impossible";
	}
}
