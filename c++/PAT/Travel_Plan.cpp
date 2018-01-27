#include<iostream>
#include<list>
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
		list<int> p;
	public:
		int total_distance()
		{
			if (p.size() == 1)
			{
				return 0;
			}
			int sum = 0;
			list<int>::iterator e = p.end();
			e--;		
			for(list<int>::iterator i = p.begin(); i != e;)
			{
				sum = sum + dist_matrix[*i][*(++i)];
			}
			return sum;
		}
		int total_cost()
		{
			if (p.size() == 1)
			{
				return 0;
			}
			int sum = 0;
			list<int>::iterator e = p.end();
			e--;
			for(list<int>::iterator i = p.begin(); i != e;)
			{
				sum = sum + cost_matrix[*i][*(++i)];
			}
			return sum;
		}
		Path(int i)
		{
			p.push_back(i);
		}
		void add(int n)
		{
			p.push_back(n);
		}
		void add(Path &ii)
		{
			for(list<int>::iterator i = ii.p.begin(); i!=ii.p.end();i++)
			{
				p.push_back(*i);
			}
		}
		Path(const Path &ii)
		{
			p = ii.p;
		}
		void pop()
		{
			p.pop_back();
		}
		void output()
		{
			for(list<int>::iterator i = p.begin(); i != p.end(); i++)
			{
				cout<<*i<<' ';
			}
			cout<<this->total_distance()<<' ';
			cout<<this->total_cost();
		}
		bool operator < ( Path &i)
		{
			return this->total_cost() < i.total_cost();
		}
		
};
void view_map(int **& m)
{
	
	cout<<"*****************************"<<endl;
	for(int i = 0; i< N; i++)
	{
		for(int j = 0; j< N;j++)
		{
			cout<<m[i][j]<<"   ";
		}
		cout<<endl;
	}
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
			matrix[i][j] = inf;
		}
	}
}
void matrix_copy(int **& A,int **&B,int N)
{
	for(int i = 0; i < N;i++)
	{
		for(int j = 0; j < N ;j++)
		{
			A[i][j] = B[i][j];
		}
	}
}

Path find_path(int s,int e)
{	if(s == e)
	{
		Path p(s);
		return p;
	}
	int **temp_dist_matrix;
	int **temp_cost_matrix;
	list<Path> short_way;
	init_matrix(temp_dist_matrix,N);
	init_matrix(temp_cost_matrix,N);
	matrix_copy(temp_dist_matrix,dist_matrix,N);
	matrix_copy(temp_cost_matrix,dist_matrix,N);
	Path p(s);                                       //floy算法，插值 
	for(int i = 0 ; i < N; i++)
	{
		if( temp_dist_matrix[s][e] > temp_dist_matrix[s][i] + temp_dist_matrix[i][e] )
		{
			p.add(i);
			temp_dist_matrix[s][e] = temp_dist_matrix[s][i] + temp_dist_matrix[i][e];
			temp_cost_matrix[s][e] = temp_cost_matrix[s][i] + temp_cost_matrix[i][e];
			continue;
		}
		if( temp_dist_matrix[s][e] == temp_dist_matrix[s][i] + temp_dist_matrix[i][e])
		{                                                                 
			Path another_way(p);                     //若有次最短路则添加至list 
			another_way.pop();
			another_way.add(i);
			short_way.push_back(another_way);
		}
	} 
	p.add(e);                         //主最短路添加末尾 
	for(list<Path>::iterator i = short_way.begin(); i!= short_way.end(); i++)
	{
		(*i).add(e);                 //每条次最短路添加上末尾 
	}
	short_way.push_back(p);          //主最短路加入list 
	short_way.sort();                //重载<让cost对最短路的排序
	//////////////////////
//	for(list<Path>::iterator i = short_way.begin(); i!= short_way.end(); i++)
//	{
//		(*i).output();
//		cout<<endl;
//	}
//	cout<<"中间矩阵是:"<<endl;
//	view_map(temp_dist_matrix);
//	cout<<"*********";
//	///////////////////
	
	return *(short_way.begin());    //返回第一条即为cost最小的最短路 
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
		cost_matrix[start][destination] = cost;
	}
	Path i = find_path(S,D);
	i.output();
}


