#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#define MAX 9999
using namespace std;
unordered_map<int,bool> m;
vector<int> v[MAX];
vector<pair<int,int>> p;
bool cmp(const pair<int,int> & p1, const pair<int,int> & p2)
{
	if(p1.first != p2.first)
		return p1.first < p2.first;
	else
		return p1.second  < p2.second;
}
int N,M;

int main()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		string id1,id2; cin >> id1 >> id2;
		int int_id1 = abs(stoi(id1));
		int int_id2 = abs(stoi(id2));
		if( id1.size() == id2.size() )
		{
			v[int_id1].push_back(int_id2);	
			v[int_id2].push_back(int_id1);
		}
		m[int_id1 * 10000 + int_id2] = true;
		m[int_id2 * 10000 + int_id1] = true;
	}
	int K; cin >> K;
	for(int i = 0; i < K;i++)
	{
		int id1,id2; scanf("%d%d",&id1,&id2);
		for(auto i1: v[abs(id1)])
		{
			for(auto i2:v[abs(id2)])
			{
				if(m[abs(i1)*10000 + abs(i2)]&& i1 != abs(id2) && i2 != abs(id1))
				{
					p.push_back(make_pair(abs(i1),abs(i2)));
				}
			}
		}
		sort(p.begin(),p.end(),cmp);
		printf("%d\n",p.size());
		for(int j = 0; j < p.size();j++)
		{
			printf("%04d %04d\n",p[j].first,p[j].second);
		}
		p.clear();
	}
}
