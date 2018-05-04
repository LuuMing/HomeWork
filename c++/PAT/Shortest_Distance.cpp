#include<iostream>
#define MAX 100003
using namespace std;
int num[MAX];
int N;
int M;
int sum;
int dist(int a,int b)
{
	int right = 0;
	if(a > b)
		swap(a,b);
	for(int i = a; i<b;i++)
	{
		right += num[i];
	}
	int left = sum - right;
	return min(left,right);
}
int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		scanf("%d",&num[i]);
		sum += num[i];
	}
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		printf("%d\n",dist(a,b));
	}
}
