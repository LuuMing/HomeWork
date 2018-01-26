#include<iostream>
#include<list>
#include<set>
#define inf 0x3f3f3f3f
using namespace std;
int ** dist_matrix = NULL;
int ** cost_matrix = NULL;
int N = 0;
int M = 0;
int S = 0;
int D = 0;

class Path
{
	private:
		int total_distance;
		int total_cost; 
		list<int> p;
	public:
		Path(int i)
		{
			p.push_back(i);
		}
		void add(int n)
		{
			p.push_back(n);
		}
		void add(Path i)
		{
			while( i.p.empty() != true )
			{
				p.push_back( *(i.p.begin()) );
				i.p.pop_front();
			}
		}
		void output()
		{
			for(list<int>::iterator i = p.begin(); i != p.end(); i++)
			{
				cout<<" "<<*i;
			}
		}
};

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
			matrix[i][j] = inf;
		}
	}
}

Path find_path(int s,int e)
{
	set<int> access;
	Path p(s);
	for(int i = 0 ; i < N ;i++)
	{
		if(dist_matrix[s][i]!=-1)
		{
			access.insert(i);
		}
	}

	if( access.end()!=access.find(e))//若直接相连 
	{
		p.add(e);
		return p;
	}
	else                                                 //未直接相连 
	{
		while(access.empty()==false)
		{
			set<int>::iterator it = access.begin();
        	p.add( find_path(*it,e) );
        	access.erase(it);
		}
		return Path(-1);
	}
	if(access.empty())
	{
		return Path(-1);
	}
}
void view_map()
{
	
	cout<<"*****************************"<<endl;
	for(int i = 0; i< N; i++)
	{
		for(int j = 0; j< N;j++)
		{
			cout<<dist_matrix[i][j]<<"   ";
		}
		cout<<endl;
	}
}
int main()
{
	
	cin >> N;
	cin >> M;
	cin >> S;
	cin >> D;
	init_matrix(dist_matrix,N);
	init_matrix(cost_matrix,N);
	for (int i = 0 ; i < M ; i++)
	{
		int start, destination,dist,cost;
		cin >> start >> destination >> dist >>cost;
		dist_matrix[start][destination] = dist;
		dist_matrix[destination][start] = dist;
		cost_matrix[destination][start] = cost;
		cost_matrix[start][destination] = dist;
	}
	view_map();

	
	Path i = find_path(S,D);
	i.output();
	cout<<"finish";
}


