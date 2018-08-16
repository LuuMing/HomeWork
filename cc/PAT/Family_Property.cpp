#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10001
int adj[MAX][MAX];
int sets[MAX];
int area[MAX];
int visit[MAX];
int N;
int min_id = 9999;
int total_k;
int total_area;
int total_sets;
int max_id;
vector<int> v;
struct result
{
	int min_id;
	int k;
	double avg_sets;
	double avg_area;
};
void dfs(int id)
{
	visit[id] = 1;
	if(id < min_id)
		min_id = id;
	total_k++;
	total_area += area[id];
	total_sets += sets[id];
	for(int i = 0 ; i <= max_id;i++)
	{
		if(adj[id][i] && !visit[i])
		{
			dfs(i);
		}
	}
}

vector<result> r;
bool cmp(const result & r1, const result & r2)
{
	if(fabs(r1.avg_area - r2.avg_area) > 0.001)
	{
		return r1.avg_area > r2.avg_area;
	}
	else
	{
		return r1.min_id < r2.min_id;
	}
}
int main()
{
	cin >> N;
	for(int i = 0 ; i < N; i++)	
	{
		int id,fa,ma,k;
		scanf("%d%d%d%d",&id,&fa,&ma,&k);
		if(id > max_id)
		{
			max_id = id;
		}
	
		for(int j = 0; j < k;j++)
		{
			int t; scanf("%d",&t);
			adj[id][t] = adj[t][id] = 1;
		}
		if( fa != -1)	
		{
			adj[fa][id] = adj[id][fa]  =1;
		}
		if( ma  != -1)
		{
			adj[ma][id] = adj[id][ma] = 1;
		}
		scanf("%d%d",sets+id,area+id);
		v.push_back(id);
	}
	for(int i = 0; i <v.size(); i++)
	{
		total_k = 0;
		min_id = 9999;
		total_sets = 0;
		total_area = 0;
		if(!visit[v[i]])
		{
			dfs(v[i]);
			result t;
			t.min_id = min_id;
			t.k = total_k;
			t.avg_area = (double)total_area / (double) total_k;
			t.avg_sets = (double) total_sets / (double) total_k;
			r.push_back(t);
		}
	}
	cout << r.size() << endl;
	sort(r.begin(),r.end(),cmp);
	for(int i = 0; i < r.size();i++)
	{
		printf("%04d %d %.3f %.3f\n",r[i].min_id,r[i].k,r[i].avg_sets,r[i].avg_area);
	}
	
}
