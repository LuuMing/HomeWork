#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define MAX 40008
#include<unordered_map>
using namespace std;
int N;
int K;
unordered_map<string,int> str2int;
vector<int> person[MAX];
int main()
{
	int id = 0;
	cin >> N >> K;
	for(int i = 0; i < K;i++)
	{
		int c,n; scanf("%d%d",&c,&n);
		for(int i = 0; i < n;i++)
		{
			string name;cin >> name;
			if(!str2int.count(name))
			{
				str2int[name] = ++id;
			}
			person[str2int[name]].push_back(c);
		}
	}
	for(int i = 0; i < N;i++)
	{
		string t; cin >> t;
		cout << t<<' ';
		sort(person[str2int[t]].begin(),person[str2int[t]].end());
		cout << person[str2int[t]].size();
		for(int i =0; i < person[str2int[t]].size();i++)
		{
			cout <<' '<<person[str2int[t]][i];
		
		}
		cout << endl;
	}
}
