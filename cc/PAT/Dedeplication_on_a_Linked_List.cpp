#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#include<set>
using namespace std;
#define MAX 100100
set<int> s;
struct node
{
	int id;
	int data;
	int next = -1;
};
node n[MAX];
vector<node> v,v1,v2;
int N;
int main()
{
	int head = 0;
	cin >> head >> N;
	for(int i = 0; i < N; i++)
	{
		int id,d,next;
		scanf("%d%d%d",&id,&d,&next);
		n[id].id = id;
		n[id].data = d;
		n[id].next = next;
	}
	int p = head;
	while( p != -1)
	{
		int tmp = abs(n[p].data);
		if(s.count(tmp)==0)
		{
			v1.push_back(n[p]);
			s.insert(abs(n[p].data));
		}
		else
		{
			v2.push_back(n[p]);
		}
		p = n[p].next;
	}
	for(int i = 0; i < v1.size()-1;i++)
	{
		printf("%05d %d %05d\n",v1[i].id,v1[i].data,v1[i+1].id);
	}
	if(v1.size() > 0)
	{
		printf("%05d %d -1\n",v1.back().id,v1.back().data);
	}
	for(int i = 0; i < v2.size()-1;i++)
	{
		printf("%05d %d %05d\n",v2[i].id,v2[i].data,v2[i+1].id);
	}
	if(v2.size() > 0)
	{
		printf("%05d %d -1",v2.back().id,v2.back().data);
	}
	
}
