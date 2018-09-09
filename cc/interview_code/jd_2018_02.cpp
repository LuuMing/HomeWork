//判断一个图是否是 Multipartite graph
#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int> edge[1001];
int e[1001][2];
int N,M;
bool flag = true;
int cnt = 0;
int visit[1001];
set<int> d;
void dfs(int s)
{
    visit[s] = 1;
    cnt++;
    for(set<int>::iterator i = edge[s].begin(); i != edge[s].end(); i++)
    {
        if(!visit[*i] &&!(d.count(s)&& d.count(*i)) )
        {
            dfs(*i);
        }
    }
}
void init()
{
    for(int i = 1; i <= N; i++)
    {
    	flag = true;
        edge[i].clear();
        visit[i] =  0;
        cnt = 0;
    }
}
int main ()
{
    int T; cin >> T;
    for(int i = 0; i < T;i ++)
    {
      	cin >> N >> M;
        init();
        for(int j = 1; j <= M;j ++)
        {
            int u,v; scanf("%d%d",&u,&v);
            edge[u].insert(v);
            edge[v].insert(u);
			e[j][0] = u;
            e[j][1] = v;
        }
   
        for(int j = 1; j <= M; j++)
        {
        	d.clear();
        	d.insert(e[j][0]);
            d.insert(e[j][1]);
			dfs(e[j][0]);
			//cout << cnt;
            if(cnt != N )
           	{
                flag = false;
                break;
            }
            cnt = 0;
            for(int k = 1; k <=N;k++)
            	visit[k] = 0;
        }
        if(flag)
        {
            cout << "Yes"<<endl;
        }
        else	cout << "No"<<endl;
        
    }
}
