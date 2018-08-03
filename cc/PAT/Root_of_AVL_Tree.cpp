#include<iostream>
using namespace std;
struct node
{
	int data;
	node * left;
	node * right;
};
int get_high(node * root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		int left = get_high(root->left) ;
		int right = get_high(root->right) ;
		return max(left,right)+1;
	}
}
node * rotateRight(node * root)
{
	node * child = root-> left;
	root -> left = child->right;
	child -> right = root;
	return child;
}
node * rotateLeft(node * root)
{
	node * child = root->right;
	root->right = child->left;
	child ->left = root;
	return child;
}
node * rotateLeftRight(node * root)
{
	root -> left = rotateLeft(root->left);
	return rotateRight(root);
}
node * rotateRightLeft(node * root)
{
	root -> right = rotateRight(root->right);
	return rotateLeft(root);
}
node* insert(node * root, int data)
{
	if(!root)
	{
		root = new node;
		root -> data = data;	
	}
	else if( data < root -> data)
	{
		root -> left = insert(root->left,data);
		int factor = get_high(root->left) - get_high(root->right);
		if(factor == 2)
		{
			if(data < root ->left ->data)
			{
				root = rotateRight(root);
			}
			else 
			{
				root = rotateLeftRight(root);
			}
		}
	}
	else 
	{
		root -> right = insert(root->right,data);
		int factor = get_high(root->left) - get_high(root->right);
		if(factor == -2)
		{
			if(data > root ->right ->data)
			{
				root = rotateLeft(root);
			}
			else 
			{
				root = rotateRightLeft(root);
			}
		}
	}
	return root;
}


int main()
{
	int N;
	cin >> N;
	node * root;
	for(int i = 0; i < N;i++)
	{
		int t;
		cin >> t;	
		root = insert(root,t);
	}
	cout << root->data;
}
