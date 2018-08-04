#include<iostream>
#include<vector>
using namespace std;
struct node
{
	node * left = NULL;
	node * right = NULL;
	int data;
	int color = 1;
};
bool is = true;
vector<int> result;
void count(node * root,int number)
{
	if(!root)
	{
		result.push_back(number);
		return;
	}
	if(root->color == 1)
	{
		count(root->left,number+1);
		count(root->right,number+1);
	}
	else
	{
		count(root->left,number);
		count(root->right,number);
	}
}
void judge(node * root)
{
	if(!is)     		//if already not an RBT, return
		return;
	if(root)
	{
		if(root -> color == -1) // If node is red, judge its child's color
		{
			if(root -> left)
			{
				if( root -> left -> color ==  -1)
				{	
					is = false; return;
				}
			}
			if( root -> right)
			{
				if( root -> right ->color == -1) 
				{
					is = false; return;
				}
			}
		}
		result.clear();  //then ,counting the number of black children
		count(root,0);
		int number_black;
		if(result.size() > 0)
		{
			number_black = result[0];
		}
		for(auto i:result)
		{
			if(i != number_black)
				is =false;
		}
		judge(root->left);  //judge its left child
		judge(root -> right); // judge its right child
	}
}
node * insert(node * root, int data)
{
	if(!root)
	{
		root  = new node;
		if(data > 0)
		{
			root -> data = data;		
			root -> color = 1;
		}
		else
		{
			root -> data = -data;
			root -> color = -1;
		}
	}
	else
	{
		if( root-> data < abs(data))
		{
			root->right = insert(root->right, data);
		}
		else
		{
			root->left = insert( root -> left, data);
		}
	}
	return root;
}

int main()
{
	int K; cin >> K;
	for(int i = 0; i < K; i++)
	{
		node * root = NULL;
		int N; scanf("%d",&N);
		for(int j = 0; j < N;j ++)
		{
			int data; scanf("%d",&data);
			root = insert(root,data);
		}
		if( root -> color == -1)
		{
			cout << "No"<< endl;
			continue;
		}
		judge(root);
		if(is)
			cout << "Yes";
		else
			cout << "No";
		is = true;
		cout << endl;
	}
}
