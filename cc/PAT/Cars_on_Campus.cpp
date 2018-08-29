/***********
	@author:LuMing
	@date: 18/8/28 19:03~20:33
**************/
#include<iostream>
#include<algorithm>
#include<string.h>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;
int N,M;
struct record
{
	char name[10];
	int hh,mm,ss;
	char state[5];
};
record r[10001];
vector<record> valid;
unordered_map<string,int> s;
unordered_map<string,int> m;
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
			
			valid.push_back(r[s[r[i].name]]);
			valid.push_back(r[i]);
			s.erase(r[i].name);
		}
	}
	sort(valid.begin(),valid.end(),cmp);
	int T = 0;
	int cnt = 0;
	for(int i = 0; i < M; i++)
	{
		int hh,mm,ss; scanf("%d:%d:%d",&hh,&mm,&ss);
		while(T <= hh *3600 + mm*60+ss)
		{
			while(true)
			{
				if(valid.empty())
					break;
				int now = valid[0].hh * 3600 + valid[0].mm*60+ valid[0].ss;
				if(now != T)
					break;
				else
				{
					if(strcmp(valid[0].state,"in") == 0)
					{
						cnt++;
						m[valid[0].name] = now;
					}	
					else
					{
						cnt--;
						total[valid[0].name] += now - m[valid[0].name];
					}
					valid.erase(valid.begin());
				}
			}
			
			T++;
		}
		printf("%d\n",cnt);
	}
	int longest = 0;
	set<string> vv;
	for(auto i:total)
	{
		if( i.second > longest)
		{
			vv.clear();
			longest = i.second;
			vv.insert(i.first);
		}
		else if (i.second == longest)
		{	
			vv.insert(i.first);
		}
	}
	for(auto i : vv)
	{
		cout << i <<' ';
	}
	int h = longest / 3600;
	int m = (longest - h * 3600) / 60;
	int s =  longest - h * 3600 - m * 60;
	printf("%02d:%02d:%02d\n",h,m,s);
	return 0;
}
