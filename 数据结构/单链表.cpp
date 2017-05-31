#include "stdio.h"
#include "stdlib.h"
typedef  struct  node//定义链表结点存储结构
{  int  data;/*数据域*/
   struct  node  *next;//指针域，建立起数据元素之间的线性
//关系
}node;

void outlist(node *p)//显示链表函数
{while(p!=NULL)
 {printf("%d->",p->data);
  p=p->next;
}
 printf("null\n");
}




//建立单链表
node *  CreatList( ) //输入一系列整数,以0标志结束,将这些整数作为data域建立一个单链表
{node  *head, *p, *s;
 int x,cycle=1; 
 head=(node *)malloc(sizeof(node)); 
 p=head;
 while(cycle)
 {scanf("%d",&x);
  if(x!=0)
  {s=(node *)malloc(sizeof(node));
   s->data=x;
   p->next=s;
   p=s;
  }
  else  cycle=0;
 }
p->next=NULL;/*建立单循环链表时则：p->next=head；*/
printf("单链表建立好：");
outlist(head->next);
return  head;
} 

int  FindList(node * head, int x)// 在单链表中查找值为x的结点
{node *p;
 p=head->next;//跳过头结点
 	while( (p !=NULL)&&(p->data !=x) ) 
 	{
  				(p=p->next  );
    }
 if(p!=NULL)
  { printf("结点找到了!\n"); return 1;}
 else
 {printf("结点未找到!\n"); return 0;}
}

void InsertList(node * &head, int i, int x)// 在单链表中第i个结点之后插入值为x的结点
{node *s, *p;
 int j;
 s=(node * ) malloc(sizeof(node));/*建立待插入结点*/
 s->data=x;
 p=head; j=0; 
  while( j!=i && p!=NULL )
  {j++; 
  p=p->next ;
  } /*p、j保持同步*/
  if(p!=NULL)
  {
	s->next =p->next ;
	p->next =s;
  }
 else
 printf("插入位置不正确!\n");
 }

void DeleteList (node * &head, int x)//在单链表中删除值为x的结点
{node *p, *q; /*删除操作时,设立一个指针q指向当前结点的前驱结点*/
 q=head;p=head->next; 
 while(p!=NULL && p->data!=x)
 {
	q=q->next ;
 	p=p->next ; 
 } /*q始终是p的前驱*/
 if(p!=NULL) /*找到结点,进行删除操作*/
 { 
	q->next =p->next ;
   free(p);
 }
 else
 printf("链表中无该结点!\n");
}

int LengthList(node * head)//求单链表的长度
{int n=0;
 node *p;
 p=head->next;
 while(p!=NULL)
 {
	p=p->next ;
  	n++;
 }
return n;
}

int main()
{node * list;int n,i,x,len;
 printf("1---请输入元素建立单链表，以输入0表示结束:\n");
 list=CreatList( );//建立单链表
 printf("2---请输入要查找的元素：");
 scanf("%d",&x);
 n=FindList(list, x);//查找值为x的元素
 printf("3---在单链表中第i个结点之后插入值为x的结点，请输入i和x的值：");
 scanf("%d%d",&i,&x);
 InsertList(list, i, x);// 在单链表中第i个结点之后插入值为x的结点
 outlist(list->next );
 printf("4---删除单链表中值为x的结点，请输入x的值：");
 scanf("%d",&x);
 DeleteList (list,x);//在单链表中删除值为x的结点
 outlist(list->next );
 len=LengthList(list);//求单链表长度
 printf("5---单链表的长度为%d:",len);
 
}

