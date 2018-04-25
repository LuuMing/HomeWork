#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 101
struct node
{
	int x,y;
	friend bool operator < (const node & n1,const node & n2)
	{
		int p1  = n1.x * n1.x + n1.y*n1.y;
		int p2 = n2.x * n2.x + n2.y * n2.y;
		return p1 < p2;
	}
};
vector<node> p;
int N;
int D;
int dist[MAX];
int path[MAX];
vector<int> r;
vector<int> Path;
bool connect(int v1,int v2)
{
	double dx =  p[v1].x - p[v2].x;
	double dy = p[v1].y - p[v2].y;
	if(dx*dx + dy*dy < D * D)
	{
		return true;
	}
	return false;
}
bool reach(int v)
{
	if(p[v].x + D > 50 || p[v].x - D <-50 || p[v].y + D > 50 || p[v].y - D <-50)
	{
		return true;
	}
	return false;
}
void first_step()
{
	for(int i = 0; i < p.size(); i++)
	{
		if( p[i].x*p[i].x + p[i].y*p[i].y < (7.5+D)*(7.5+D) )
			dist[i] = 1;
		else
			dist[i] = -1;
	}
}
void output_path(int v)
{
	Path.push_back(v);
	if(path[v] != -1)
	{
		output_path(path[v]);
	}
}
void Unweight()
{
	first_step();
	vector<int> q;
	for(int i = 0; i < N;i++)
	{
		if(reach(i))
			r.push_back(i);
		if(dist[i] != -1)
			q.push_back(i);	
	}
	while(!q.empty())
	{
		int V = q[0];
		q.erase(q.begin());
		for(int i = 0; i < p.size();i++)
		{
			if(connect(V,i))
			{
				if(dist[i] == -1)
				{
					dist[i]  = dist[V] + 1;
					path[i] = V;
					q.push_back(i);
				}
			}
		}
	}
}
int main()
{
	cin >> N >> D;
	for(int i = 0; i < N; i++)
	{
		int a,b; cin >> a >> b;
		if( abs(a) > 50 || abs(b) > 50 || a*a+b*b <= 7.5*7.5)
			continue;
		node t;
		t.x = a; t.y = b;
		p.push_back(t);
		path[i] = -1;
	}
	sort(p.begin(),p.end());
	if(D + 7.5 > 50)
	{
		cout << 1 << endl;
		return 0;
	}
	Unweight();
	int min_dist = 999999;
	int num = -1;
	for(auto &i : r)
	{
		if(dist[i] != -1 && dist[i] < min_dist)
		{
			min_dist = dist[i];
			num = i;
		}
	}
	if(num == -1)
	{
		cout << 0; return 0;
	}
	else
	{
		cout << min_dist << endl;
		output_path(num);
		for(auto i = Path.rbegin(); i != Path.rend()-1;i++)
		{
			cout << p[*i].x <<' '<< p[*i].y << endl;
		}
	}
}
