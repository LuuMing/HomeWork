#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int N;
int M;
void dfs(int n,int d)
{
	if( n == 0 )
	{
		for(auto i : v)
		{
			cout << i << ' ';
		} 
		cout << endl;
		return ; 
	}
	else if(n < 0)
		return;
	else
	{
		for(int jj = min(d,M); jj > 0; jj--)
		{	
			v.push_back(jj);
			dfs(n - jj,jj);
			v.pop_back();
		}
	}
}
int main()
{
	cin >> N >> M;
	dfs(N,M);
}
