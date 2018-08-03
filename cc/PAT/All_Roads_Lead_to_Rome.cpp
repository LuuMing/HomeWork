#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
#define MAX 201
#define INF 999999
unordered_map<string,int> s2i;
unordered_map<int,string> i2s;
int N;
int K;
int adj[MAX][MAX];
int happ[MAX];
int pre[MAX];
int NUM;
int COST;
int HAP;
void dijkstra()
{
	int D[MAX];
	int w[MAX];
	int num[MAX];
	bool visit[MAX];
	for(int i = 0; i < N;i++)
	{
		D[i] = INF;
		visit[i] = false;
		w[i] = happ[i];
		num[i] = 1;
		pre[i] = i;
	}
	num[0] = 1;
	D[0] = 0;
//	visit[0] = true;
	for(int i = 0; i < N; i++)
	{
		int u = -1;
		int min = INF;
		for(int j = 0; j < N; j++)
		{
			if(D[j] < min && !visit[j])
			{
				min = D[j];
				u = j;
			}
		}
		if(u == -1)
			break;
		visit[u] = true;
		for(int v = 0; v < N; v++) {
		  if(visit[v] == false&& adj[u][v] != INF) {
    			if(D[u] + adj[u][v] < D[v]) {
      			D[v] = D[u] + adj[u][v];
      			num[v] = num[u];
    			w[v] = w[u] + happ[v];
      			pre[v] = u;
    		} else if(D[u] + adj[u][v] == D[v]) {
      			num[v] = num[v] + num[u];
      			if(w[u] + happ[v] > w[v]) {
        			w[v] = w[u] + happ[v];
        			pre[v] = u;
      			}
    		}
  			}
		}	
	}
	NUM = num[s2i["ROM"]];
	COST = D[s2i["ROM"]];
	HAP = w[s2i["ROM"]];
}
void printPath(int v) {
    if(v == s2i["ROM"]) {
        printf("%s", i2s[v].c_str());
        return ;
    }
    printPath(pre[v]);
    printf("%s->", i2s[v].c_str());
}
int main()
{
	string start;
	cin >> N >> K >> start;
	s2i[start] = 0;
	i2s[0] = start;
	for(int i = 1; i < N;i++)
	{
		char name[4]; int happy; 
		scanf("%s%d",name,&happy);
		s2i[name] = i;
		i2s[i] = name;
		happ[i] = happy;
	}
	for(int i = 0; i < N;i++)
		for(int j = 0; j < N;j++)
			adj[i][j] = adj[j][j] = (i==j) ?0:INF;
	for(int i = 0; i < K; i++)
	{
		char name1[5],name2[5]; int w;
		scanf("%s%s%d",name1,name2,&w);
		adj[s2i[name1]][s2i[name2]] = adj[s2i[name2]][s2i[name1]] = w;
	}
	dijkstra();
	cout << NUM <<' '<< COST <<' '<< HAP;
	printPath(0);

}
