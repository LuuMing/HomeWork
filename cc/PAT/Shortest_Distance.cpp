#include<iostream>
#define MAX 100003
using namespace std;
int dist[MAX];
int N;
int M;
int sum;
int main()
{
	cin >> N;
	for(int i = 1; i <= N;i++)
	{
		int t;
		scanf("%d",&t);
		sum += t;
		dist[i] = sum;
	}
	cin >> M;
	for(int i = 0; i < M;i++)
	{
		int a,b; cin >> a >>b;
		if(a > b)
		swap(a,b);
		printf("%d\n",min(dist[b-1]-dist[a-1],sum-(dist[b-1]-dist[a-1])));
	}
}
