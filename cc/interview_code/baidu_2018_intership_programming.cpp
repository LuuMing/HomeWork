/*

输入N，M 代表有一块N*M的区域
输入 x,y 代表 saber初始位置 为 x,y
输入N行，每行M个值
代表区域H(i,j)的高度
saber很孤傲，只朝海拔不低于自己当前位置的方向走(上、下、左、右)，问能走到多高的地方?

sample input:
5 8
3 3
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
3 2 0 2 4 -1 0 0
0 0 0 3 -1 8 -1 0
0 0 0 5 0 -1 0 0
sample output:

5
*/
/*************************************************************/
#include<iostream>
using namespace std;
#define MAX 201
int N,M;
long long int map[MAX][MAX];
struct p
{
	int x,y;
};
p saber;
bool visited[MAX][MAX];
int max_h = -1;
void DFS(int x,int y,int p_x,int p_y)
{
	visited[x][y] = true;
	if(x>= 1 && x <= N && y >= 1 && y <= M)
	{
		if(map[x][y] >= map[saber.x][saber.y])
		{
			saber.x = x;
			saber.y = y;
			if(map[saber.x][saber.y] > max_h)
			{
				max_h = map[saber.x][saber.y];
			}
		}
		int l_x = x-1;
		int r_x = x+1;
		int l_y = y-1;
		int r_y = y+1;
		if(!visited[l_x][y]&& map[l_x][y] >= map[saber.x][saber.y]  )
		{
			DFS(l_x,y,x,y);
		}
		if(!visited[r_x][y] && map[r_x][y] >= map[saber.x][saber.y])
		{
			DFS(r_x,y,x,y);
		}
		if(!visited[x][l_y] && map[x][l_y] >= map[saber.x][saber.y])
		{
			DFS(x,l_y,x,y);
		}
		if(!visited[x][r_y] && map[x][r_y] >= map[saber.y][saber.y])
		{
			DFS(x,r_y,x,y);
		}
		saber.x = p_x;           //back tracing
		saber.y = p_y;
	}
	else return;
}
int main()
{
	cin >> N >> M;
	cin >> saber.x >> saber.y;
	for(int i = 1; i <= N;i++)
	{
		for(int j = 1; j <= M;j++)
		{
			cin >> map[i][j];
			visited[i][j] = false;
		}
	}
	DFS(saber.x,saber.y,saber.x,saber.y);
	cout << max_h;
}
