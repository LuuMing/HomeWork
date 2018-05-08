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
