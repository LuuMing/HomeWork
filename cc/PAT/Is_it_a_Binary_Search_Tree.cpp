#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int N;
vector<int> input;
vector<int> pre;
struct node
{
	int data;
	node * left = NULL;
	node * right = NULL;
};
node * insert(node * root,int data)
{
	if(!root)
	{
		root = new node;
		root->data = data;
	}
	else
	{
		if(data >= root->data)
		{
			root->right = insert(root->right,data);
		}
		else
		{
			root->left = insert(root->left ,data);
		}
	}
	return root;
}

void preorder(node * root,int m)
{
	if(m==0)
	{
		if(root)
		{
			pre.push_back(root->data);
			preorder(root->left,m);
			preorder(root->right,m);
		}
		
	}
	else
	{
		if(root)
		{
			pre.push_back(root->data);
			preorder(root->right,m);
		preorder(root->left,m);	
		}
	
	}
}
int p = 0;
void post(node * root,int m)
{
	if(root)
	{
		if(m==0)
		{
			post(root->left,m);
			post(root->right,m);
			cout << root->data;
			p++;
			if(p < N)
				cout << ' ';
		}
		else
		{
			post(root->right,m);
			post(root->left,m);
			cout << root->data;
			p++;
			if(p < N)
				cout << ' ';
		}
	}
}
int main()
{
	cin >> N;
	node * root = NULL;	
	for(int i = 0; i < N;i++)
	{
		int t; scanf("%d",&t);
		input.push_back(t);
		root = insert(root,t);
	}
	preorder(root,0);
	if(pre==input)
	{
		cout << "YES"<<endl;
		post(root,0);
		return 0;
	}
	else
	{
		pre.clear(); preorder(root,1);
		if(pre==input)
		{
			cout << "YES" << endl;
			post(root,1);
			return 0;
		}
	}
	cout << "NO";
}
