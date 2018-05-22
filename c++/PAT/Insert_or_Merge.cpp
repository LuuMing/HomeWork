#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int num[110];
int result[110];
int tmp[110];
int is_insert()
{
	int p = 0;
	scanf("%d",&result[0]);
	bool flag = false;
	for(int i = 1; i < N; i++)
	{
		scanf("%d",&result[i]);
		if(result[i] > result[i-1]&&!flag)
			p = i;
		else
			flag = true;
	}
	for(int i = p + 1;i < N; i++)
	{
		if(result[i]!= num[i])
			return -1;
	}
	return p;
}
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		scanf("%d",&num[i]);
	}
	int p = is_insert();
	if( p != -1)    //p is the last position of ordered sequence
	{
		cout << "Insertion Sort" <<p<<endl<< endl;
		/*one more step for insertion sort*/
	/*	if(p!=N-1)
		{
			int i,t = result[p+1];
			for(i = p+1; i > 0 && result[i-1] > t;i--)
			{
				result[i] = result[i-1];
			}
			result[i] = t;
		}
	*/
		sort(result,result+p+2);
	}
	else
	{
		cout << "Merge Sort" << endl;
		int l;     // l is the the length of ordered subsequence
		for( l = 2; l <= N; l *= 2)
		{
			bool flag= false;
			for(int i = l; i < N; i+= 2*l)
			{
				if(result[i] <result[i-1])				
				{
					flag = true;
					break;
				}
			}
			if(flag)  break;
		}
		/*one more step for merge sort*/
		int left_min,right_max,right_min,left_max,next;
		for(left_min = 0; left_min < N-l; left_min = right_max)
		{
			right_min = left_max = left_min + l;
			right_max = left_max + l;
			if(right_max > N)
				right_max = N;
			next = 0;
			while(left_min < left_max && right_min < right_max )
				tmp[next++] = result[left_min] > result[right_min]?
				result[right_min++]:result[left_min++];
			while(left_min < left_max)
			result[--right_min] = result[--left_max];
			while(next > 0)
			result[--right_min] = tmp[--next];
		}
	}
	for(int i = 0; i < N;i++)
	{
		cout << result[i];
		if(i != N-1)
			cout <<' ';
	}
}

