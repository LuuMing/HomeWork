#include<iostream>
#include<map>
using namespace std;
struct node
{
	node * left = NULL;
	node * right = NULL;
	int data;
};
node * insert(node * root,int data)
{
	if(!root)
	{
		root = new node;
		root-> data = data;
	}
	else
	{
		if( data > root->data)
			root -> right = insert(root->right,data);
		else
			root-> left = insert(root->left,data);
	}
	return root;
}
map<int,int> m;
void t(node * root,int l)
{
	if(root)
	{
		t(root->left,l+1);
		t(root->right,l+1);
		m[l]++;
	}
	
}
int main()
{
	int N; cin >> N; node * root = NULL;
	for(int i = 0; i < N; i++)
	{
		int t;
		scanf("%d",&t);
		root = insert(root,t);
	}
	t(root,1);
	if(m.size() ==1)
	{
		cout << "1 + 0 = 1";
		return 0;
	}
	auto it = m.rbegin();
	int data1 = it->second;
	int data2 = (++it)->second;
	cout << data1 <<" + "<<data2 <<" = "<<data1+data2;
}
