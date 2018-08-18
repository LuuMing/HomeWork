/***************************
	@author: LuMing
	@date:	18/8/18 12:49~ 13:05
		13:12~13:59
***************************/
#include<iostream>
#include<vector>
#define MAX 501
#define INF 99999
using namespace std;
int length[MAX][MAX];
int Time[MAX][MAX];
int pre_path[MAX];
int pre_time[MAX];	
int D[MAX];
int T[MAX];
int N;
int S, E;
vector<int> v1,v2;
void output_path(int u)
{
	if(u == pre_path[u])
	{
		v1.push_back(u);
		return;
	}
	else
	{
		v1.push_back(u);
		output_path(pre_path[u]);
	}
}
void output_time(int u)
{
	if(u == pre_path[u])
	{
		v2.push_back(u);
		return;
	}
	else
	{
		v2.push_back(u);
		output_time(pre_time[u]);
	}
}
void dijkstra(int v)
{
	int visit[MAX];	
	for(int i = 0; i < N;i++)
	{	
		visit[i] = 0;
		D[i] = length[v][i];
		T[i] = Time[v][i];
		pre_path[i] = i;
	}
	visit[v] = 1;
	for(int i = 0; i < N ;i++)
	{
		int num = -1;
		int dist = INF;
		for(int j = 0; j < N; j++)
		{
			if( D[j] < dist && !visit[j])
			{
				num = j;
				dist = D[j];
			}
		}
		if(num == -1)
			break;
		visit[num] = 1;
		for(int u = 0; u < N; u++)
		{
			if( D[num] + length[num][u]  <  D[u] && !visit[u])
			{
				pre_path[u] = num;
				D[u] = D[num] + length[num][u];
				T[u] = T[num] +Time[num][u];
			}
			else if (D[num] + length[num][u] == D[u] && !visit[u] && T[num] + Time[num][u] < T[u])
			{
				pre_path[u] = num;
				D[u] = D[num] + length[num][u];
				T[u] = T[num] + Time[num][u];
			}
		}
	}
	output_path(E);
	int DD = D[E];
//////////////////////////////////////
	for(int i = 0; i < N;i++)
	{	
		visit[i] = 0;
		D[i] = length[v][i];
		T[i] = Time[v][i];
		pre_time[i] = i;
	}
	visit[v] = 1;
	for(int i = 0; i < N ;i++)
	{
		int num = -1;
		int dist = INF;
		for(int j = 0; j < N; j++)
		{
			if( T[j] < dist && !visit[j])
			{
				num = j;
				dist = T[j];
			}
		}
		if(num == -1)
			break;
		visit[num] = 1;
		for(int u = 0; u < N; u++)
		{
			if( T[num] + Time[num][u]  <  T[u] && !visit[u])
			{
				pre_time[u] = num;
				D[u] = D[num] + length[num][u];
				T[u] = T[num] +Time[num][u];
			}
			else if (T[num] + Time[num][u] == T[u] && !visit[u] &&    D[num] + length[num][u] < D[u])
			{
				pre_time[u] = num;
				D[u] = D[num] + length[num][u];
				T[u] = T[num] + Time[num][u];
			}
		}
	}
	output_time(E);
	if(v1 == v2)
	{
			cout << "Distance = " << DD <<"; ";
	}
	else
	{
		cout << "Distance = " << DD <<": "<<S<<" -> ";
		for(int i = v1.size()-1; i >=0;i--)
		{	
			cout << v1[i];
			if(i!=0)
				cout << " -> ";
		}
		cout << endl;
	}
	cout << "Time = " << T[E] <<": "<<S<<" -> ";
	for(int i = v2.size()-1; i >=0;i--)
	{
		cout << v2[i];
		if(i!=0)
			cout << " -> ";
	}
	cout << endl;
}
int main()
{
	int M;cin >> N >> M;
	for(int i = 0; i < N ;i++)
	{
		for(int j = 0; j < N; j++)
		{
			length[i][j] = Time[i][j] = (i==j)?0:INF;
		}
	}
	for(int i = 0; i < M; i++)
	{
		int v1,v2,one_way,l,t;
		scanf("%d%d%d%d%d",&v1,&v2,&one_way,&l,&t);
		if(one_way)
		{
			length[v1][v2] = l;
			Time[v1][v2] = t;
		}
		else
		{
			length[v1][v2] = length[v2][v1] = l;
			Time[v1][v2] = Time[v2][v1] = t;
		}
	}
	cin >> S >> E;
	dijkstra(S);
	return 0;
}
