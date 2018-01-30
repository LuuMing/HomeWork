#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
class Myset:public set<int>
{
	public:
		int common(Myset & s2)
		{
			vector<int> result(this->size()+s2.size());
			vector<int>::iterator end = set_intersection(this->begin(),this->end(),s2.begin(),s2.end(),result.begin());
			result.resize(end-result.begin());
			return result.size();
		} 
		int total(Myset &s2)
		{
			vector<int> result(this->size()+s2.size());
			vector<int>::iterator end = set_union(this->begin(),this->end(),s2.begin(),s2.end(),result.begin());
			result.resize(end-result.begin());
			return result.size();
		}
};
int main()
{
	int N = 0;
	int M = 0;
	int K = 0;
	int a = 0;
	int b = 0;
	int tem = 0;
	cin >> N;
	Myset * s = new Myset [N];
	for(int i = 0; i < N; i++)
	{
		cin>>M;
		for(int j = 0; j < M;j++)
		{	
			cin >> tem;
			s[i].insert(tem);
		}
	}

	cin >> K;
	int * q1 = new int [K];
	int * q2 = new int [K]; 
	for(int i = 0; i < K;i++)
	{
		cin >> q1[i] >> q2[i];
	}
	for(int i = 0; i < K;i++)
	{
		printf("%.1f\%\n",100*s[q1[i]-1].common(s[q2[i]-1]) / (double)s[q1[i]-1].total(s[q2[i]-1]));
	}
	return 0;
} 
