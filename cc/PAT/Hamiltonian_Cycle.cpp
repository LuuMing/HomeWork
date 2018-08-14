/************************
	@author:LuMing
	@date:18/8/14 09:25~10:01
*************************/
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
#define MAX 250
unordered_set<int> v[MAX];
int N,M,K;
int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].insert(b);
		v[b].insert(a);
	}
	cin >> K;
	for(int i = 0; i < K; i++)
	{
		int n; scanf("%d",&n);int start;  int end;
		unordered_set<int> s;
		s.clear(); 
		scanf("%d",&start); 
		int s_c = start;
		s.insert(start);
		bool flag = true;
		for(int j = 1; j < n-1; j++)
		{
			int t; scanf("%d",&t);
			if(v[start].count(t) && !s.count(t))
			{
				s.insert(t);
			}
			else
			{
				flag = false;
			}
			start = t;
		}
		scanf("%d",&end);
		if(s_c == end && s.size() == N && flag && v[start].count(end)) //Don't forget last edge
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << endl;
	}
}

