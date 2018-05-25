#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define MAX 51
char pre[MAX];
char in[MAX];
int N;
struct node
{
	char data;
	node * left = NULL;
	node * right = NULL;
};
node * build(char * inorder,char * preorder,int length)
{
	if(length ==0)
		return NULL;
	node * root = new node;
	root -> data = *preorder;
	int rootIndex;// the length of left tree
	for(rootIndex = 0; rootIndex < length;rootIndex++)
	{
		if(inorder[rootIndex] == root->data)
		{
			break;		
		}
	}
	root -> left = build(inorder,preorder+1,rootIndex);
	root -> right = build (inorder + rootIndex + 1,preorder + rootIndex + 1,length- (rootIndex +1));
	return root;
}
int get_high(node * root)
{
	if(!root)
	{
		return 1;
	}
	else
	{
		return max(get_high(root->left)+1,get_high(root->right)+1);
	}
}
int  main()
{
	cin >> N;
	scanf("%s",pre);
	scanf("%s",in);
	node * n = build(in,pre,N-1);
	cout << get_high(n) - 1;
}
