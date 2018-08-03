#include<iostream>
#include<set>
using namespace std;
set<int> s;
int id[1000];
string num[10001];
int N;
int fri(string a, string b)
{
	int s_a = 0, s_b = 0;
	for(int i = 0; i < a.size();i++)
	{
		s_a += a[i]-'0';	
	}
	for(int i = 0; i < b.size() ; i++)
		s_b += b[i] - '0';
	if( s_a == s_b)
		return s_a;
	else
		return -1;
}
int main()
{
	int cnt = 0;
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		cin >> num[i];
	}
	for(int i = 0; i< N;i++)
	{
		for(int j = 0; j < N;j++)
		{
			int I = fri(num[i],num[j]);
			if( I != -1)
			{	id[I]++;
				s.insert(I);
				if(id[I] == 1)	
				cnt++;
			}
			
		}
	}
	cout << cnt << endl;
	int c = 0;
	for(auto i:s)
	{
		cout << i;
		c++;
		if( c!= cnt)
			cout << ' ';
	}
	
}
