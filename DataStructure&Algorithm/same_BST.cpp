#include<iostream>
using namespace std;
struct node
{
	int data;
	node * left;
	node * right;
};
node* insert(node * root, int data)
{
	if(!root)
	{
		root = (node*)malloc(sizeof(node));
		root -> data = data;
		root ->left = root->right =NULL;
	}
	else if (data > root->data)
	{
		root->right = insert(root->right,data);
	}
	else if (data < root->data)
	{
		root->left = insert(root->left,data);
	}
	return root;
}

node * build(int n)
{
	node * root = NULL;
	int data;
	for(int i = 0; i < n; i++)
	{
		cin >> data;
		root = insert(root,data);
	}
	return root;
}
bool same(node * r1, node * r2)
{
	if( !(r1||r2) ) //both are null
	{
		return true;
	}
	else if( !(r1 && r2)) // one of r is null
	{
		return false;
	}
	else
	{
		if(r1->data != r2->data) 
		{
			return false;
		}
		else
		{
			return same(r1->left,r2->left)&&same(r1->right,r2->right);
		}

	}
}
int main()
{
	int n;
	int test_case;
	while(cin >> n && n )
	{
		cin >> test_case;
		node * root = build(n);
		for(int i = 0; i < test_case; i++)
		{
			node * temp = build(n);
			if(same(root,temp))
			{
				cout << "Yes"<<endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
}
