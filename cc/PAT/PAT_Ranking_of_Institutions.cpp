#include<ctype.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
struct school
{
	string name;
	int num;
	int totalB;
	int totalA;
	int totalT;
	
};
int get_total(const school & s)
{
	return int( s.totalB/1.5 + (double)s.totalA + s.totalT*1.5);
}
unordered_map<string,school> m;
vector<school> v;
bool cmp(const school & s1, const school & s2)
{
	int t1 = get_total(s1);
	int t2 = get_total(s2);
	if(t1 != t2)
	{
		return t1 > t2;
	}
	else if (s1.num != s2.num)
	{
		return s1.num < s2.num;
	}
	else
	{
		return s1.name < s2.name;
	}
}

int main()
{
	int N; cin >> N;
	for(int i = 0; i < N;i++)
	{
		char id[10];
		int score;
		 char s[10];
		 scanf("%s%d%s",id,&score,s);
		for(int j = 0;s[j]!=0;j++) s[j] = tolower(s[j]);
		if(id[0] == 'B')
		{
			m[s].totalB += score;
		}
		else if (id[0] == 'A')
		{
			m[s].totalA += score;
		}
		else
		{
			m[s].totalT += score;
		}
		m[s].num++;
	}
	for(auto & mm: m)
	{
		v.push_back(mm.second);
		v.back().name = mm.first;
	}
	sort(v.begin(),v.end(),cmp);
	cout << v.size() << endl;
	int rank = 1;
	int pre = get_total(v[0]);
	for(int i = 0; i < v.size(); i++)
	{
		if (get_total(v[i]) != pre)
		{
			rank = i + 1;
			pre = get_total(v[i]);
		}
		printf("%d %s %d %d\n",rank,v[i].name.c_str(),get_total(v[i]),v[i].num);
	}
}
