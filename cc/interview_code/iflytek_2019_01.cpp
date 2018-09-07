#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#define MAX 10001
using namespace std;
int score[MAX];
int main()
{
	int T,n,X;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		scanf("%d%d",&n,&X);
		int total = X * n;
		int sum = 0;
		for(int j = 0; j < n;j ++)
		{
			scanf("%d",score+j);
			sum += score[j];
		}
		sort(score,score + n);
		int idx = 0;
		while( sum < total)
		{
			sum += 100 - score[idx];
			idx ++;
		}
		cout << idx << endl;
	}
}

