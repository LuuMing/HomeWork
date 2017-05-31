#include<iostream> 
using namespace std;
#define m0 100
/*
向量 
*/
typedef int vector[m0];
/*
堆栈 
*/
typedef struct SeqStack
{
	int top = 0;
	char data[m0];	
}SeqStack;
/*
队列 
*/
typedef struct SeqQueue
{
	char data[m0];
	int front = 0;
	int rear = 0;
}SeqQueue;
/*
链表 
*/
typedef struct Node
{
	struct Node * nextNode;
	char  data;	
}Node;
/*
双向链表 
*/
typedef struct dNode
{
	struct dNode * next;
	struct dNode * prior;
	char data;
}dNode;
/*
二叉树  数组存储 
*/
typedef char sqbtree[m0]; 
/*
二叉树  链式存储 
*/
typedef struct btNode
{
	char data;
	struct btNode * left;
	struct btNode * right;
}btNode; 
/*
图  
*/
typedef struct vexnode 
{
	char vexdata;
	char * otherinfo;
}vexnode;
/*
顶点向量
*/ 
typedef vexnode vex[m0];
/*
邻接矩阵
*/
typedef int adjmatrix[m0][m0];
/*
链接表 
*/



int main()
{

	vector a;
	SeqStack s;
	SeqQueue q;
	dNode d;
	cout<<s.top;
	cout<<q.front<<q.rear;
	static int x = 100;
	cout<<endl<<endl<<x;
}
