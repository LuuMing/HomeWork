#include<iostream>
#include<cstdio>
#include<vector>
#define INF 99999
using namespace std;
int N;
vector<int> nums;
int get_sum(vector<int>& dist,int s,int e)
{
	if(dist[e] != -1)
	{
		return dist[e];
	}
	else
	{
		if(s == e)
		{
			dist[e] = nums[e];
			return dist[e];
		}
		else
		{
			dist[e] = get_sum(dist,s,e-1) + nums[e];
			return dist[e];
		}
	}
}
int main()
{
	cin >> N;
	nums.resize(N);
	int neg_num = 0;
	for(int i = 0; i < N;i++)
	{
		scanf("%d",&nums[i]);
		if(nums[i] < 0)
		{
			neg_num++;
		}
	}
	if(neg_num== N)
	{
		cout << 0 << ' ' << nums[0] << ' ' << nums[N-1];
		return 0;
	}
	int max = -INF;
	int start = 0;
	int end = 0;
	for(int i = 0; i < N;i++)
	{	
		vector<int> dist(N,-1);                //weak version Dynamic Programming
		for(int j = i; j < N;j++)              //1-D vector to store sum
		{
			if(get_sum(dist,i,j) > max)
			{
				max = get_sum(dist,i,j);
				start = nums[i];
				end = nums[j];
			}
		}
	}	
	cout << max << ' ' << start <<' ' <<end;	
}
