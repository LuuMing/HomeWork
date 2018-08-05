#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100200
struct node
{
	int address;
	int data;
	int next = -1;
};
node n[MAX];
vector<node> list;
vector<node> result1,result2,result3;
int S,N,K;
int main()
{
	cin >> S >> N >> K;
	for(int i = 0; i < N;i++)
	{
		int addr,data,next;
		scanf("%d%d%d",&addr,&data,&next);
		n[addr].address = addr;
		n[addr].data= data;
		n[addr].next = next;
	}
	for(;S != -1; S = n[S].next)
	{
		list.push_back(n[S]);
	}
	for(int i = 0; i < list.size(); i++)
	{
		if(list[i].data < 0)
		{
			result1.push_back(list[i]);
		}
		else
		{
			if(list[i].data <= K)
				result2.push_back(list[i]);
			else
				result3.push_back(list[i]);
		}
	}
	result1.insert(result1.end(),result2.begin(),result2.end());
	result1.insert(result1.end(),result3.begin(),result3.end());
	for(int i = 0 ; i < result1.size()-1 ;i++)
	{
		printf("%05d %d %05d\n",result1[i].address,result1[i].data,result1[i+1].address);
	}
	printf("%05d %d -1",result1.back().address,result1.back().data);
}
