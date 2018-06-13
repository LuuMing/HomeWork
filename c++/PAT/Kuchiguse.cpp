#include<iostream>
#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
string s[101];
string suffix;
int main()
{
	int N;
	cin >> N;
	getline(cin,s[0]);
	for(int i = 0; i < N; i++)
	{
		getline(cin,s[i]);
		reverse(s[i].begin(),s[i].end());
	}
	int j = 0;
	while(true)
	{
		int i = 1;
		bool flag = true;
		for(; i < N;i++)
		{
			if(s[i][j] != s[i-1][j])
			{
				flag = false;
				break;
			}
		}
		if (flag){
			suffix += s[0][j];
			j++;
		}
		else
			break;
	}
	if(suffix.size() == 0)
		cout << "nai";
	else
	{
		reverse(suffix.begin(),suffix.end());
		cout << suffix;
	}
}
