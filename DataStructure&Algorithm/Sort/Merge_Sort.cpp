void Merge(T A[], T TmpA [], int L,int R,int RightEnd)
{
	LeftEnd = R-1;
	Tmp = L;
	NumElements = RightEnd - L + 1;
	while( L <= LeftEnd && R <= RightEnd)
	{
		if(A[L] < A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	while(L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while(R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	for(i = 0; i < NumElements;i++,RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}
void MSort(T A[], T TmpA[],int L, int RightEnd)
{
	int Center;
	if(L < RightEnd)
	{
		Center = (L + RightEnd) / 2;
		MSort(A, TmpA, L, Center);
		MSort(A,TmpA,Center + 1, RightEnd);
		Merge(A,TmpA,L ,Center+1,RightEnd);
	}	
}
void Merge_Sort(T A[], int N)
{
	T * TmpA;
	TmpA = malloc(N* sizeof(T));
	if( TmpA != NULL)
	{
		MSort(A,TmpA,0,N-1);
		free(TmpA);
	}	
	else Error("Space error");
}
