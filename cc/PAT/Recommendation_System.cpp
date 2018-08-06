/***********************
	@date:2018/8/6 09:40~ 09:55 + 10:43~10：57
	@author: LuMing
***********************/
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iostream>
using namespace std;
unordered_map<int,int> m;
vector<pair<int,int>> v;
bool cmp(const pair<int,int> & p1, const pair<int,int> & p2)
{
	if( p1. second != p2.second)
		return p1.second > p2.second;
	else
		return p1.first < p2.first;
}
int N,K;
int main()
{
	cin >> N >> K;
	int i0;
	cin >> i0;
	m[i0]++;
	for(int i = 1; i < N; i++)
	{
		int t; scanf("%d",&t);
		v.clear();
		for(auto ii:m)
			v.push_back(ii);
		sort(v.begin(),v.end(),cmp);
		printf("%d:",t);
		for(int j = 0; j < v.size() && j < K;j++)
		{
			printf(" %d",v[j].first);
		}
		m[t]++;
		printf("\n");
	}
}
