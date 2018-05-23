#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num[101];
int result[101];
int N;
int is_insert()
{
	int p = 0;
	cin >> result[0];
	bool flag = false;
	for(int i = 1 ; i < N;i++)
	{
		cin >> result[i];
		if(result[i] >= result[i-1] && !flag)
		{
			p = i;
		}
		else
		{
			flag = true;
		}
	}
	for(int i = p + 1; i < N;i++)
	{
		if(result[i] != num[i])
			return -1;
	}
	return p;
}
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	int p = is_insert();
	if(p != -1)
	{	
		cout << "Insertion Sort" << endl;
		sort(result,result+p+2);
	}
	else
	{
		cout << "Heap Sort"<<endl;
		int unsort_p = N - 1;
		while(unsort_p-- >=0)
		{
			bool flag = false;
			for(int i = unsort_p-1; i >= 0;i--)
			{
				if(result[i] > result[unsort_p])
				{
					flag = true; break;
				}
			}
			if( flag ) break;
		}
		make_heap(result,result+unsort_p+1);
		swap(result[0],result[unsort_p]);
		make_heap(result,result+unsort_p);
	}
	for(int i = 0; i < N;i++)
	{
		cout << result[i];
		if(i!=N-1)
			cout << ' ';
	}
}
