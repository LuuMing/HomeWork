#include<iostream>
#include<string.h>
using namespace std;
#define MAX 101
#define INF 999999
int N;
int M;
int adj[MAX][MAX];
int D[MAX][MAX];
void floyd()
{
	memcpy(D,adj,MAX*MAX*sizeof(int));
	for(int k = 1; k <= N;k++)
	{
		for(int i = 1; i <= N;i++)
		{
			for(int j = 1;j <= N;j++)
			{
				if(D[i][j] > D[i][k]+D[k][j])
					D[i][j] = D[i][k] + D[k][j];
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	int v = -1;
	for(int i = 0; i <= N;i++)
		for(int j = 0;j <= N;j++)
			adj[i][j] = adj[j][i] = (i==j)?0:INF;
	for(int i = 0; i < M; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		adj[a][b] = adj[b][a] = c;
	}
	floyd();
	bool connected = true;
	int num = -1;
	int length = INF;
	for(int i = 1; i <= N;i++)
	{
		int tem = -1;
		for(int j = 1; j <= N;j++)
		{
			if(D[i][j] > tem)
			{
				tem = D[i][j];
			}
			if(D[i][j] == INF)
			{
				connected = false;
				break;
			}
		}
		if(!connected)
			break;
		else if (tem < length)
		{
			length = tem;
			num = i;
		}
	}
	if(!connected)
		cout << 0;
	else
	{
		cout << num <<' '<<length;  
	}
}
