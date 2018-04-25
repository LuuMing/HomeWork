#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 101
using namespace std;
struct node
{
	int x;int y;
};
vector<node> p;
int path[MAX];
int N;
int D;
bool cmp(const int & v1, const int & v2)
{
	int d1 = p[v1].x * p[v1].x + p[v1].y * p[v1].y;
	int d2 = p[v2].x * p[v2].x + p[v2].y * p[v2].y;
	return d1 < d2;
}
bool first(int v)
{
	if(p[v].x*p[v].x + p[v].y * p[v].y < (7.5+D) * (7.5+D))
		return true;
	return false;
}
bool reach(int v)
{
	if(p[v].x +D >= 50 || p[v].x - D <= -50 || p[v].y + D >= 50 || p[v].y-D <= -50)
		return true;
	return false;
}
bool connect(int v1,int v2)
{
	int dx = (p[v1].x - p[v2].x);
	int dy = (p[v1].y - p[v2].y);
	if(dx*dx + dy*dy <= D*D )
	{
		return true;
	}
	return false;
}
void BFS()
{
	vector<int> s;
	vector<int> q;
	vector<bool> visited(MAX,false);
	for(int i = 0; i < p.size();i++)
	{
		s.push_back(i);
	}
	sort(s.begin(),s.end(),cmp);
	for(int i = 0; i < s.size();i++)
	{
		if(first(s[i]))
		{
			q.push_back(s[i]);
			visited[s[i]] = true;
		}
	}
	int step = 2;
	int tail;
	if(!q.empty())
	 tail = q[q.size()-1];
	while(!q.empty())
	{
			int top = q[0];
			q.erase(q.begin());
			if(reach(top))
			{
				cout << step << endl;
				vector<int> Path;
				while(top != -1)
				{
					Path.push_back(top);
					top = path[top];
				}
				for(int i = Path.size()-1;i >= 0; i--)
				{
					cout << p[Path[i]].x << ' '<< p[Path[i]].y << endl;
				}
				return ;
			}
			for(int i = 0; i < p.size();i++)
			{
				if(connect(top,i) && !visited[i])
				{
					q.push_back(i);
					visited[i] = true;
					path[i] = top;
				}		
			}
			if(top == tail)
			{
				step ++;
				tail = q[q.size()-1];
			}
	}
	if(q.empty())
	cout << 0 << endl;
}
int main()
{
	cin >> N >> D;	
	for(int i = 0; i < N;i++)
	{
		int a,b; cin >> a >> b;
		
		node t; t.x = a; t.y  = b;
		p.push_back(t);
		path[i] = -1;
	}
	if(D + 7.5 >= 50)
	{
		cout << 1; return 0;
	}
	BFS();
}
