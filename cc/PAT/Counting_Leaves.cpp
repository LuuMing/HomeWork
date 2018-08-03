#include<cstdio>
#include<vector>
#include<iostream>
#include<map>
#include<sstream>
using  namespace std;
map<int,int> level_num;                            //store the num of leaf nodes for each level
struct node
{
	int ID;
	vector<int> child;
	bool root = true;
	int level = -1;
};
void DFS(vector<node>& nodes,int root,int level)   //DFS, to mark the level for each node
{
	nodes[root].level = level;
	for(auto &i: nodes[root].child)
	{
		DFS(nodes,i,level+1);
	}
}
void BFS(vector<node> nodes,int root)              //BFS, count leaf node through map
{
	vector<int> queue;
	queue.push_back(root);
	while(!queue.empty())
	{
		if(nodes[queue.front()].child.empty())
		{
			level_num[nodes[queue.front()].level] += 1;
		}
		else
		{
			for(auto &i:nodes[queue.front()].child)
			{
				queue.push_back(i);
			}
		}
		queue.erase(queue.begin());
	}
}
int main()
{
	int N,M;
	cin >> N >> M;
	int num, K,t;
	stringstream ss;
	vector<node> nodes(N+1);
	for(int i = 0; i < M;i++)
	{
		scanf("%d%d",&num,&K);	
		for(int i = 0; i < K;i++)
		{
			scanf("%d",&t);
			nodes[num].child.push_back(t);
			nodes[t].root =false;
		}
	}
	int n_root = 0;
	for(int i = 1; i < N+1;i++)
	{
		if(nodes[i].root)
		{
			n_root = i;
		}
	}
	DFS(nodes,n_root,1);
	for(int i = 1; i < N+1;i++)
	{
		level_num.insert(make_pair(nodes[i].level,0));
	}
	BFS(nodes,n_root);
	for(auto &i:level_num)
	{
		ss << i.second<<' ';
	}
	string s = ss.str();
	s.erase(s.end()-1);
	cout << s;
}
