/*
	Original Shell Sort
feature: Dm = N/2, Dk = Dk+1 / 2. D is changeable.
complexity:θ(N2)	

*/
void Shell_Sort(T A[], int N)
{
	for(int D = N/2; D > 0; D/= 2) /*希尔增量序列*/
	{
		for(int  P = D; P < N; P++) /*插入排序*/
		{
			A Tmp = A[P];
			for(int i = P; i >= D && A[i-D] > Tmp; i-= D)
			{
				A[i] = A[i-D];
			}
			A[i] = Tmp;
		}
	}
}
/*
	Sedgewick-Shell Sort
*/
void ShellSort( ElementType A[], int N )
{ /* 希尔排序 - 用Sedgewick增量序列 */
     int Si, D, P, i;
     ElementType Tmp;
     /* 这里只列出一小部分增量 */
     int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
      
     for ( Si=0; Sedgewick[Si]>=N; Si++ ) 
         ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */
 
     for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] )
         for ( P=D; P<N; P++ ) { /* 插入排序*/
             Tmp = A[P];
             for ( i=P; i>=D && A[i-D]>Tmp; i-=D )
                 A[i] = A[i-D];
             A[i] = Tmp;
         }
}
