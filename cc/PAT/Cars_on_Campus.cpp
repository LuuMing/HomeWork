/***********
	@author:LuMing
	@date: 18/8/28 19:03~20:33
**************/
#include<iostream>
#include<algorithm>
#include<string.h>
#include<unordered_map>
using namespace std;
int N,M;
struct record
{
	char name[10];
	int hh,mm,ss;
	char state[5];
	bool valid = false;
};
unordered_map<string,int> s;
record r[10001];
int num[25*61*61];
bool cmp(const record & r1, const record & r2)
{
	if(r1.hh != r2.hh)
	{
		return r1.hh < r2.hh;
	}
	else if (r1.mm != r2.mm)
		return r1.mm < r2.mm;
	else
		return r1.ss < r2.ss;
}

unordered_map<string,record> m;
unordered_map<string,int>  total;
int main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		scanf("%s %d:%d:%d %s",r[i].name,&r[i].hh,&r[i].mm,&r[i].ss,r[i].state);
	}
	sort(r,r+N,cmp);
	for(int i = 0; i < N;i++)
	{
		if(strcmp(r[i].state,"in") == 0)
		{
			s[r[i].name] = i;
		}
		if(s.count(r[i].name) && strcmp(r[i].state,"out") == 0)
		{
			r[s[r[i].name]].valid = true;
			r[i].valid = true;
			s.erase(r[i].name);
		}
	}
	int cnt = 0;
	int Time = 0;
	for(int i = 0; i < N; i++)
	{


		if( !m.count( r[i].name) && strcmp(r[i].state,"in") == 0 &&r[i].valid)
		{
		
			for(; Time <= r[i].hh *3600 + r[i].mm * 60 + r[i].ss;Time++) 
				num[Time] = cnt;	
			m[r[i].name] = r[i];
				cnt++;	
		}
		if( m.count(r[i].name) && strcmp(r[i].state, "out")==0 &&r[i].valid)
		{
			for(; Time <= r[i].hh *3600 + r[i].mm * 60 + r[i].ss;Time++) 
				num[Time] = cnt;	
			string id = r[i].name;
			total[id] += r[i].hh*3600 + r[i].mm * 60 + r[i].ss - m[id].hh * 3600 - m[id].mm * 60 - m[id].ss; 
		
			m.erase(id);
			cnt--;	
		}
			
	}
	for(int i = 0; i < M; i++)
	{
		int hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);	
		printf("%d\n",num[hh*3600+mm*60+ss]);
	}
	vector<string> vv;
	int total_time = 0;
	for(auto i: total)
	{
		if(i.second > total_time)
		{
			vv.clear();
			vv.push_back(i. first);
			total_time = i.second;
		}
		else if (i.second == total_time)
		{
			vv.push_back(i.first);
		}
	}
}
