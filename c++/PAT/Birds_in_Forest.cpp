#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 105
int pre[MAX];
int count[MAX];
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
		pre[a] = pre_b;
	count[find(b)]++;	
}
int main()
{
	int max_n = -1;
	int K; cin >> K;
	for(int i = 0; i < MAX ;i++)
		pre[i] = i;
	for(int i = 0; i < K; i++)
	{
		int m_g = -1;
		int m = -1;
		int  N; scanf("%d",&N);
		vector<int> v(N+1);
		
		for(int j = 0; j < N; j++)
		{
			scanf("%d",&v[j]);
			if(v[j] > max_n)
				max_n = v[j];
			if(count[v[j]] > m)
			{
				m = count[v[j]];
				m_g = find(v[j]);			
			}
		}	
		for(int j = 0; j < N;j++)
		{
			merge(v[j],m_g);
		}
	}
	int n_t = 1;
	int max_t = -1;
	for(int i = 1; i <= max_n;i++)
	{
		if(pre[i] == i)
			n_t++;
	}		
	for(int i = 1; i <= max_n;i++)
		if(count[i] > max_t)
			max_t = count[i];
	cout << n_t <<' '<< max_t << endl;
	int q; cin >> q;
	for(int i =0; i < q;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		if(find(a) == find(b))
			cout << "Yes" <<endl;
		else
			cout << "No" << endl;
	}
}