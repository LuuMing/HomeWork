#include<iostream>
#include<unordered_map>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
unordered_map<string,int> m;
int N;
int main()
{
	int max = -1;
	vector<string> v;
	cin >> N;
	for(int i = 0; i < 2 * N; i++)
	{
		string t; cin >> t;
		m[t]++;
		if(m[t] > max)
		{
			max = m[t];
			v.clear();
			v.push_back(t);
		}
		else if (m[t] == max)
		{
			v.push_back(t);
		}
	}
	if(v.size() == 1)
	{
		cout << v[0] <<' ' <<  m[v[0]];
	}
	else
	{
		sort(v.begin(),v.end());
		cout << v[0] << ' ' << m[v[0]] <<' ' << v.size();
	}

}
