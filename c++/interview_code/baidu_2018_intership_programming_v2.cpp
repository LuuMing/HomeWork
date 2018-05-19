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
void DFS(int x,int y)
{
	int pre_x = saber.x;
	int pre_y = saber.y;
	if(!visited[x][y] && x <= N && y <= M && x >= 1 && y >= 1)
	{
		
		if( map[x][y] > map[saber.x][saber.y] )
		{
			saber.x = x;
			saber.y = y;
			if(map[saber.x][saber.y] > max_h)
			{
				max_h = map[saber.x][saber.y];
			}
			saber.x = x;
			saber.y = y;
			DFS(x-1,y);
			saber.x = x;
			saber.y = y;
			DFS(x+1,y);
			saber.x = x;
			saber.y = y;
			DFS(x,y+1);
			saber.x = x;
			saber.y = y;
			DFS(x,y-1);
		}
	}
	saber.x = pre_x;
	saber.y = pre_y;
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
	DFS(saber.x+1,saber.y);
	
	DFS(saber.x-1,saber.y);
	DFS(saber.x,saber.y+1);
	DFS(saber.x,saber.y-1);
	cout << max_h;
}
