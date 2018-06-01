#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int add;
	int key;
	int next = -1;
};
bool cmp(const node & n1,const node & n2)
{
	return n1.key < n2.key;
}
vector<node> v;
node nodes[100020];
int main()
{
	int N,root;	cin >> N >> root;
	for(int i = 0 ; i < N;i++)
	{
		int a,k,n;
		scanf("%d%d%d",&a,&k,&n);
		nodes[a].add = a;
		nodes[a].key = k;
		nodes[a].next = n;
	}
	while(root != -1)
	{
		v.push_back(nodes[root]);
		root = nodes[root].next;
	}
	sort(v.begin(),v.end(),cmp);
	if(v.size()!=0)
	{
		printf("%d %05d\n",v.size(),v[0].add);
		for(int i = 0; i < v.size()-1; i++)
		{
			v[i].next = v[i+1].add;
			printf("%05d %d %05d\n",v[i].add,v[i].key,v[i].next);
		}
		printf("%05d %d -1",v[v.size()-1].add,v[v.size()-1].key);
	}
	else
	{
		cout << "0 -1";
	}
}

