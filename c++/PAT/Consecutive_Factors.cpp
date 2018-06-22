#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<int> v;
int main() 
{
	int n; cin >> n;
	for(int i = 2;i <= sqrt(n)+1;i++)
	{
		if(n % i == 0)
		v.push_back(i);
	}	
	for(int i = 0; i < v.size();i++)
		cout << v[i] << endl;
	vector<int> result;
	for(int i  = 0; i < v.size();i++)
	{
		vector<int> vv;
		vv.push_back(v[i]);
		for(int j = i+1; j < v.size();j++)
		{
			if(v[j] - v[j-1] == 1)
			{
				vv.push_back(v[j]);			
			}
			else
			{
				break;
			}		
		}
		if(vv.size() > result.size())
			result = vv;
	}
	if(result.size()==0)
	{
		cout << 1 << endl;
		cout << n;
	}
	else
	{
		cout << result.size()<<endl;
		for(int i = 0; i < result.size();i++)
		{
			cout << result[i];
			if(i!=result.size()-1)
			cout << '*';
		}
	}
}