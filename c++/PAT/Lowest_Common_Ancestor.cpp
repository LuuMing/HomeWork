#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
	int data;
	node * left = NULL;
	node * right = NULL;
};
node * insert(node * root,int elem)
{
	if(!root)
	{
		root = new node;
		root -> data = elem;
	}
	else
	{
		if( elem > root -> data)
			root -> right = insert(root -> right, elem);
		else
			root -> left = insert(root -> left, elem);
	}
	return root;
}
int M;
int N;
int find_e1;
int find_e2;
int min_total = 99999;
int result_e1 = -1;
int result_e2 = -1;
node * result;
int find(node * root, int elem)
{
	int cnt = 0;
	bool find = true;
	while(root)
	{
		if(root -> data == elem)
		{
			find = false;
			break;
		}
		else if (root -> data < elem)
		{
			root = root-> right;
		}
		else
			root = root -> left;
		cnt ++;
	}
	if(find)
		return -1;
	else
		return cnt;
}
void t(node * root,int elem1, int elem2)
{
	if(root)
	{
		if( root -> left)
			t(root->left,elem1,elem2);
		if(root-> right)
			t(root->right,elem1,elem2);
		find_e1 = find(root, elem1);
		find_e2 = find(root, elem2);
		if(find_e1 != -1 && find_e2 != -1 && find_e1 + find_e2 < min_total)
		{
			min_total = find_e1 + find_e2;
			result_e1 = find_e1;
			result_e2 = find_e2;	
			result = root;
		}
	}
}
int main()
{
	node * root = NULL;
	scanf("%d%d",&M,&N);
	for(int i = 0; i < N; i++)
	{
		int t; scanf("%d",&t);
		root = insert(root,t);
	}
	for(int i = 0; i < M;i++)
	{
		int elem1, elem2;
		scanf("%d%d",&elem1,&elem2);
		result_e1 = -1;
		result_e2 = -1;
		min_total = 99999;
		int f1 = find(root,elem1);
		int f2 = find(root,elem2);
		if(f1 == -1 && f2 == -1)
		{
			printf("ERROR: %d and %d are not found.",elem1,elem2);
		}
		else if (f1 == -1)	
		{
			printf("ERROR: %d is not found.",elem1);
		}
		else if (f2 == -1)
		{
                        printf("ERROR: %d is not found.",elem2);
		}
		else
		{
			t(root,elem1,elem2);
			if(result_e1 == 0)
			{
				printf("%d is an ancestor of %d.",elem1,elem2);
			}
			else if (result_e2 == 0)
			{
				printf("%d is an ancestor of %d.",elem2,elem2);
			}
			else
				printf("LCA of %d and %d is %d.",elem1,elem2,result->data);
		}
		if(i != M-1)
			printf("\n");
	}
}
