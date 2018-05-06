/*
	Insertion_Sort
feature:
best: O(N)
worst:O(N2)

*/
void Insertion_Sort(T A[], int N)
{
	for(int P = 1; P < N; P++)
	{
		T Tmp = A[P];		//摸牌
		for(int i = P; i > 0 && A[i-1] > Tmp; i--)
			A[i] = A[i-1];   //移出空位
	}
}
