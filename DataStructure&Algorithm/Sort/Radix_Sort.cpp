/*
	Radix Sort (LSD)
*/
#define MaxDigit 4
#define Radix 10
struct Node
{
	int key;
	Node * next;
};
struct HeadNode
{
	Node * head,tail;
};
HeadNode B[Radix];
int GetDigit(int x, int D)
{
	int d, i;
	for( i = 1; i <= D; i++)
	{
		d = X % Radix;
		X /= Radix;
	}
	return d;
}

void LSDRadixSort(T A[], int N)
{
	int D, Di, i;
	Node * tmp, p, List = NULL;
	for( i = 0; i < Radix; i++)  //init the bucket
	{
		B[i].head = B[i].tail = NULL;
	}
	for( i = 0; i < N; i++)    //insert the reverse order data 
	{
		tmp = (Node *) malloc(sizeof(struct Node));
		tmp -> key = A[i];
		tmp->next = List;
		List = tmp;
	}
	for(D = 1; D <= MaxDigit; D++) //for every digit
	{
		p = List;
		while(p)
		{
			Di = GetDigit(p->key, D); //get current digit
			tmp = p; p = p -> next;   //Delete from list
			tem -> next = NULL;
			if(B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else
			{
				B[Di].tail -> next = tmp;
				B[Di].tail = tmp;
			}
			
		}
		/* collect */
		List = NULL;
		for(Di = Radix - 1; Di >= 0; Di--)
		{
			if(B[Di].head)
			{
				B[Di].tail -> next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL; //clear the bucket
			}
		}
	}
	for( i = 0; i < N ;i++)
	{
		tmp = List;
		List = List -> next;
		A[i] = tmp -> key;
		free(tmp);
	}
}
