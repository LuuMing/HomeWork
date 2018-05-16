#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX 10010
int b[MAX];
int M, N;
bool prime(int n)
{
	if (n < 2)
		return false;
	if( n == 2) return true;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if( n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> M >> N;
	while(!prime(M)){ M++;} 
//	cout << M << endl;
	for(int i = 0; i < N; i++)
	{
		int key; cin >> key;
		bool flag = false;
		for(int j = 0; j < M; j++)
		{
			int pos = (key + j * j) % M;
			if(!b[pos])
			{
				flag = true;
				b[pos] = 1;
				cout << pos;
				break;
			}
		}
		if(!flag)
			cout << '-';
		if(i != N-1)
			cout <<' ';
	}
}
