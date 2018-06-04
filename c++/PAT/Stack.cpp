#include<iostream>
#include<stack>
#define MAX 100001
using namespace std;
stack<int> s;
int tree[MAX];
int read(int idx)
{
	int sum = 0;
	while(idx)
	{
		sum += tree[idx];
		idx -= idx & -idx;
	}	
	return sum;
}
void update(int idx,int k)
{
	while(idx <= MAX)
	{
		tree[idx] += k;
		idx += idx & -idx;
	}
}
int binary_search(int size)
{
	int left = 1;
	int right = MAX;
	while(left < right)
	{
		int mid = ( left + right ) / 2;
		int r = read(mid);
		if( r < size)
		{
			left = mid + 1;
		}
		else if ( r >= size)
		{
			right = mid;
		}

	}
	return left;
}
int main()
{
	int N;
	cin >> N;
	char q[15];
	for(int i = 0 ; i < N; i++)
	{
		scanf("%s",q);
		if(q[1] == 'o')
		{
			if(s.size() == 0)
			{
				printf("Invalid\n");
			}	
			else
			{
				int t = s.top();
				printf("%d\n",t);
				s.pop();
				update(t,-1);
			}
		}
		else if (q[1] == 'u')
		{
			int t; scanf("%d",&t);
			s.push(t);
			update(t,1);
		}	
		else
		{
			if(s.size() == 0){
				printf("Invalid\n");
				continue;
			}
			int k;
			k = binary_search( (s.size()+1)/2 );
	
			printf("%d\n",k);
		}				
		
	}
}
