/*******************
	@author: LuMing
	@date: 18/8/16 12:31~13:17
*********************/
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#define MAX 10990
using namespace std;
bool visit[MAX];
struct family
{
	int sets;
	int area;
	vector<int> child;
};
struct result
{
	int min_id;
	int k;
	double avg_sets;
	double avg_area;
};
int N;
vector<int> v;
vector<result> r;
family f[MAX];
int total_k = 0;
int total_sets = 0;
int total_area = 0;
int min_id = 99999;
bool cmp(const result & r1, const result & r2)
{
	if(fabs(r1.avg_area) - fabs(r2.avg_area) < 0.0001)
	{
		return r1.min_id < r2.min_id;
	}
	else
		return r1.avg_area > r2.avg_area;
}
void dfs(int id)
{
	visit[id] =  true;
	total_k ++;
	total_sets += f[id].sets;
	total_area += f[id].area;
	if(id < min_id)
	{
		min_id = id;
	}
	for(int i = 0; i < f[id].child.size(); i++)
	{
		if( !visit[f[id].child[i]])
		{
			dfs(f[id].child[i]);
		}
	}
}
int main()
{
	cin >> N;
	for(int i = 0; i < N; i ++)
	{
		int id,fa,ma,k,sets,area;
		scanf("%d%d%d%d",&id,&fa,&ma,&k);
		if(fa != -1)
		{
			f[id].child.push_back(fa);
			f[fa].child.push_back(id);
		}
		if(ma != -1)
		{
			f[id].child.push_back(ma);
			f[ma].child.push_back(id);
		}
		for(int j = 0; j < k;j++)
		{
			int t; scanf("%d",&t);
			f[t].child.push_back(id);
			f[id].child.push_back(t);
		}
		scanf("%d%d",&sets,&area);
		f[id].sets = sets;
		f[id].area = area;
		v.push_back(id);
	}
	for(int i = 0; i < v.size() ;i++)
	{
		total_k = 0;
		total_sets = 0;
		total_area = 0;
		min_id = 999999;	
		if(!visit[v[i]])
		{
			dfs(v[i]);
		}
		else
			continue;
		result t; t.min_id = min_id;
		t.k = total_k;
		t.avg_sets = (double)total_sets / (double)total_k;
		t.avg_area = (double)total_area / (double)total_k; 
		r.push_back(t);
	}
	sort(r.begin(),r.end(),cmp);
	cout << r.size() << endl;
	for(int i = 0; i < r.size(); i++)
	{
		printf("%04d %d %.3f %.3f\n",r[i].min_id,r[i].k,r[i].avg_sets,r[i].avg_area);
	}
}
