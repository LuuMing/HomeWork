BinTree Insert(BinTree BST, ElementType X)
{
	if(BST == NULL)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST ->Left = BST->Right = NULL;
	}
	else
	{
		if(X > BST->Data)
		{
			BST->Right = Insert(BST->Right,X);
		}
		else if (X < BST->Data)
		{
			BST->Left = Insert(BST->Left,X);
		}
	}
	return BST;
}
BinTree Delete(BinTree BST, ElementType X)//删除元素,返回根节点
{
	Position temp; 
	if(!BST)
	{
		printf("Not Found\n");
	}	
	else if( BST->Data > X)           //元素大于当前节点,递归删除左子树
	{
		BST->Left = Delete(BST->Left,X);
	}
	else if(BST->Data < X)
	{
		BST->Right = Delete(BST->Right,X);
	}
	else				 //当前节点为待删除节点
	{
		if( BST->Left && BST->Right ) //have two child
		{
			//temp = FindMin(BST->Right);      		 //find max of it's Left tree/ or find min of it's left tree as temp
			//BST->Data =  temp ->Data;	   		 //use temp to replace the root
			//BST->Right = Delete(BST->Right,BST->Data);	 //Delete Left / Right tree recursively
			 temp = FindMax(BST->Left);
			 BST->Data = temp -> Data;
			 BST -> Left = Delete(BST->Left,BST->Data);	 	
		}
		else                          //have one/no child, just replace it's root
		{
			//temp = BST;
			if(BST->Left)
			{
				BST = BST->Left;
			}
			else 
			{
				BST = BST ->Right;
			}
			//free(temp);
		}
	}
	return BST;

}

Position Find(BinTree BST, ElementType X)
{
	if(BST == NULL)
	{
		return NULL;
	}
	 if(X == BST-> Data)
	{
		return BST;
	}
	else if (X < BST->Data)
	{
		return Find(BST->Left,X);
	}
	else
	{
		return Find(BST->Right,X);	
	}
}
Position FindMin(BinTree BST)
{
	if(!BST) return NULL;
	else if ( !BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}

Position FindMax(BinTree BST)
{
	if(!BST) return NULL;
	else if ( !BST->Right)
		return BST;
	else
		return FindMax(BST->Right);
}
