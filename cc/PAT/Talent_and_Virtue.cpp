#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct person
{
	int Id;
	int V;
	int T;
};
bool mycmp(const person & p1, const person& p2)
{
	if(p1.V+p1.T == p2.V+p2.T)
	{
		if(p1.V != p2.V)
		{
			return p1.V > p2.V;
		}
		else
		{
			return p1.Id < p2.Id;
		}
	}
	else
	{
		return p1.V+p1.T > p2.V+p2.T;
	}			
}
int main()
{
	int N,L,H;
	int count = 0;
	person i;
	scanf("%d%d%d",&N,&L,&H);
	vector<person> sage;
	vector<person> noblemen;
	vector<person> foolmen;
	vector<person> smallmen;
	for(int j =0; j < N;j++ )
	{
		scanf("%d %d %d",&i.Id,&i.V,&i.T);
		if(i.V < L || i.T < L)
		{
			continue;
		}
		count++;
		if( i.V >= H && i.T >=H)
		{
			sage.push_back(i);
		}else if(i.T < H && i.V >= H)
		{
			noblemen.push_back(i);
		}else if( i.T < H && i.T < H && i.V >= i.T)
		{
			foolmen.push_back(i);
		}else
		{
			smallmen.push_back(i);
		}
	}
	sort(sage.begin(),sage.end(),mycmp);
	sort(noblemen.begin(),noblemen.end(),mycmp);
	sort(foolmen.begin(),foolmen.end(),mycmp);
	sort(smallmen.begin(),smallmen.end(),mycmp);
	printf("%d\n",count);	
	for(auto &i:sage)
	{
		printf("%d %d %d\n",i.Id,i.V,i.T);
	}
	for(auto &i:noblemen)
	{
		printf("%d %d %d\n",i.Id,i.V,i.T);
	}
	for(auto &i:foolmen)
	{
		printf("%d %d %d\n",i.Id,i.V,i.T);
	}
	for(auto &i:smallmen)
	{
		printf("%d %d %d\n",i.Id,i.V,i.T);
	}
}
