#include<iostream>
#include<vector>
using namespace std; 
vector<int> vv;
int M;
int N;
void output(int index,vector<int>v )
{
	if( index > N)
		return;
	output(2 * index,v) ;
	output(2 * index + 1,v);
	vv.push_back(v[index]);
}
int main()
{
	cin >>M >> N;
	for(int i = 0; i < M; i++)
	{
		vector<int> v(N + 1);
		for(int j = 1; j <= N; j++)
		{
			scanf("%d",&v[j]);
		}
		int greater = 0;
		int less = 0;
		bool heap = true;
		for(int j = 1; j <= N; j++)
		{
			
			if(2*j <= N )
			{
				if(v[j] >= v[2*j])
				{
					greater ++;			
				}
				else if ( v[j] < v[2*j] )
				{
					less ++;
				}
			}
			if(2 * j + 1 <= N)
			{
				if(v[j] >= v[2*j+1])
				{
					greater ++;			
				}
				else if ( v[j] < v[2*j+1] )
				{
					less ++;
				}
			}
		} 
	        if( greater >= 1 && less == 0)
		{
			printf("Max Heap");
		}
		else if (less >= 1  && greater == 0)
		{
			printf("Min Heap");
		}
		else
			printf("Not Heap");
		printf("\n");
		vv.clear();
		output(1,v);
		for(int k = 0; k < vv.size(); k++)
		{
			printf("%d",vv[k]);
			if( k != vv.size() - 1)
				printf(" ");
		}
		if( i != M - 1)
			printf("\n");
	}
}
