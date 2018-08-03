#include<iostream>
#include<cstdio>
#include<set>
#include<unordered_map>
using namespace std;
int single[100000];
int N;
set<int> s;
unordered_map<int , int > m;
unordered_map <int ,int >m2;
int main()
{
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		int t1,t2; 
		scanf("%d%d",&t1,&t2);
		single[t1] = 1;
		single[t2] = 1;
		m[t1] = t2;
		m[t2] = t1;
	}
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		int t;
		scanf("%d",&t);
		if(single[t] == 0)
		{
			s.insert(t);
			continue;
		}
		if( single[t] == 1 && !s.count(m[t]))
		{
			s.insert(t);
			continue;
		}
		if( single[t] == 1 && s.count(m[t]))
		{
			s.erase(m[t]);
			continue;
		}
	}
	int j = 0;
	cout << s.size() << endl;
	for(auto i : s)
	{
		printf("%05d",i);j++;
		if( j != s.size())
		cout <<' ';
		
	}
}
