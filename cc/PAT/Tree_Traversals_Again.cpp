#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
	int data;
	node * left;
	node * right;
};
int N;
int times = 0;
int out_times = 0;
void output(node * root)
{
	if(root)
	{
		if(root->left)
		{
			output(root->left);
		}
		if(root->right)
		{
			output(root->right);
		}
		if(out_times != N-1)
		{
			cout << root->data << ' ';
			out_times++;
		}
		else
		{
			cout << root->data;
		}
	}
}
node * build()
{
	node * root = NULL;
	char query[5];
	int t;
	if (times < 2*N)
	{
		scanf("%s",query);
		if(query[1]=='u')
		{
			cin >> t;
			root = new node;
			root->data = t;
			times++;
		}
		else
		{
			times++;
			return root;
		}
		root -> left = build();
		root -> right = build();
	}
	return root;
}
int main()
{
	cin >> N;
	node * root = build();
	output(root);
}
