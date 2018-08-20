/******************
	@author: LuMing
	@date: 18/8/20 19:50~20:17
********************/
#include<iostream>
#include<queue>
#define MAX 21
using namespace std;
struct node
{
	int idx;
	int left = -1;
	int right = -1;
	bool root = true;
};
node n[MAX];
bool complete = true;
int idx;
void bfs(int root)
{
	bool no_child = false;
	queue<node> q;
	q.push(n[root]);
	while( !q.empty() )
	{
		node top = q.front();
		q.pop();
		if(top.left == -1)
		{
			no_child = true;		
		}
		else
		{
			if(no_child)
			{
				complete = false;
			}
			q.push(n[top.left]);
		}
		if(top.right == -1)
		{
			no_child = true;		
		}
		else
		{
			if(no_child)
			{
				complete = false;
			}
			q.push(n[top.right]);
		}
		idx = top.idx;
	}
}
int main()
{
	int N; cin >> N;
	int root;
	for(int i = 0; i < N; i++)
	{
		int l,r;
		if(scanf("%d",&l) == 1)
		{
			n[i].left = l;
			n[l].root = false;
		}
		if(scanf("%d",&r) == 1)
		{
			n[i].right = r;
			n[r].root = false;
		}
		n[i].idx = i;
	}
	for(int i = 0; i < N ;i++)
	{
		if( n[i].root)
		{
			root = i;
			break;	
		}
	}
	bfs(root);
	if(complete)
	{
		cout << "YES " <<idx;
	}
	else
	{
		cout << "NO "<<root;
	}
}
