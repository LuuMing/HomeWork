#include<iostream>
#include<stdio.h>
#define m0 100
using namespace std;
typedef struct seqQueue
{
	char data[m0];
	int front,rear;
}seqQueue;

seqQueue* initSeqQueue()
{
	seqQueue *p;       //
	p=new seqQueue;
	p->front =0;
	p->rear =0;
	return p;
}

int emptySeqQueue(seqQueue *s)
{
	if(s->front ==s->rear )
	{
		return 1;
	}
	else 
		return 0;
}

int inSeqQueue(seqQueue *s,char x)
{
	if(s->rear -s->front >m0)
	{
		cout<<"队满不能入队"; 
		return 0;
	}
	else 
	{
		s->data [s->rear]=x;
		s->rear++;
	}
//	while(s->front !=0)
//	{
//		for(int i=s->front ;i<=s->rear;i++)
//		{
//			s->data[s->front-1]=s->data[s->front ];
//		}
//		s->front --;
//		s->rear --;
//	}	//元素前移，节省空间 ，请忽略 
	
}
int outSeqQueue (seqQueue *s, char &x)
{
	if(emptySeqQueue(s))
	{
		printf("队空不能出队！\n");
		return 0;
	}
	else 
	{
		x=s->data [s->front];
		s->data [s->front++];
		return 1;
	}
}

char frontSeqQueue(seqQueue *s)
{
	if(emptySeqQueue(s))
	return 0;
	else 
	return (s->data [s->front]);
}	//查看堆头元素 

char rearSeqQueue(seqQueue *s)
{
	if(emptySeqQueue(s))
	return 0;
	else 
	return (s->data [(s->rear)-1]);
}	//查看队尾元素 
int main()
{
	seqQueue *p=initSeqQueue();//初始化一个队列 
	inSeqQueue(p,'l');//入队列 l 
	inSeqQueue(p,'o');//入队列 o
	inSeqQueue(p,'v');//入队列 v
	inSeqQueue(p,'e');//入队列 e
	
	cout<<"队头元素是："<<frontSeqQueue(p)<<endl<<"队尾元素是"<<rearSeqQueue(p)<<endl;
	char x;
	cout<<"出队列:"<<endl;
	outSeqQueue(p,x);
	cout<<x<<endl;
	outSeqQueue(p,x);
	cout<<x<<endl;
	outSeqQueue(p,x);
	cout<<x<<endl;
	outSeqQueue(p,x);
	cout<<x<<endl;
	
	outSeqQueue(p,x);//当队列为空时，出队列 
}



