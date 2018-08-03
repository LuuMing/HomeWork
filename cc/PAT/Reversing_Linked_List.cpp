#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int next_add[100001];
int list[100001];
int result[100001];
int main()
{
	int head;
	int N;
	int length;
	cin >> head >> N >> length;
	for(int i = 0; i < N; i++)
	{
		int cur_add;
		int data;
		int n;
		cin >> cur_add >> data >> n;
		list[cur_add] = data;
		next_add[cur_add] = n;
	}
	int times = 0;
	while(head != -1)
	{
		result[times] = head;
		head = next_add[head];
		times ++;
	}
	int i = 0;
	while(i+length <= times)
	{
		reverse(&result[i],&result[i+length]);
		i = i+length;
	}
	for( i = 0; i < times-1;i++)
	{
		printf("%05d %d %05d\n",result[i],list[result[i]],result[i+1]);
	}
	printf("%05d %d %d",result[i],list[result[i]],-1);

}

