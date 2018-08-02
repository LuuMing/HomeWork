#include<iostream>
#include<vector>
using namespace std;
#define MAX 10001
vector<int>degree;
vector<int> v[MAX];
int main()
{
	int N , M;
	cin >> N >> M;
	degree.resize(N+1,0);
	for(int i = 0; i < M;i++)
	{
		int U,V; scanf("%d%d",&U,&V);
		v[U].push_back(V);
		v[V].push_back(U);
		degree[U]++;
		degree[V]++;
	}
	int K; cin >> K;
	for(int i = 0; i < K;i++)
	{
		int t; scanf("%d",&t);
		vector<int> t_degree = degree;
		for(int j = 0; j < t;j++)
		{
			int vertex; scanf("%d",&vertex);
			t_degree[vertex] = 0;
			for(auto a:v[vertex])
			{
				if(t_degree[a] >0 )
				t_degree[a] --;
			}
		}
		bool flag = true;
		for(int i = 0; i < t_degree.size();i++)
		{
			if(t_degree[i] != 0)
				flag =false;
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
