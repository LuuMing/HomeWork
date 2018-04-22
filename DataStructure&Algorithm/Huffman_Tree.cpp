#include<iostream>
#include<vector>
#include<queue>
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
int N;

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
int main()
{
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		char a;int b;
		cin >> a >> b;  //sample input: A 1 B 1 C 1 D 3 E 3 F 6 G 6
		nodes[i].weight = b;
	}
	node * huffman = Huffman();
	cout << huffman->weight;
}
