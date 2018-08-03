#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
unordered_map<string,string> d;
int main()
{
	int n;
	cin >> n;
	string account;
	string pass;
	for(int i = 0; i < n;i++)
	{
		char c; cin >> c >> account >> pass;
		if(c=='L')
		{
			if( !d.count(account))
			{
				cout << "ERROR: Not Exist" << endl;
			}
			else if (d[account] == pass)
			{
				cout << "Login: OK" << endl;
			}
			else
				cout << "ERROR: Wrong PW" << endl;
		}
		else
		{
			if(d.count(account))
			{
				cout << "ERROR: Exist" << endl;
			}
			else
			{
				d[account] = pass;
				cout << "New: OK" << endl;;
			}
		}
	}
}
