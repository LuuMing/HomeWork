#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct mice
{
	int weight;
	int rank = 5;
	int num;
};
struct mycomp
{
	bool operator ()(mice&a,mice & b)
	{
		return a.weight<b.weight;
	}
};
int main()
{
	int Np = 0;
	int Ng = 0;
	cin >> Np >> Ng;
	mice* mices = new mice[Np];
	vector<int> per;                        //参战编号 
	for(int i = 0; i < Np;i++)
	{
		cin >> mices[i].weight;
	}
	for(int i = 0; i < Np; i++)
	{
		int t;
		cin >> t;
		per.push_back(t);
		mices[i].num = i;
	}
	if(Ng == 1)
	{
		for(int i = 0; i < Np ;i++)
		{
			if(i == Np-1)
			cout<<1;
			else 
			cout<<1<<' ';
		}
		return 0;
	}
	int i = 0;
	vector<int> victory;                                          //胜利者编号 
	priority_queue<mice,vector<mice>,mycomp> combat;              //优先队列 
	while( per.size()!=1 )                                        //当参战不止一个人时一直战斗                          
	{
		while(i < per.size())                                     //找出所有胜利者 
		{
			while(i < per.size()&& combat.size() != Ng) 
			{
				combat.push(mices[per[i]]);
				i++;                                
			}
			victory.push_back(combat.top().num);                  //优先队列，队顶为胜利者 
			combat = priority_queue<mice,vector<mice>,mycomp>();  //清空 
		}
		for(auto&i:per)                                          //对于所有失败者(all player not in victory) 
		{
			if(find(victory.begin(),victory.end(),i)==victory.end())
			{
				mices[i].rank = victory.size() + 1;              //失败者等级为胜利人数+1  (rank of lost is the size of victory plus one.) 
			}
		}
		per.clear();
		for(auto&i:victory)
		{	
			per.push_back(i);                                    //胜利者继续参战 
		}
		victory.clear();
		i = 0; 
	}
	mices[*(victory.begin())].rank = 1;                          //没有对手时就成了第一 
	for(int i = 0;i < Np;i++)
	{
		if( i!= Np-1)
		cout << mices[i].rank << ' ';
		else
		cout << mices[i].rank;
	}
	return 0;
} 


