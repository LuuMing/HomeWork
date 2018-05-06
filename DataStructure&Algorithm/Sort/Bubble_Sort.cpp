/*
	Bubble Srot
feature: Good for list
best: O(N)
worst: O(N2)
*/
template <T>
void Bubble_Sort(T A[],int x)
{
	for(int P = N - 1; P >= 0; P--)
	{
		int flag = 0;
		for(int i = 0; i < P; i++)
		{
			if(A[i] > A[i+1])
			{
				swap(A[i],A[i+1]);
				flag = 1;
			}
		}
		if(!flag)
			break;
	}
}

