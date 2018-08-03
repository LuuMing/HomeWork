#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<map>
#define INF 99999
using namespace std;
int N,M;
unordered_map<string,int> str2idx;            

struct person
{
	string ID;
	vector<int> score;
};

class mycmp     //function object, for different sort condition
{
	int i;
public:
	mycmp(int ii )
	{
		i = ii;
	}
	bool operator ()(const person & p1 ,const person & p2)
	{
		return p1.score[i] > p2.score[i];
	}
};
vector<person> p;
void ranking(vector<int>* level_, int k)    //after sorted vector p
{					    //ranking by condition k, store them to vector level_[k]
	for(int i = 0,pre = INF,rank = 1; i < N;i++)
	{
		if(p[i].score[k] < pre)     //if sore less than pre
		{
			pre = p[i].score[k];
			level_[k][str2idx[p[i].ID]] = i+1;
			rank = i+1;
		}
		else                       //if score equal to pre
		{
			level_[k][str2idx[p[i].ID]] = rank;	
		}
	}
}

int main()
{
	cin >> N >> M;
	vector<int> level_[4]; for(int i = 0; i < 4;i++) level_[i].resize(N);  //to store different 4 kind of level.
	p.resize(N);
	vector<string> query(M);
	for(int i = 0; i < N;i++)
	{
		p[i].score.resize(4);
		cin >> p[i].ID;
		scanf("%d %d %d",&p[i].score[0],&p[i].score[1],&p[i].score[2]);
		p[i].score[3] = p[i].score[0] + p[i].score[1] + p[i].score[2];
		str2idx[p[i].ID] = i;
	}
	for(int i = 0; i < M;i++)
	{
		cin >> query[i];
	}
	for(int i = 3; i >= 0 ;i--)
	{
		sort(p.begin(),p.end(),mycmp(i));           //use function object to sort.
		ranking(level_,i);                          //save the ranking result.
	}
	map<int,char> level;                                //automatically adjust best ranking result.
	for(int i = 0; i < M;i++)
	{
		if(str2idx.find(query[i]) != str2idx.end()) //person str2idx[query[i]]'s scores. use person's ID to locate its index.
		{					     //if exist, keep the value, do not update
			level[level_[3][str2idx[query[i]]]] = 'A';                                                                                  
			level[level_[0][str2idx[query[i]]]] =( level[level_[0][str2idx[query[i]]]]==0 ? 'C':level[level_[0][str2idx[query[i]]]] );
			level[level_[1][str2idx[query[i]]]] =( level[level_[1][str2idx[query[i]]]]==0 ? 'M':level[level_[1][str2idx[query[i]]]] );
			level[level_[2][str2idx[query[i]]]] =( level[level_[2][str2idx[query[i]]]]==0 ? 'E':level[level_[2][str2idx[query[i]]]] );
			cout << level.begin()->first << ' ' << level.begin()->second << endl;
			level.clear();
		}
		else
		{
			cout << "N/A" <<endl;
		}
	}	
	
}
