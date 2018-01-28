#include<iostream>
#include<vector>
#include<set>
#define inf 99999
using namespace std;
int ** dist_matrix = NULL;
int N = 0;
int M = 0;
int S = 0;
int D = 0;

int * pathfind(int s)
{
	int *D = new int [N];               //中间向量D 
	int *Path = new int [N];            //用Path记录路径
	set<int> Set;
	Set.insert(s);                      //初始顶点加入集合 
	for(int i = 0; i < N;i++)
	{
		D[i] = dist_matrix[s][i];      //生成中间向量
		Path[i] = 0;                   //初始化Path 
	}                                   
	while( Set.size() < N)              //not all node in Set, DO!
	{
		int num = 0;
		int dist = inf;
		for(int i = 0; i < N; i++)
		{
			if( Set.find(i)==Set.end() && D[i] < dist) //找出与顶点相连最短点,且此点未加入集合 
			{                          
				num = i;
				dist = D[i];                           //记录编号num 
			}
		}                                
		for(int i = 0; i < N; i++)
		{
			int temp = dist + dist_matrix[num][i];
			if( Set.find(i)==Set.end() && temp < D[i])                     //对于所有未加入集合的点,且可被num点松弛 
			{
				D[i] = temp;                                   //重点来了，松弛操作
				Path[i] = num;                                 //记录num点，意思为顶点到i之间经过num 
			}                             
		}                           
		Set.insert(num);
	}
	cout<<"Path:";
	for(int i = 0; i < N;i++)
	{
		cout<<Path[i]<<" ";
	}                   
		cout<<endl;

	return D;                       //D[i]即为顶点到i点的最短距离 	                                      
}


void init_matrix(int**& matrix,int N)
{
	matrix  = new int*[N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new int[N];
	}
	for(int i = 0;i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(i==j)
			{
				matrix[i][j] = 0;
				continue;
			}
			matrix[i][j] = inf;
		}
	}
}
void view_map(int **& m)
{
	cout<<"*****************************"<<endl;
	for(int i = 0; i< N; i++)
	{
		for(int j = 0; j< N;j++)
		{
			if(m[i][j]==inf)
			{
				cout<<"∞"<<"    ";
			}
			else
				cout<<m[i][j]<<"    ";
		}
		cout<<endl;
	}
}
int main()
{
	N = 4;        //点的个数 
	M = 5;		  //边的个数 
	S = 0;        //顶点 
	D = 3;        //终点 
	init_matrix(dist_matrix,N);
	dist_matrix[0][1] = 1;
	dist_matrix[1][3] = 2;
	dist_matrix[0][3] = 4;
	dist_matrix[0][2] = 2;
	dist_matrix[2][3] = 1;
	for(int i = 0; i< N ;i++)
	{
		for(int j =0 ;j<N;j++)
		{
			dist_matrix[j][i] = dist_matrix[i][j];
		}
	} 
//	for(int i = 0 ; i < M ; i++)
//	{
//		int start, destination,dist;
//		cin >> start >> destination >> dist;
//		dist_matrix[start][destination] = dist;
//		dist_matrix[destination][start] = dist;
//	}
	view_map(dist_matrix);     //查看邻接矩阵 
	cout<<"起始点为:"<<S<<endl;
	cout<<"终点为:"<<D<<endl;
	cout<<"最短距离为:"<<pathfind(S)[D]; 
}
