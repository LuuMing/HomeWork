#include<iostream>
#include<vector>
using namespace std;
int N;
vector<pair<string,string>> account;
int main()
{
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		string temp1,temp2;
		cin >> temp1 >> temp2;
		bool flag =false;
		for(int i = 0; i < temp2.size();i++)
		{
			if(temp2[i] == '1')
			{
				temp2[i] = '@';
				flag =true;
			}
			if(temp2[i] == '0')
			{
				temp2[i] = '%';
				flag = true;
			}
			if(temp2[i] == 'l')
			{
				temp2[i] = 'L';
				flag = true;
			}
			if(temp2[i] =='O')
			{
				temp2[i] = 'o';
				flag = true;
			}
		}
		if(flag)
		{
			account.push_back(make_pair(temp1,temp2));
		}			
	}
	if(account.size() == 0)
	{
		if(N == 1)
		{
			cout <<"There is 1 account and no account is modified";
		}else
		{
			cout <<"There are "<<N<<" accounts and no account is modified";
		}
	}
	else
	{	
		cout << account.size()<<endl;
		for(auto &i:account)
		{
			cout << i.first <<' ' <<i.second<<endl; 
		}
	}
}
