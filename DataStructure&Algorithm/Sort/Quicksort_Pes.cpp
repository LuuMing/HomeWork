void QuickSort(T A[],int N)
{
	if (N < 2) return;
	pivot = 从A[]中选一个主元;
	将 S = {A[] \ pivot} 分成2个独立子集;
		A1 = {a∈ S | a <= pivot}
		A2 = {a∈ S | a >= pivot};
	A[] = Quicksort(A1,N1) ∪  { pivot } ∪  Quicksort(A2,N2);
}
