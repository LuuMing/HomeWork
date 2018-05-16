template<class T>
void get_topN(T A[], int low, int high, int topn)
{
	if( low >= high || topn > high) return ;
	int i = low, j = high, tmp = A[i];
	while( i < j)
	{
		while(i < j && A[j] < tmp ) j--;
		if( i < j ) A[i++] = A[j];
		while(i < j && A[i] >= tmp) i++;
		if( i < j ) A[j--] = A[i];
	}
	A[i] = tmp;
	int n = i - low + 1;
	if( n == topn)  return;
	else if ( n > topn )
		get_topN(A,low, i-1 , topn);
	else if ( n < topn )
		get_topN(A,i+1, high, topn - n);
}
