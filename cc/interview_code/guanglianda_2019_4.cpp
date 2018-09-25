/*
	不使用队列对带有父指针的二叉树进行广度遍历
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct DoubleDirectionBinTree
{
	DoubleDirectionBinTree * parent;
	DoubleDirectionBinTree * left;
	DoubleDirectionBinTree * right;
	int value;
};
map<int,vector<int>> bfs(DoubleDirectionBinTree * root,map <int,vector<int>> & m,int depth)
{
	m[depth].push_back(root -> value);
	if( root -> left)
	{
		m = bfs(root-> left,m,depth + 1);
	}
	if( root -> right)
	{
		m = bfs(root -> right,m,depth+1);
	}
	return m;
}
void BFS(DoubleDirectionBinTree * root)
{
	map<int, vector<int> > m;
	m = bfs(root,m,0);
	for(auto i:m)
	{
		for(auto j : i.second)
		{
			cout << j <<' ';
		}
		cout << endl;
	}
}
int main()
{
	BFS()
}

