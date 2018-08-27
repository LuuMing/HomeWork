#include<iostream>
#include<unordered_set>
using namespace std;
#define MAX 
unordered_set<int> s;
int pre_order[10001];
int M,N;
int main()
{
	cin >> M >> N;
	for(int i = 0; i < N; i++)
	{
		scanf("%d",pre_order+i);
		s.insert(pre_order[i]);
	}
	for(int i = 0; i < M ;i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		if( !s.count(u) && !s.count(v))
		{
			printf("ERROR: %d and %d are not found.\n",u,v);
		}
		else if ( !s.count(u) || !s.count(v)) 
		{
			printf("ERROR: %d is not found.\n",s.count(u)?v:u);
		}
		else
		{
			for(int j = 0; j < N; j++)
			{
				if( u<=pre_order[j] && pre_order[j] <=v || v<=pre_order[j] && pre_order[j] <=u)
				{
					if( u == pre_order[j])
					{
						printf("%d is an ancestor of %d.\n",u,v);
					}
					else if ( v==pre_order[j])
					{
						printf("%d is an ancestor of %d.\n",v,u);
					}
					else
					{
						printf("LCA of %d and %d is %d.\n",u,v,pre_order[j]);
					}
					break;
				}
			}
		}
	}
	
}
