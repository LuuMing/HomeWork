#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#define MAX 64
using namespace std;
struct node
{
	int weight;
	node * left;
	node * right;

}nodes[MAX];
struct cmp
{
	bool operator()(node * a,node * b)
	{
		return a->weight > b -> weight;  // > : min_heap  <:max_heap
	}	
};
priority_queue<node*,vector<node*>,cmp> min_heap;
int N,M;
unordered_map<char,int> m;

node * Huffman()
{
	for(int i = 0; i < N;i++)
	{
		min_heap.push(&nodes[i]);
	}
	for(int i = 1; i < N;i++)    //N-1 times merge
	{
		node *T = new node;
		T -> left = min_heap.top();
		min_heap.pop();
		T -> right = min_heap.top();
		min_heap.pop();
		T->weight = T->left->weight + T->right->weight;
		min_heap.push(T);
	}
	return min_heap.top();
}
int WPL(node * T,int Depth)  //other method: WPL = sum of non-leaf node's weight
{
	if( !T->left && !T->right)
	{
		return Depth * T->weight;
	}
	else
	{
		return WPL(T->left,Depth+1) + WPL(T->right,Depth+1);
	}
}
bool hasprefix(vector<string> code)
{
	sort(code.begin(),code.end());
	for(int i = 0; i < code.size();i++)
	{
		string t = code[i];
		for(int j = i+1; j < code.size();j++)
		{
			if(code[j].substr(0,t.size()) == t)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		char a;int b;
		cin >> a >> b;  //sample input: A 1 B 1 C 1 D 3 E 3 F 6 G 6
		nodes[i].weight = b;
		m[a] = b;
	}
	node * huffman = Huffman();
	int wpl = WPL(huffman,0);
	cin >> M;
	for(int i = 0; i < M;i++)
	{
		int w = 0;
		vector<string> code;
		for(int j = 0; j < N;j++)
		{
			char c_t; string s_t;
			cin >> c_t >> s_t;
			w += s_t.size() * m[c_t];
			code.push_back(s_t);
		}
		if(!hasprefix(code) && w == wpl)	
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
	
}
