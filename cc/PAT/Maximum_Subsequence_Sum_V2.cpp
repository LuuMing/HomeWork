#include<iostream>
using namespace std;
int main()
{
	int N;
	int current = 0;
	int max = 0;
	cin >> N;
	for(int i = 0; i < N ;i++)
	{
		int t;
		cin >> t; 
		current += t;
		if(current > max)
		{
			max = current;
		}
		if(current < 0)
		{
			current = 0;
		}
	}
	cout << max;
}
