#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 10001
vector< pair<string,int> > h[MAX];
int insert( string num )
{
	int code = 0;
	for(int i = 3; i <= 10;i++)
	{
		code = (code * 10) + (num[i]-'0');
	}
	int pos = code % MAX;
	bool flag = false;
	for(int i = 0; i < h[pos].size();i++ )
	{
		if( num == h[pos][i].first )
		{
			h[pos][i].second++;
			flag = true;
			return h[pos][i].second;
		}
	}
	if(!flag)
	{
		h[pos].push_back(make_pair(num,1));
		return 1;
	}
}
int main()
{
	int N;
	cin >> N;
	int max = -1;
	vector<string> v;
	string num;
	for(int i = 0; i < 2*N;i++)
	{
		cin >> num;
		int n = insert(num);	
		if( n > max )
		{
			max = n;
			v.clear();
			v.push_back(num);
		}
		else if (n == max)
		{
			v.push_back(num);
		}
	}
	sort(v.begin(),v.end());
	if(v.size()==1)
	{
		cout << v[0] <<' ' << max;
	}
	else
	{
		cout << v[0] <<' ' << max <<' '<< v.size(); 
	}
}
