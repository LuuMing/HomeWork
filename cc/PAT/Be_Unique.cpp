#include<iostream>
#define MAX 10001
using namespace std;
int b[MAX];
int p[10*MAX];
int main()
{
	int N;
	cin >> N;
	for(int i = 0 ;i < N; i++)
	{
		cin >> p[i];
		b[p[i]]++;
	}
	for(int i = 0; i < N; i++)
	{
		if(b[p[i]] == 1)
		{
			cout << p[i];
			return 0;
		}
	}
	cout << "None";
}
