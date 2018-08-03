#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long int p;
int N;
long int num[100001];
int binary_find(int left)
{
	long int m = num[left];
	int right = N;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(num[mid] < p * m)
		{
			left = mid+1 ;
		}
		else if (num[mid] > p * m)
		{
			right = mid;
		}
		else
		{
			return mid;
		}
	}
	return left - 1;
}
int main()
{
	int nums = 0;
	cin >> N >> p;
	for(int i = 0; i < N; i++)
	{
		scanf("%ld",&num[i]);	
	}
	sort(num,num+N);
	for(int i = 0; i < N;i++)
	{
		int j = binary_find(i);
		if( j - i + 1  > nums)	
			nums = j - i + 1;
	}
	cout << nums;

}
