#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;
#define MAX 100010
int pre[MAX];
int count[MAX];
int exist[MAX];
int find(int n)
{
	if(pre[n] == n)
		return n;
	else
	{
		pre[n] = find(pre[n]);
		return pre[n];
	}
}
void merge(int a, int b)
{
	int pre_a = find(a);
	int pre_b = find(b);
	if(pre_a == pre_b)
		return;
	else
		pre[pre_a] = pre_b;
}
int main()
{
	int K; cin >> K;
	for(int i = 1; i < MAX ;i++)
		pre[i] = i;
	for(int i = 0; i < K; i++)
	{
		int r;
		int  N; scanf("%d",&N);
		scanf("%d",&r); exist[r] = 1;
		for(int j = 0; j < N - 1; j++)
		{
			int t; scanf("%d",&t);
			exist[t] = 1;
			merge(r,t);
		}

	}
	int n_t = 0, n_b = 0;
	for(int i = 1; i <= MAX;i++)
	{
		if(exist[i])
		{
			int t = find(i);
			count [t]++;
		}
	}
	for(int i = 1; i <= MAX ;i++)
	{
		if(count[i] != 0 && exist[i])
		{
			n_t ++;
			n_b += count[i];
		}
	}
	cout << n_t <<' '<<n_b << endl;
	int q; cin >> q;
	for(int i = 0; i < q;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		if(find(a) == find(b))
			cout << "Yes" <<endl;
		else
			cout << "No" << endl;
	}
}
