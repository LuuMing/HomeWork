/*****************
	@author: LuMing
	@date: 18/8/25 21:32~22:28
*****************/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define MAX 401
int N,K,P;
int total;
vector<int> tmp,f;
vector<int> result;
int tmp_total;
void dfs(int s,int stp) // dfs from big to small number
{
	if(tmp.size() > K || s > N)
		return;
	if(s == N && tmp.size() == K)
	{
		if(tmp_total > total)
		{
			total = tmp_total;
			result = tmp;
		}
		return;
	}
	
	if(stp  - 1 >= 0)
	{
		tmp.push_back(stp);
		tmp_total += stp;
		dfs(s+f[stp],stp);
		tmp.pop_back();
		tmp_total -= stp;
		dfs(s,stp - 1);
	}
}
int main()
{
	cin >> N >> K >> P;
	int tmp = 0;
	int i = 0;
	while(tmp <= N)
	{
		f.push_back(tmp);
		tmp = pow(++i,P);	
	}
	dfs(  0	,f.size() - 1);
	if(result.size() != 0)
	{
		printf("%d = %d^%d", N, result[0], P);
       		for (int i = 1; i < result.size(); i++)
            		printf(" + %d^%d", result[i], P);
		printf("\n");

        }
       	else
	{
		cout << "Impossible" << endl;
	}
}
