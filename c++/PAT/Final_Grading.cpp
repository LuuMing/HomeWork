#include<cstdio>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct score
{
	int Gp = -1;
	int m = -1;
	int f = -1;
};
unordered_map<string,score> m;
vector<pair<string,score>> v;
int get_G(score s)
{
	if(s.m > s.f && s.m != -1 && s.f != -1) 
	{
		return int((s.m * 0.4 + s.f * 0.6) + 0.5);
	}
	else
	{
		if(s.f == -1)	
			return int(s.m * 0.6+0.5);
		if(s.m == -1)
			return s.f;
		if( s.f == -1 && s.m == -1)
			return 0;
	}
}
bool cmp(const pair<string,score> &p1,const  pair<string,score> & p2)
{
	int G1 = get_G(p1.second);
	int G2 = get_G(p2.second);
	if(G1 == G2)
	{
			return p1.first < p2.first;
	}
	else
		return G1 > G2;

}
int main()
{
	int P, M,N;
	cin >> P >> M >> N;
	for(int i = 0; i < P; i++)
	{
		char name[30]; int online_score;
		scanf("%s%d",name,&online_score);
		if(online_score < 200)
			continue;
		m[name].Gp = online_score;
	}
	for(int i = 0; i < M ; i++)
	{
		char name[30]; int score;
		scanf("%s%d",name,&score);
		if(m.count(name))
		m[name].m = score;
	}
	for(int i = 0; i < N ; i++)
	{
		char name[30]; int score;
		scanf("%s%d",name,&score);
		if(m.count(name))
		m[name].f = score;
	}
	for(auto a:m)
	{
		v.push_back(make_pair(a.first,a.second));
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0; i < v.size(); i++)
	{
		if(get_G(v[i].second) >= 60)
		printf("%s %d %d %d %d\n",v[i].first.c_str(),v[i].second.Gp,v[i].second.m,v[i].second.f,get_G(v[i].second));
	}

}

