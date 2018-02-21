#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
stringstream ss;
struct node
{
	string data;
	int left = -1,right = -1;
	bool root = true;
};
vector<node> nodes;
void output(int root)                //Binary tree, In order
{
	if(nodes[root].left!= -1 && nodes[root].right!=-1 )  //have two child
	{
		ss << '(';
		output(nodes[root].left);
		ss << nodes[root].data;
		output(nodes[root].right);
		ss <<')';
	}
	else if(nodes[root].left != -1 && nodes[root].right == -1)   //have one child
	{
		ss << '(';
		output(nodes[root].left);
		ss << nodes[root].data;
		ss <<')';
	}else if(nodes[root].left == -1&&nodes[root].right !=-1)   //have one child
	{
		ss << '(';
		ss << nodes[root].data;
		output(nodes[root].right);
		ss <<')';
	}
	else                                                       //no child                                           
	{
		ss << nodes[root].data;
	}
}
int main()
{
	int N;
	int root;
	cin >> N;
	nodes.resize(N+1);
	for(int i = 1; i < N+1;i++)        //read,and mark the root
	{
		cin >> nodes[i].data;
		cin >>nodes[i].left >> nodes[i].right;
		if(nodes[i].left != -1)
		nodes[nodes[i].left].root = false;
		if(nodes[i].right!= -1)
		nodes[nodes[i].right].root = false;
	}
	for(int i = 1; i < N+1;i++)
	{
		if(nodes[i].root)
		{
			root = i;
		}
	}
	output(root);
	string s = ss.str();              //to erase the extra ()
	if(s[s.size()-1] == ')')
	s.erase(s.end()-1);
	if(s[0]=='(')
	s.erase(s.begin());
	cout << s;
}
