#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> in;
vector<int> pre;
bool flag = false;
void build(int root, int start, int end)
{
	if(start > end || flag)
		return;
	int i = start;
	while(i < end && in[i] != pre[root])
		i++;
	
	build( root + 1,start,i-1);
	build( root + (i-start) + 1, i+1 , end);
	if(!flag)
	{
		flag = true;
		printf("%d",pre[root]);
	}
}
int main()
{
	int N; scanf("%d",&N);
	pre.resize(N); in.resize(N);
	for(int i = 0; i < N;i++)
	scanf("%d",&pre[i]);
	for(int i = 0; i < N;i++)
	scanf("%d",&in[i]);
	build(0,0,N-1);
}
