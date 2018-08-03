#include<iostream>
#include<cstdio>
#include<math.h>
#include<string.h>
using namespace std;
int K;
int b[1001];
int main()
{	
	cin >> K;
	for(int i = 0; i < K;i++)
	{
		memset(b,0,1001);
		bool flag = true;
		int N; cin >> N;
		int pre; cin >> pre; b[pre]++;
		for(int j = 1; j < N;j++)
		{
			int t;
			cin >> t;
			if(abs(pre - t) <= 1)
				flag = false;
			b[t]++;
			pre = t;				
		}
		if(!flag)
		{
			cout << "NO" << endl;
			continue;
		}
		for(int j = 1; j <= N;j++)
			if(b[j]!=1)
				flag = false;
		if(flag)
			cout << "YES"<< endl;
		else
			cout << "NO"<< endl;

	}		
}