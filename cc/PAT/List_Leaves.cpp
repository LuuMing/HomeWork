#include<iostream>
using namespace std;
#define MAX 12
struct node
{
	int index;
	int left = -1;
	int right = -1;
	bool root = true;
	bool leaf = false;
};
node temp[MAX];
node result[2*MAX+2];
void build(int root,int index)
{
	if(root != -1)
	{
		result[index] = temp[root];
	}
	if(temp[root].left != -1)
	{
		build(temp[root].left,2*index);
	}
	if(temp[root].right != -1)
	{
		build(temp[root].right,2*index+1);
	}
}
int main()
{
	int N;
	cin >> N;
	int num_leaves = 0;
	int root = -1;
	for(int i = 0; i < N; i++)
	{
		char l,r;
		cin >> l >> r;
		temp[i].index = i;
		if(l=='-'&&r=='-')
		{
			temp[i].leaf = true;
			num_leaves ++;
		}
		if(l != '-')
		{
			temp[i].left = l - '0';
			temp[temp[i].left].root = false;
		}
		if( r != '-')
		{
			temp[i].right = r - '0';
			temp[temp[i].right].root = false;
		}
	}
	for(int i = 0; i < N; i++)
	{
		if(temp[i].root)
		{
			root = i;
			break;
		}
	}
	build(root,1);
	for(int i = 1,count = 0; i <= 2*MAX+2 ; i++)
	{
		if(result[i].leaf)
		{
			if(count != num_leaves-1 )
			{
				cout  << result[i].index <<' ';
				count ++;
			}
			else
			{
				cout << result[i].index;
				break;
			}
		}
	}
}
