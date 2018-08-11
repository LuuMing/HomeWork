/******************
	@author:LuMing
	@date:2018/8/11 19:06~20:10
*******************/
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#define MAX 30
using namespace std;
int postorder[MAX];
int inorder[MAX];
vector<int> v;
map<int,vector<int>> m;
void build(int root, int start, int end,int idx)
{
	if(start > end)
		return;
	int i = start;
	for(;inorder[i] != postorder[root]; i++);
	build(root - (end - i +1 ), start,i-1,2*idx);
	build(root-1,i+1,end,2*idx+1);
	v[idx] = postorder[root];
}
int main()
{
	int i;
	int N; cin >> N;
	v.resize(10000,-1);
	for(i = 0; i < N;i++)
	{
		scanf("%d",inorder+i);
	}
	for(i = 0; i <N;i++)
	{
		scanf("%d",postorder+i);
	}
	build(N-1,0,N-1,1);
	int l = 1;
	i = 1;
	int total = 0;
	while( total != N)
	{
		int cnt =0;
		for(;cnt < pow(2,l-1); cnt++,i++)
		{
			if(v[i]!=-1)
			{
				m[l].push_back(v[i]);
			  total++;
			}
		}
		l++;
	}
	int j = -1;
	int cnt =0;
	for(auto i : m)
	{
		if(j==1)
			for(auto ii :i.second)
			{
				cout << ii;
				cnt++;
				if(cnt!=N)
				cout << ' ';
			}
		else
			for(auto ii=i.second.rbegin();ii!=i.second.rend();ii++)
			{	cout << *ii;
				cnt++;
				if(cnt!=N)
				cout << ' ';
			}
		j*=-1;
	}
}
