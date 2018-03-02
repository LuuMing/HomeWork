#include<iostream>
#include<sstream>
using namespace std;
stringstream  ss;
struct node
{
	int num ;
	node*left = NULL;
	node* right = NULL;
};
int N;
int times = 0;
node * build()
{
	node * r = NULL;
	if(times < 2*N)	
	{
		string tem;
		cin >> tem;
		if(tem[1] == 'u')
		{
			r = new node;
			cin >> r -> num;
			times++;
		}
		else
		{
			times++;
			return NULL;
		}
	        r->left = build();
	        r->right =build();
	}
	return r;
}
void post(node * root)
{
	if(root -> left != NULL)
	{
		post(root ->left);
	}
	if(root -> right != NULL)
	{
		post(root -> right);
	}
	if(root != NULL)
	{
		ss << root->num << ' ';
	}
}
int main()
{
	cin >> N;
	node* r = build();
	post(r);
	string s = ss.str();
	s.erase(s.end()-1);
	cout << s;
}
