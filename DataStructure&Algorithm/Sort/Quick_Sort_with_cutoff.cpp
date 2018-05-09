T Median3(T A[],int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left ] > A[Center] )
		swap(&A[Left],&A[Center]);
	if (A[Left] > A[Right])
		swap(&A[Left],&A[Right]);
	/*A[Left] <= A[Center] <= A[Right]*/
	if(A[Center] > A[Right])
		swap(&A[Center],&A[Right-1]);
	return A[Right - 1];
}
void Quicksort(T A[],int Left,int Right)
{
	if(Cutoff <= Right - Left) {
	Pivot = Median3 ( A , Left, Right);
	i = Left; j = Right - 1;
	for()
	{
		while(A[++i] < Pivot) { }
		while(A[--j] > Pivot) { }
		if(i < j)
			swap(&A[i],&A[j]);
		else 
			break;
	}
	swap(&A[i],&A[Right - 1]);
	Quicksort(A,Left,i-1);
	Quicksort(A,i+1,Right);
	}
	else
		Insertion_Sort(A+Left,Right-Left+1);
}
void Quick_Sort(T A[],int N)
{
	Quicksort(A,0,N-1);
}
