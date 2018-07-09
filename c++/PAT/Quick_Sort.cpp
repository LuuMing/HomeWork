#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int num[100001];
int l_max[100001];
int r_min[100001];
vector<int> v;
int main()
{
	int N; cin >> N;
	int Max = -1;
	int Min = 10e8;
	for(int i = 0; i  < N ; i ++)
	{
		scanf("%d",num+i);
		if(num[i] > Max)
		{
			Max  = num[i];
		}
		l_max[i+1] = Max;
	}
	for(int i = N-1 ; i >= 1; i--)
	{
		if(num[i] < Min)
		{
			Min = num[i];
		}
		r_min[i-1] = Min;
	}
	l_max[0] = num[0];
	r_min[N-1] = num[N-1];
	for(int i = 0; i < N;i++)
	{
		if( l_max[i] <= num[i] && r_min[i] >= num[i])
			v.push_back(num[i]);
	}
	cout << v.size() << endl;
	sort(v.begin(),v.end());
	for(int i = 0; i < v.size();i++)
	{
		cout << v[i];
		if( i != v.size() -1)
		cout << ' ';
	}
	cout << endl;
}
