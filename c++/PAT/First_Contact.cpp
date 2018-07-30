#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#define MAX 301
using namespace std;
int index;
struct person
{
	int gender;
	unordered_set<int> friends;
};
unordered_map<int,int> int2id;
unordered_map<int,int> id2int;
person p[MAX];
int K;
int visit[MAX];
vector<int> st1,st2,st3;
bool same(int id1,int id2 )
{
	if( (id1 > 0 && id2 > 0) || (id1 <0 && id2 < 0))
		return true;
	else
		return false;
}
vector<pair<int,int>> result;
bool cmp(const pair<int,int> p1,const pair<int,int> p2)
{
	if(p1.first != p2.first)
	return p1.first < p2.first;
	else
		return p1.second < p2.second;
}
int main()
{
	int N, M; cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int id1,id2;
		scanf("%d%d",&id1,&id2);
		if(!id2int.count(id1))
		{
			id2int[id1] = index;
			int2id[index] = id1;
			index++;
		}
		if(!id2int.count(id2))
		{
			id2int[id2] = index;
			int2id[index] = id2;
			index++;
		}
		if(id1 > 0)
			p[id2int[id1]].gender = 1;
		else
			p[id2int[id1]].gender = -1;
		p[id2int[id1]].friends.insert(id2int[id2]);
		p[id2int[id2]].friends.insert(id2int[id1]);
	}
	cin >> K;
	for(int i = 0; i < K;i++)
	{
		int id1,id2;	scanf("%d%d",&id1,&id2);
		if(!id2int.count(id1) || !id2int.count(id2))
		{
			cout << 0 << endl;
			continue;
		}
		bool same_gender = same(id1,id2);
		visit[id2int[id1]] = 1;
		for(auto e: p[id2int[id1]].friends)
		{
			if(same(int2id[e],id1) && !visit[e])
			{
				st1.push_back(e);
			}
		}
		for(auto e:st1)
		{
			for(auto ee:p[e].friends)
			{
				if(!same_gender)
				{
					if(!same(int2id[e],int2id[ee])&&! visit[ee])
					{
						st2.push_back(ee);
						visit[ee] = 1;
					}
				}
				else
				{
					if(same(int2id[e],int2id[ee]) && !visit[ee])
					{
						st2.push_back(ee);
						visit[ee] = 1;
					}
				}
			}
			visit[e] = 1;
		}
		for(auto e:st2)
		{
			if(p[e].friends.count(id2int[id2]))
			{
				st3.push_back(e);
			}
		}
		for(auto s:st1)
		{
			for(auto ss:st3)
			{
				if(p[s].friends.count(ss))
				{
					result.push_back(make_pair(int2id[s] > 0?int2id[s]:-int2id[s],int2id[ss]>0?int2id[ss]:-int2id[ss]));	
				}
			}
		}

		cout << result.size() << endl;
		sort(result.begin(),result.end(),cmp);
		for(int ii =0; ii <result.size();ii++)
		{
			printf("%d %d\n",result[ii].first,result[ii].second);
		}
		result.clear(); st1.clear();st2.clear();st3.clear();
		for(int i = 0; i < N;i++)
			visit[i] = 0;
	}
}

