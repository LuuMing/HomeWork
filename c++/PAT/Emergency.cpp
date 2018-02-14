#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define MAX 501
#define INF 99999999
int N;
int adj[MAX][MAX];
int team_weight[MAX];

void Dijkstra(int s,int e,int &count_path,int &count_team)
{
	vector<int> D(N);
	vector<int> num_path(N,0);
	vector<int> teams(N);
	set<int> Set;
	int set_size = -1;
	num_path[s] = 1;
	teams[s] = team_weight[s];
	for(int i = 0; i < N; i++)
	{
		D[i] = adj[s][i];
	}
	for(int i = 0; i < N; i++)
	{
		int num = -1;
		int dist = INF;
		for(int i = 0; i < N; i++)
		{
			if(Set.find(i)==Set.end() && D[i] < dist)
			{
				dist = D[i];
				num = i;
			}
		}
		Set.insert(num);
		if(num ==-1)
		{
			break;
		}
		for(int i = 0; i < N; i++)
		{
			if( Set.find(i)==Set.end() && adj[num][i]!=INF )
			{
				if(D[num] + adj[num][i] < D[i])
				{
					D[i] = D[num] + adj[num][i];
					num_path[i] = num_path[num];
					teams[i] = teams[num] + team_weight[i];
				}
				else if(D[num] + adj[num][i] == D[i])
				{
					num_path[i] = num_path[i] + num_path[num];
					if(teams[num]+team_weight[i] > teams[i])
					{
						teams[i] = teams[num] + team_weight[i];
					}
				}
			}
		}
	}
	count_team = teams[e];
	count_path = num_path[e];
}

int main()
{
	cin >> N;
	int M = 0;
	int S = 0;
	int E = 0;
	int count_path = 0;
	int count_team = 0;
	cin >> M >> S >> E;
	for(int i = 0; i < N; i++)
	{
		cin >> team_weight[i];
		for(int j = 0; j < N; j++)
		{
			if(i == j)
			{
				adj[i][j] = 0;
			}
			else
			{
				adj[j][i] = adj[i][j] = INF;
				
			}
		}
	}
	for(int i = 0; i < M; i++)
	{
		int a,b,l;
		cin >> a >> b >>l;
		adj[a][b]=adj[b][a]= l;
	}
	Dijkstra(S,E,count_path,count_team);
	cout << count_path << ' ' <<count_team;
}
