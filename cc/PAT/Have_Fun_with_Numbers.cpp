#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string input;
bool have[11];
bool have_2[11];
string mult(string s)
{
	string result;
	int jinwei = 0;
	int remain = 0;
	int multied = 0;
	for(int i = s.size()-1; i >=0;i--)
	{
		multied = (s[i]-'0')*2+jinwei;
		remain = multied %10;
		jinwei = multied / 10;
		result += to_string(remain);
		
	}
	if(jinwei!=0)
	{
		result += to_string(jinwei);
	}
	reverse(result.begin(),result.end());
	return result;
}
int main()
{
	cin >> input;
	for(int i = 0; i < input.size();i++)
	 have[input[i]-'0'] = true;
	string result = mult(input);
	for(int i = 0; i < result.size();i++)
	{
		have_2[result[i]-'0'] = true;
	}
	for(int i = 0; i <= 9;i++)
	{
		if(have[i] != have_2[i])
		{
			cout << "No" << endl << result;
			return 0;
		}
	}
	cout <<"Yes" << endl << result;
}
