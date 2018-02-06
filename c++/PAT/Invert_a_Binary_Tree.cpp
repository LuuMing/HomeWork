#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
int N;
struct node
{
	string num;
	string left ;
	string right;
	bool root = true;
};
map<string,node*> str2addr;
void level_order(string root)
{
	int i = 0;
	queue<string> q;
	q.push(root);
	while( i < N )
	{
		if( str2addr.at(q.front())->right!="-" )
		{
			q.push(str2addr.at(q.front())->right);		
		}
		if( str2addr.at(q.front())->left!="-" )
		{
			q.push(str2addr.at(q.front())->left);		
		}
		if( i == N-1)
		{
			cout << str2addr.at(q.front())->num;
			q.pop();
		}
		else
		{
			cout << str2addr.at(q.front())->num<<' ';
			q.pop();
		}
		i++;
	}
	cout << endl;
}
int times = 0;
void in_order(string root)
{
	if(str2addr.at(root) != NULL)	
	{
		if(str2addr.at(root)->right != "-")
		{
			in_order(str2addr.at(root)->right);
		}

		if(times == N-1)
		{
			cout << str2addr.at(root)->num;
		}
		else
		{
			cout<< str2addr.at(root)->num<<' ';
		}	
		times++;
		if(str2addr.at(root)->left != "-")
		{
			in_order(str2addr.at(root)->left);
		}
	}
}


int main()
{
	int root;
	scanf("%d",&N);
	node* Nodes = new node[N];
	for(int i = 0; i < N; i++)
	{
		Nodes[i].num =to_string(i);
		cin >> Nodes[i].left;
		cin >> Nodes[i].right;
		str2addr.insert(pair<string,node*>(to_string(i),&Nodes[i]));
	}
	str2addr.insert(pair<string,node*>("-1",NULL));
	for(int i = 0; i < N; i++)		//mark root
	{
		if(Nodes[i].left != "-")
			str2addr.at(Nodes[i].left)->root = false;
		if(Nodes[i].right != "-")
			str2addr.at(Nodes[i].right)->root = false;
	}
	for(int i = 0; i< N; i++)               //find root
	{
		if(Nodes[i].root)
		{
			root = i;                 		
		}	
	}
	level_order(to_string(root));	
	in_order(to_string(root));

//	for(int i = 0; i < N;i++)
//	{
//		cout<<Nodes[i].root<<' ';
//	}
	return 0;
}





