#include<cstdio>
#include<map>
using namespace std;
struct node
{
	char data;
	int address;
	int next;
}; 
int main()
{
	int addr_A;
	int addr_B;
	int N;
	scanf("%d%d%d",&addr_A,&addr_B,&N);
	node * Nodes = new node[N];
	map<int,node*> string2addr;
	for(int i = 0; i < N; i++)
	{
		scanf("%d %c%d",&Nodes[i].address,&Nodes[i].data,&Nodes[i].next);
		string2addr.insert(pair<int,node*>(Nodes[i].address,&Nodes[i]));
	}
	string2addr.insert(pair<int,node*>(-1,NULL));
	node * ptra = string2addr.at(addr_A);
	node * ptrb = string2addr.at(addr_B); 
	for(; ptra!=NULL;ptra = string2addr.at(ptra->next))
	{
		ptra->data = -1; 
	}
	for(;ptrb!=NULL;ptrb = string2addr.at(ptrb->next))
	{
		if(ptrb->data==-1)
		{
			break;
		}
	}
	if(ptrb == NULL)
	{
		printf("%d",-1);
	}
	else
	{
		printf("%05d",ptrb->address);
	}
	return 0;
}
