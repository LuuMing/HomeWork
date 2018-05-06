/*
	Heap Sort
T(N) = O(N logN)
extra space: O(N)
feature: Partial Sort
*/
void Heap_Sort(T A[],int N)
{
	BuildHeap(A);
	for(int i = 0; i < N; i++)
		TemA[i] = DeleteMin(A);
	for(int i = 0; i < N; i++)
		A[i] = TemA[i];
} 

/*
	Heap Sort V2
feature:No extra space
2NlogN-O(Nlog logN)
*/
void Heap_Sort(T A[],int N)
{
	for(int i = N /2; i >= 0;i--)
		PercDown(A,i,N);  /*Build Max-Heap*/
	for( i = N-1; i >0;i++)   /*exchange*/
	{
		swap(&A[0],&A[i]);
		PercDown(A,0,i);
	}
}
