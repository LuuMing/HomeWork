#include<iostream>
#include<cstdio>
#define M_MAX 1500
#define N_MAX 150
#define L_MAX 200
using namespace std;
int brain[M_MAX][N_MAX][L_MAX];
bool visited[M_MAX][N_MAX][L_MAX];
int M;
int N;
int L;
int T;
int count = 0;
bool valite(int x, int y ,int l)
{
	if( x >= M || x < 0 || y >= N || y < 0 || l >= L || l < 0)
		return false;
	return true;
}
void dfs(int x,int y,int l)
{
	visited[x][y][l] = true;
	count ++;
	int dx[6] = {1,-1,0,0,0,0};
	int dy[6] = {0,0,1,-1,0,0};
	int dz[6] = {0,0,0,0,1,-1};
	for(int i = 0; i < 6;i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		int zz = l + dz[i];
		if(valite(xx,yy,zz))
		{
			 if(brain[xx][yy][zz]&& !visited[xx][yy][zz])
				dfs(xx,yy,zz);
		}	
	}
}
int main()
{
	int total = 0;
	cin >> M >> N >> L >> T;
	for(int l = 0; l < L; l++)
	{
		for(int m = 0; m < M; m++)
		{
			for(int n = 0; n < N; n++)
			{
				scanf("%d",&brain[m][n][l]);
			}
		}
	}
	for(int l = 0; l < L; l++)
	{
		for(int m = 0; m < M; m++)
		{
			for(int n = 0; n < N; n++)
			{
				if (brain[m][n][l]&& !visited[m][n][l])
				{
					count = 0;
					dfs(m,n,l);
					if(count >= T)
						total += count;
				}
			}
		}
	}
	cout << total;
}