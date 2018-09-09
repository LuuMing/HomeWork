#include<iostream>
#include<set>
using namespace std;
int dist[201][201];
int N, M,K;
set<int> S;
int main()
{
	int min_dist = 9999;
	int num;
	cin >> N >> M;
	for(int i = 0; i < M;i ++)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		dist[u][v] = w; dist[v][u] = w;
	}
	cin >> K;
	for(int i = 0; i< K;i ++)
	{
		S.clear();
		int k; 
		int start,s;
		scanf("%d",&k);
		scanf("%d",&start);
		s = start;
		S.insert(s);
		int total_dist = 0;
		bool flag = true;
		bool simple = true;
		for(int j = 1; j < k; j++)
		{
			int v; scanf("%d",&v);
			if( dist[s][v] == 0 )
			{
				flag = false;
			}
			else
			{
				if(S.count(v) && j != k-1)
				{
					simple = false;
				}
				S.insert(v);
				total_dist += dist[s][v];
				s = v;
			}
		}
		cout << "Path " <<i+1<<": ";
		if(flag)
		{
			cout << total_dist <<" (";
			if(s == start && S.size() == N)
			{
				if(total_dist < min_dist)
				{
					num = i+1;
					min_dist = total_dist;
				}
				if( simple)
				{
					cout << "TS simple cycle";
				}
				else
					cout << "TS cycle";
			}
			else
			{
				cout << "Not a TS cycle";
			}
			cout <<")";
		}
		else
		{
			cout << "NA" <<" (Not a TS cycle)";
		}
		cout << endl;
	}
	cout << "Shortest Dist("<<num<<") = "<<min_dist;
}