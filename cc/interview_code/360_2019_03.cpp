/*

众所周知，集合{1 2 3 … N}有N!种不同的排列，假设第i个排列为Pi且Pi,j是该排列的第j个数。将N个点放置在x轴上，第i个点的坐标为xi且所有点的坐标两两不同。对于每个排列（以Pi为例），可以将其视为对上述N个点的一种遍历顺序，即从第Pi,1个点出发，沿直线距离到达第Pi,2个点，再沿直线距离到达第Pi,3个点，以此类推，最后到达第Pi,N个点，将该路线的总长度定义为L(Pi)，那么所有N!种路线的总长度之和是多少，即L(P1)+L(P2)+L(P3)+...+L(PN!)的结果是多少？*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int visit[10001];
long long sum = 0;
void generate(int i,vector<int> v,int n,unordered_set<int> s)
{
	v.push_back(i);
	s.insert(i);
	if(i > n)
		return;
	if(v.size() == n)
	{
	//	for(auto kk:v)
	//	{
	//		cout << kk <<' ';
	//	}	
	//	cout<< endl;
		for(int ii = 1; ii < v.size() ;ii++)
		{
			sum += abs(visit[v[ii] - 1] - visit[v[ii-1] - 1]);
		}
	//	cout << "sum: " << sum << endl;
		return;
	}
	for(int j = i +1; j <= n; j++)
	{
		if( !s.count(j))
		generate(j,v,n,s);
	}
	for(int j = i -1; j >  0; j--)
	{
		if(!s.count(j))
		generate(j,v,n,s);
	}
}
int main()
{
	int N; cin >> N;
	vector<int> v;
	unordered_set<int> s;
	for(int i = 0; i < N;i++)
	{
		scanf("%d",visit+ i);
	}
	for(int i = 1; i <= N;i++)
	generate(i,v,N,s);
	cout << sum % (1000000000+7);
}
