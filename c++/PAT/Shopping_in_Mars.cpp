#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int N;
int M;
int Min = 99999;
vector<pair<int,int>> v;
int chain[100001];
void output(int i ,int j)
{
	printf("%d-%d\n",i,j-1);
}
int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N;i++)
	{
		scanf("%d",& chain[i]);
	}
	int i = 1;int j = 1;
	int total = 0;
	bool flag = false;
	while(i <= N&& j <= N+1)
	{
		if(total == M)
		{
			flag = true;
			output(i,j);
			total -= chain[i];
			i++;
		}
		else if ( total < M)
		{
			total += chain[j++];
		}
		else
		{
			if(total < Min)
			{
				v.clear();
				Min = total;
				v.push_back(make_pair(i,j-1));
			}
			else if (total==Min)
			{
				v.push_back(make_pair(i,j-1));
			}
			total -= chain[i];
			i++;
		}
	}
	if(!flag)
	{
		for(auto &i: v)
		{
			printf("%d-%d\n", i.first,i.second);
		}
	}
}
