#include<iostream>
#include<algorithm>
#include<set>
#define MAX 50002
using namespace std;
struct node
{
	int idx;
	int cnt;
	bool operator < (const node & n2) const 
	{
		return cnt != n2.cnt? cnt > n2.cnt:idx < n2.idx;
	}
};
set<node> s;
int num[MAX];
int N,K;
int main()
{
	cin >> N >> K;
	int e1; cin >> e1; 
	node t;
	t.idx = e1;
	t.cnt = 1;
	s.insert(t);
	num[e1]++;
	for(int i = 1; i < N; i++)
	{
		int k = 0;
		int elem_idx; scanf("%d",&elem_idx);
		printf("%d:",elem_idx);
		for(auto jj = s.begin(); jj != s.end() && k < K; jj++,k++)
		{
			printf(" %d",jj->idx);
		}
		printf("\n");
		t.idx = elem_idx; t.cnt = num[elem_idx];
		auto it = s.find(t);
		if(it != s.end())
		{
			s.erase(it);
		}
		num[elem_idx]++;
		t.idx = elem_idx; t.cnt = num[elem_idx];
		s.insert(t);
	}
}
