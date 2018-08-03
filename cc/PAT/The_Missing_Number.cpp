#include<iostream>
#include<algorithm>
#include<cstdio>
#include<unordered_set>
using namespace std;
int num[100001];
unordered_set<int> s;
int main()
{
	int N; cin >> N;
	for(int i = 0; i < N;i++)
	{	scanf("%d",num+i);
		s.insert(num[i]);
	}
	sort(num,num+N);
	int min = 1;
	for(int i = 0; i < N; i++)
	{
		if(num[i] < 0 )
			continue;
		if( !s.count(num[i] + 1))
		{
			min = num[i] + 1;
			break;
		}	
	}
	cout << min;
}