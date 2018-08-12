/**************************
	@author:LuMing
	@date:18/8/12 22:26~23:06
**************************/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 101
using namespace std;
struct node
{
	int left; int right; int data;
};
int sequence[MAX];
node n[MAX];
vector<node> v;
int idx = 0;
void insert(int root)
{
	if(n[root].left !=-1)
	{
		insert(n[root].left);
	}
	n[root].data = sequence[idx++];
	if(n[root].right != -1)
		insert(n[root].right);
}
void t(int root)
{
	queue<node> q;
	q.push(n[root]);
	while(!q.empty())
	{
		node top = q.front();
		v.push_back(top);
		q.pop();
		if(top.left != -1)
		{
			q.push(n[top.left]);
		}
		if(top.right != -1)
			q.push(n[top.right]);
	}
}
int main()
{
	int N; cin >> N;
	for(int i = 0; i < N; i++)
	{
		scanf("%d%d",&n[i].left,&n[i].right);
	}
	for(int i = 0; i< N;i++)
	{
		scanf("%d",sequence+i);
	}
	sort(sequence,sequence+N);
	insert(0);
	t(0);
	for(int i = 0; i < v.size();i++)
	{
		cout << v[i].data;
		if(i != v.size()-1)
			cout << ' ';
	}
}
