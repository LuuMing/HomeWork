#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N;
	int total = 0;
	cin >> N;
	vector<int> floor(N+1);
	floor[0] = 0;
	for(int i = 1; i <= N;i++)
	{
		cin >> floor[i];
	}
	for(int i = 1; i <N+1;i++)
	{
		if(floor[i] - floor[i-1] > 0)
		{
			total += (floor[i] - floor[i-1] )* 6;
		}
		else
		{
			total += (floor[i-1] - floor[i])*4;
		}
		total += 5;
	}
	cout << total;
}
