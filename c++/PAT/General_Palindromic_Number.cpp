#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N,b;
	cin >> N >> b;
	vector<int> r;
	int n = N;
	int result = 0;
	while(n)           //to radix, and radix to num
	{
		r.push_back(n%b);
		result = result*b + n%b;
		n/= b;
	}
	if(r.size()==0)
	{
		r.push_back(0);
	}
	if(result == N)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	for(int i = r.size()-1; i >= 0;i--)
	{
		if(i == 0)
		{
			cout << r[i];
		}
		else
			cout << r[i] << ' ';
	}
}
