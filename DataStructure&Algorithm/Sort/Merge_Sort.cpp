/*
	Merge Sort
O(NlogN)
stable
extra space: O(N)
feature: good for outer sort
*/
/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
     int LeftEnd, NumElements, Tmp;
     int i;
      
     LeftEnd = R - 1; /* 左边终点位置 */
     Tmp = L;         /* 有序序列的起始位置 */
     NumElements = RightEnd - L + 1;
      
     while( L <= LeftEnd && R <= RightEnd ) {
         if ( A[L] <= A[R] )
             TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
         else
             TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
     }
 
     while( L <= LeftEnd )
         TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
     while( R <= RightEnd )
         TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */
          
     for( i = 0; i < NumElements; i++, RightEnd -- )
         A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}
 
void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{ /* 核心递归排序函数 */ 
     int Center;
      
     if ( L < RightEnd ) {
          Center = (L+RightEnd) / 2;
          Msort( A, TmpA, L, Center );              /* 递归解决左边 */ 
          Msort( A, TmpA, Center+1, RightEnd );     /* 递归解决右边 */  
          Merge( A, TmpA, L, Center+1, RightEnd );  /* 合并两段有序序列 */ 
     }
}
 
void MergeSort( ElementType A[], int N )
{ /* 归并排序 */
     ElementType *TmpA;
     TmpA = (ElementType *)malloc(N*sizeof(ElementType));
      
     if ( TmpA != NULL ) {
          Msort( A, TmpA, 0, N-1 );
          free( TmpA );
     }
     else printf( "空间不足" );
}
/*******************************************/
/*non recursive*/
void Merge_pass(T A[],T TmpA[], int N, int length)
{
	for(i = 0; i <= N-2*length;i+= 2* length)
		Merge1(A,TmpA,i,i+length,i+2*length-1);
	if (i + length < N)
		Merge1(A,TmpA,i,i+length,N-1);
	else 
		for( j = i; j < N;j++)  TmpA[j] = A[j];
}
void Merge_sort(T A[],int N)
{
	int length = 1;
	T * TmpA;
	TmpA = malloc(N*sizeof(T));
	if(TmpA!= NULL)
	{
		while(length < N)
		{
			Merge_pass(A,TmpA,N,length);
			length *= 2;
			Merge_pass(TmpA,A,N,length);
			length *= 2;
		}
		free(TmpA);
	}
	else Error("Space Error");
}
