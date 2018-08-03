#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int N;
int M;
int L;
int input[201];       
int order[10001] ;                                                     
int main()
{
	cin >> N;
	cin >> M;
	for(int i = 1;i  <= M;i++)
	{
		int t; scanf("%d",&t);
		input[t] = i;	
	}
	cin >> L;
	for(int i = 0; i < L; i++)
	{
		int t;
		scanf("%d",&t);
		order[i] = input[t];
	}
	vector<int> D(M+1,0);
	for(int i = 0; i < L; i++)
	{
		if(order[i] == 0)
		{
			continue;
		}
		D[order[i]]++;
		for(int j = order[i]+1; j <= M;j++)
		{
			if(D[j] < D[order[i]])
				D[j]++;
		}
	}
	cout << D[M];
}
