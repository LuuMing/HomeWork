#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> inputs(N);
	for(int i = 0; i < N;i++)
	{
		cin >> inputs[i];
	}
	sort(inputs.begin(),inputs.end());
	int output = inputs[0];
	for(int i = 0;i < N;i++)
	{
		output = (output+inputs[i])/2;
	}
	cout << output;
}
