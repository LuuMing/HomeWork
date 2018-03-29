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
BinTree Delete(BinTree BST, ElementType X)
{
	Position temp; 
	if(!BST)
	{
		printf("Not Found\n");
	}	
	else if( BST->Data > X)
	{
		BST->Left = Delete(BST->Left,X);
	}
	else if(BST->Data < X)
	{
		BST->Right = Delete(BST->Right,X);
	}
	else
	{
		if( BST->Left && BST->Right )
		{
			temp = FindMin(BST->Right);
			BST->Data =  temp ->Data;
			BST->Right = Delete(BST->Right,BST->Data);
			 	
		}
		else
		{
			temp = BST;
			if(!BST->Left)
			{
				BST = BST->Right;
			}
			else 
			{
				BST = BST ->Left;
			}
			free(temp);
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
