/*
	Selection Sort
θ(N2)
*/

void Selection_Sort(T A[], int N)
{
	for(int i = 0; i < N; i++)
	{
		MinPosition = ScanForMin(A,i,N-1);
		/*从 A[i]到 A[N-1]中找最小元，位置赋给MinPostion*/
		swap(A[i],A[MinPosition]);
	}
}
