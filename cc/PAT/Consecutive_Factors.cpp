#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<int> v;
int main() 
{
	int n; cin >> n;
	vector<int> result;
	for(int i = 2;i <= sqrt(n)+1;i++)
	{
		int j = i;
		vector<int> r;
		int nn = n;
		while(nn % j == 0)
		{
			r.push_back(j);
			nn /= j;
			j++;
		}
		if(r.size() > result.size())
			result = r;
	}
	if(result.size() == 0)
	{
		cout << 1 << endl << n;
		return 0;
	}
	cout << result.size() << endl;
	for(int i = 0; i < result.size();i++)
	{
		cout << result[i];
		if(i != result.size() - 1)
			cout << '*';
	}
}
