#include<stdio.h> 
#include<iostream>
using namespace std;
typedef struct loopNode
{
	int password, num;
	struct loopNode * nextNode;
} loopNode;

loopNode * creatNode( int m ) //建立链表 
{
	loopNode * head, * p, *s;  
	head = new loopNode;
	p = head;
	for( int i=0; i<m ; i++ )
	{
		s = new loopNode;
		scanf( "%d,%d", &s-> num, &s-> password);
		p-> nextNode = s;
		p = s;
	}
	p-> nextNode = head-> nextNode;
	return head;
}

void outList(loopNode * p )//输出链表 
{
	loopNode * head = p;
	p = p-> nextNode;
	do
	{
		cout<< p->num <<","<< p->password <<"->";
		p = p-> nextNode;
	}
	while( p != head-> nextNode );
	cout << "循回到第一个节点!" << endl; 
}

void outQuee( loopNode *q, int m ) //输出队列 
{
	loopNode *p = q-> nextNode;
	while( p-> nextNode != p )
	{
		for( int i = 0 ;i < m-1 ; i++ )
		{
			p = p-> nextNode ;
			q = q-> nextNode ;
		}
		cout << p-> num << ',' ;
		m = p-> password ;
		q-> nextNode = p-> nextNode ;
		p = p-> nextNode ;
	}
	cout << p-> num <<endl;	
}
int main()
{
	int m = 0;
	cout << endl << "请输入参加人数:" ;
	cin >> m; 
	cout << endl;
	cout << "首先，建立约瑟夫环，它采用单循环链表存储结构：" << endl; 
	loopNode * p = creatNode( m );
	cout << "约瑟夫环为:" << endl;
	outList( p );
	cout << "请输入起始报数值:"; 
	cin >> m;
	cout << endl;
	cout << "则本轮出环序列是:";
	outQuee( p , m);
}
