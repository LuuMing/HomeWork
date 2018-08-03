#include<iostream>
using namespace std;
int pre[1001];
struct path
{
	int start;
	int end;
};
int find(int num)
{
	if(pre[num] == num)
	{
		return num;
	}
	else
	{
		pre[num] = find(pre[num]);
		return pre[num];
	}
}
void merge(int a,int b) //!!!
{
	int set_A = find(a);
	int set_B = find(b);
	if(set_A == set_B)
	{
		return;
	}
	else
	{
		pre[set_B] = set_A;
	}
}
int N;
int M;
int K;
path p[500001];
int main()
{
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++)
	{
		cin >> p[i].start >> p[i].end;
	}
	for(int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		for(int j = 1; j <= N; j++)
		{
			pre[j] = j;
		}
		for(int k = 0; k < M; k++)
		{
			if(p[k].start != temp && p[k].end != temp)
			{
				merge(p[k].start,p[k].end);
			}
		}
		int num = 0;
		for(int i = 1; i <= N;i++)
		{
			if(pre[i] == i)
			{
				num ++;
			}
		}
		cout << num -2 << endl;
	}	
}
