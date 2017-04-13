#include "stdio.h"
#include "stdlib.h"

typedef struct btnode//二叉树结点存储结构定义
{char data;
 struct btnode *left,*right;
}btnode;

void CreateBiTree(btnode* &T)//按照先序序列建立二叉树
{
char ch;
scanf("%c",&ch);       //读入一个字符   
if(ch=='#') T=NULL;
else 
{
  T=(btnode*)malloc(sizeof(btnode)); //生成一个新结点
  T->data=ch;
  CreateBiTree( T->left );  //生成左子树
  CreateBiTree( T->right  );;  //生成右子树
}
}

void  preorder(btnode *b)   //先序遍历
{if(b)
{printf("%c", b->data) ; //"访问结点"
 preorder(b->left); //递归遍历左子树
 preorder(b->right); //递归遍历右子树
}
}

void  inorder(btnode *b)   //中序遍历
{if(b)
{	inorder( b->left ); //递归遍历左子树
	printf("%c", b->data);//访问节点 
    inorder( b->right );; //递归遍历右子树
}
}
void  lastorder(btnode *b)   //后序遍历
{if(b)
{lastorder(b->left); //递归遍历左子树
 lastorder(b->right); //递归遍历右子树
 printf("%c", b->data) ; //"访问结点"
}
}

int depth(btnode *b)//求二叉树的深度
{int depthl,depthr;
 if( b->left == NULL && b->right == NULL) return 0;
 else
{ depthl = depth( b->left );
  depthr = depth( b->right );
 if(depthl>depthr) return(depthl+1);
 else 
 return(depthr+1);
}
}

int node_counter(btnode *b)//求二叉树的总结点数
{int cl,cr;
 if(!b) return 0;
 else if(b->left ==NULL && b->right == NULL)
 {
 	return 1;
 }
else {
 cl=node_counter(b->left);
 cr=node_counter(b->right);
 return( 1+cl + cr );
}
}

int leaf_counter(btnode *b)//求二叉树的叶结点数
{int cl,cr;
 if(!b) return 0;
 else
 if( b->left == NULL && b->right == NULL )  return 1;
 else
{cl=leaf_counter(b->left);
 cr=leaf_counter(b->right);
 return( cl+cr );
}
}

void outputbt(btnode *b)//输出二叉树的嵌套括号表示
{
if(b)
{ printf("%c",b->data);
  if( b->left != NULL || b->right != NULL )
  {
  printf("(");
  outputbt( b->left );
  if( b->right != NULL) printf(",");
  outputbt( b->right );
  printf(")");
  }
}
}
int main()
{btnode *btree; int t;

printf("请输入二叉树的先序序列，如：ab##c##，回车结束，建立二叉树：");
 CreateBiTree(btree);//建立二叉树，输入待建二叉树的先序序列，如：ab##c##
 printf("\n二叉树的嵌套括号表示:");
 
 outputbt(btree);
printf("\n三种遍历序列分别是:");
 printf("\n先序:");
 preorder(btree);
 printf("\n中序:");
 inorder(btree);
 printf("\n后序:");
 lastorder(btree);
 t=depth(btree);//求二叉树深度
 printf("\n二叉树深度是：%d",t);
 t=node_counter(btree);//求二叉树结点数
 printf("\n二叉树总结点数是：%d",t);
 t=leaf_counter(btree);//求二叉树叶结点数
 printf("\n二叉树叶结点数是：%d",t);

}

