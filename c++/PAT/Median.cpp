#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
	int N1,N2;
	cin >> N1;
	vector<long int> s;
	for(int i = 0; i < N1;i++)
	{
		long int t;
		scanf("%ld",&t);
		s.push_back(t);
	}
	cin >> N2;
	for(int i = 0; i < N2;i++)
	{
		long int t;
		scanf("%ld",&t);
		s.push_back(t);
	}
	sort(s.begin(),s.end());
	cout << s[(s.size()-1)/2];
}
