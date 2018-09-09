#include<iostream>
#include<set>
using namespace std;
int M,N;
int in[10001];
int pre[10001];
set<int> s;
int main()
{
	cin >> M >> N;
	for(int i = 0; i < N;i++)
	{
		scanf("%d",in+i);
		s.insert(in[i]);
	}	
	for(int i = 0; i < N;i++)
	{
		scanf("%d",pre+i);
	}
	for(int i = 0; i < M;i ++)
	{
		set<int> tmp;
		int u,v; scanf("%d%d",&u,&v);
		if(!s.count(u) && !s.count(v))
		{
			printf("ERROR: %d and %d are not found.",u,v);
		}
		else if(!s.count(u))
		{
			printf("ERROR: %d is not found.",u);
		}
		else if(!s.count(v))
		{
			printf("ERROR: %d is not found.",v);
		}
		else
		{
			int s = 0;
			for(s = 0; in[s] != u && in[s] != v && s < N; s++);
			s +=1;
			for( ;in[s] != u && in[s] != v&& s < N; s++)
				tmp.insert(in[s]);
				tmp.insert(u);
				tmp.insert(v);
//			for(set<int>::iterator kk = tmp.begin(); kk != tmp.end(); kk++)
//				cout << *kk <<' ';
//				cout << endl;
			int LCA;
			for(int k = 0; k < N ; k++)
			{
				if(tmp.count(pre[k]))
				{
					LCA = pre[k];
					break;
				}
			}
			
			if(LCA == u)
			{
				printf("%d is an ancestor of %d.",u,v);
			}
			else if(LCA == v)
			{
				printf("%d is an ancestor of %d.",v,u);
			}
			else
			{
				printf("LCA of %d and %d is %d.",u,v,LCA);
			}
		}
		if( i != M - 1)
		cout << endl;
	}
}