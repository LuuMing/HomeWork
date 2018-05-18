/*
	输入N,代表N组数据
	每次输入n,输出第n个素数
sample input:
2
1
2
sample output:
2
3
*/
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int prime[10001];
int N;
bool isprime(int i)
{
	if( i < 2) return false;
	if( i == 2) return true;
	for(int j = 2; j <= sqrt(i); j++)
	{
		if( i % j == 0)
			return false;
	}
	return true;
}
int main()
{
	cin >> N;
	memset(prime,-1,10001);
	int s = 1;
	prime[s] = 2;
	for(int i = 0; i < N; i++)
	{
		int n; cin >> n;
		if (prime[n] != -1)
		{
			cout << prime[n] << endl;
		}
		else
		{
			while(s != n)
			{
				for(int j = prime[s]+1; ; j++)//must plus 1
				{
					if(isprime(j))
					{
						prime[++s] = j; break;
					}
				}
			}
			cout << prime[s] << endl;
		}
	}
	return 0;
}


