#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_set>
#include<queue>
#define MAX 1001
using namespace std;
struct person
{
	vector<int> followed;
};
person p[MAX];
int L;
int N;
unordered_set<int> s;
void forward(int v)
{
	queue<int> q;
	q.push(v);
	int level = 0, last = v, tail = v;
	s.insert(v);
	while( !q.empty() && level < L)
	{
		int t = q.front();
		q.pop();
		for(int i = 0; i < p[t].followed.size();i++)
		{
			int w = p[t].followed[i];
			if(s.count(w))
				continue;
			q.push(w);
			tail = w;
			s.insert(w);
		}
		if(t == last)
		{
			level++;
			last = tail;
		}
	}
}
int main()
{
	cin >> N >> L;
	int K;
	for(int i = 1; i <= N; i++)
	{
		int m;scanf("%d",&m);
		for(int j = 0; j < m; j++)
		{
			int t; scanf("%d",&t);
			p[t].followed.push_back(i);
		}
	}
	cin >> K;
	for(int i = 0; i < K;  i++)
	{
		s.clear();
		int t; scanf("%d",&t);
		forward(t);
		if(s.count(t))
			cout << s.size()-1;
		else
			cout << s.size();
		if( i != K - 1)
		cout << endl;
	}
}
