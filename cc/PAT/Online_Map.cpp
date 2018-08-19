/*****************
	@author: LuMing
	@date: 18/8/19 20:27~22:15
*****************/
#include<iostream>
#include<vector>
using namespace std;
#define MAX 501
#define INF 99999
int map[MAX][MAX];
vector<int> v1,v2;
int length[MAX][MAX];
int Time[MAX][MAX];
int N, M;
int pre_length[MAX];
int pre_Time[MAX];
int S,E;
int D[MAX];
int T[MAX];
int visit[MAX];
void output1(int v)
{
	v1.push_back(v);
	if(v == pre_length[v])
		return;	
	else
		output1(pre_length[v]);
}
void output2(int v)
{
	v2.push_back(v);
	if(v == pre_Time[v])
		return;	
	else
		output2(pre_Time[v]);
}
int main()
{
	int Dist;
	cin >> N >> M;
	for(int i = 0; i < N;i++)
	{
		pre_length[i] = i;
		pre_Time[i] = i;
		for(int j = 0; j < N;j++)
		{
			length[i][j] = length[j][i] = (i==j)?0:INF;
			Time[i][j] = Time[j][i] = (i==j)?0:INF;
		}
	}
	for(int i = 0; i < M;i++)
	{
		int v1,v2,one_way,l,t;
		scanf("%d%d%d%d%d",&v1,&v2,&one_way,&l,&t);
		if(one_way)
		{
			map[v1][v2] = 1;
			length[v1][v2] = l;
			Time[v1][v2] = t;
		}
		else
		{
			map[v1][v2] = 1;
			map[v2][v1] = 1; 
			length[v1][v2] = length[v2][v1] = l;
			Time[v1][v2] = Time[v2][v1] = t;
		}
	}
	cin >> S >> E;
	for(int i = 0; i < N;i++)
	{
		D[i] = length[S][i];
		T[i] = Time[S][i];
	}
	visit[S] = 1;
	for(int i = 0; i < N;i++)
	{
		int num = -1;
		int min_dist = 99999;
		for(int j = 0; j < N; j++)
		{
			if(!visit[j] && D[j] < min_dist)
			{
				min_dist = D[j];
				num = j;
			}
		}
		if(num == -1)
			break;
		visit[num] = 1;
		for(int v = 0; v < N; v++)
		{
			if(!visit[v] && length[num][v] != INF)
				if(D[num] + length[num][v] < D[v] && )
				{
					T[v] = T[num] + Time[num][v];
					D[v] = D[num] + length[num][v];	
					pre_length[v] = num;
				}
				else if (D[num] + length[num][v] == D[v]  &&
					T[num]+ Time[num][v] < T[v] && map[num][v])
				{
					T[v] = T[num] + Time[num][v];
					pre_length[v] = num;
				}
		}
	}
	output1(E);
	Dist = D[E];
	int pre_num[MAX];
	for(int i = 0; i < N;i++)
	{
		D[i] = length[S][i];
		T[i] = Time[S][i];
		visit[i] = 0;
		pre_num[i] = 0;
	}
	visit[S] = 1;
	for(int i = 0; i < N;i++)
	{
		int num = -1;
		int min_dist = 99999;
		for(int j = 0; j < N; j++)
		{
			if(!visit[j] && D[j] < min_dist)
			{
				min_dist = D[j];
				num = j;
			}
		}
		if(num == -1)
			break;
		visit[num] = 1;
		for(int v = 0; v < N; v++)
		{
			if(!visit[v] && length[num][v] != INF)
				if(T[num] + Time[num][v] < T[v])
				{
					T[v] = T[num] + Time[num][v];
					pre_Time[v] = num;
					pre_num[v] = pre_num[num] + 1;
				}
				else if (T[num] + Time[num][v] == T[v] && pre_num[num] + 1 < pre_num[v]) 
				{
					pre_Time[v] = num;
					pre_num[v] = pre_num[num] + 1;
				}
			}
		}
	output2(E);
	if( v1 == v2)
	{
		cout << "Distance = " << Dist <<"; ";
	}
	else
	{
		cout << "Distance = " << Dist <<": "<<S;
		for(auto i = v1.rbegin();  i!=v1.rend(); i++)
		{	
			cout << " -> " <<*i;
		}
		cout << endl;
		
	}
	cout << "Time = " <<  T[E] <<": "<<S;
	for(auto i = v2.rbegin();  i!=v2.rend(); i++)
	{	
		cout << " -> " <<*i;
	}
}
