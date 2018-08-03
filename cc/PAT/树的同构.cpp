#include<iostream>
#include<vector>
#define MAX 100
using namespace std;
struct node
{
	char data;
	int left;
	int right;
	bool root = true;
};
node tree1[MAX],tree2[MAX];
int build(struct node tree[])
{
	int N1;
	cin >> N1;
	for(int i = 0; i < N1; i++)
	{
		cin >> tree[i].data;
		char l,r;
		cin >> l >> r;
		if(l != '-')
		{
			tree[i].left = l-'0';
			tree[tree[i].left].root = false;
		}
		else
		{
			tree[i].left = -1;
		}
		if(r != '-')
		{
			tree[i].right = r-'0';
			tree[tree[i].right].root = false;
		}
		else
		{
			tree[i].right = -1;
		}
	}
	for(int i = 0; i < N1 ;i++)
	{
		if(tree[i].root)
		{
			return i;
		}
	}
	return -1;
}
bool is(int root1,int root2)
{
	if(root1 == -1 && root2 == -1) //both are NULL
	{
		return true;
	}
	if((root1 == -1 && root2!= -1)|| (root1!=-1 && root2 == -1))
	{
		return false;
	}
	if( tree1[root1].data != tree2[root2].data)
	{
		return false;
	}
	//above: root
	//below: child
	if(tree1[root1].left==-1 && tree2[root2].left == -1 )
	{
		return is( tree1[root1].right,tree2[root2].right );
	}
	else if(tree1[tree1[root1].left].data == tree2[tree2[root2].left].data)
	{
		return is( tree1[root1].left,tree2[root2].left ) && is(tree1[root1].right,tree2[root2].right);
	}
	else
	{
		return is(tree1[root1].left, tree2[root2].right) && is (tree1[root1].right,tree2[root2].left);
	}
}
int main()
{
	int R1,R2;
	R1 = build(tree1);
	R2 = build(tree2);
	if(is(R1,R2))
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}
