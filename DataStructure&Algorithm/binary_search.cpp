/*
	不大于某数的最后一个元素
*/
void binsearch(vector<int> A, int target)
{
	int lo = 0, hi = A.size();
	while(lo < hi - 1)
	{
		int mid = (lo + hi) / 2;
		if(A[mid] >= target)
			lo = mid;
		else
			hi = mi;
	}
	return lo;
}
