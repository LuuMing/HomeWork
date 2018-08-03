#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int adj[501][501];
int Cmax;
int N;
int Sp;
int M;
int min_dist;
#define INF 999999
vector<int> capacity;
vector<vector<int>>pre;
vector<vector<int>> dijkstra(int & min_dist)  //to return pre, and record minimal distance between vertex 0 and end.
{
	vector<bool> flag(N+1,false);       //to mark the visited vertex.
	vector<int> D(N+1);               
	for(int i = 0; i < N+1; i++)
	{
		D[i] = adj[0][i];
	}
	vector<vector<int>> pre(N+1);
	//flag[0] = false;    If mark inital vertex be visited, then, for all vertex i that link to inital vertex directly, pre[i] will be empty.
	//                    Cause error while back-track to start.
	for(int i = 0; i < N+1;i++)
	{
		int num = -1;
		int dist = INF;
		for(int i = 0;  i < N+1;i++)
		{
			if(flag[i]== false && D[i] < dist)  //Notice:not "adj[0][i] < dist"
			{
				num = i;
				dist = D[i];
			}
		}
		if(num == -1)
		{
			break;
		}
		flag[num] = true;
		for(int i = 0; i < N+1; i++)
		{
			int temp = D[num] + adj[num][i];
			if(flag[i] == false && temp < D[i])
			{
				pre[i].clear();
				pre[i].push_back(num);
				D[i] = temp;
			}
			else if(flag[i] == false && temp == D[i])
			{
				pre[i].push_back(num);
			}
		}
	}
	min_dist = D[Sp];                                 //record the minimal distance.
	return pre;
	
}
void compute_bike(vector<int> path,int& send,int& back) //for complete path, calculate the send and back
{
	int cur_send = 0;
	int cur_back = 0;
	for(int i = path.size()-2;i>=0;i--)
	{
		if(cur_back + capacity[path[i]] < Cmax/2)
		{
			cur_send += Cmax/2 - (cur_back + capacity[path[i]]);
			cur_back = 0;
		}
		else
		{
			cur_back = cur_back + capacity[path[i]]-Cmax/2;
		}
	}
	send = cur_send;
	back = cur_back;
}
int compute_dist(vector<int> path)
{
	int sum = 0;
	for(int i = 1;i < path.size();i++)
	{
		sum += adj[path[i-1]][path[i]];
	}
	return sum;
}

vector<int> temp,best;                                  
int min_send = INF;
int min_back = INF;
void DFS(int s,int e)                    
{
	if(s==e)                          
	{
		temp.push_back(e);
		int temp_dist = compute_dist(temp);
		int send = 0;
		int back = 0;
		compute_bike(temp,send,back);
		if( temp_dist == min_dist)            // 1. the path needs to be the mininal distance
		{
			if(send < min_send)           // 2. lesser send
			{
				min_send = send;
				min_back = back;
				best = temp;
			}
			else if(send == min_send&& back<min_back)//same send but lesser back
			{
				min_send = send;
				min_back = back;
				best = temp;
			}
		}
		temp.pop_back(); //！！！
		return ;
	}
	temp.push_back(e);
	for(auto &i:pre[e])
	{
		DFS(s,i);
	}
	temp.pop_back();         //！！！
}
int main()
{
	cin >> Cmax >> N >> Sp >> M;
	capacity.resize(N+1);
	for(int i = 1;i < N+1;i++)
	{
		cin >> capacity[i];
	}
	for(int i = 0;i < N+1;i++)
	{
		for(int j = 0; j < N+1;j++)
		{
			if(i == j)
			{
				adj[i][j] = adj[j][i] = 0;
			}
			else
			{
				adj[i][j] = adj[j][i] = INF;
			}
		}
	}
	for(int i = 0;  i < M;i++)
	{
		int a,b,d;
		cin >> a >> b>>d;
		adj[a][b] = adj[b][a] = d;
	}
	pre = dijkstra(min_dist);
	DFS(0,Sp);
	cout << min_send<<' ';	
	for(int i = best.size()-1;i >=0;i--)
	{
		if(i!=0)
		cout <<best[i] <<"->";
		else
		cout << best[i]<<' ';
	}
	cout << min_back;	
	
}
