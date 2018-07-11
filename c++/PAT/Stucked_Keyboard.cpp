#include<cstdio>
#include<iostream>
using namespace std;
int times[256];
int stucked[256];
int s[256];
int main()
{
	string input; int k;
	cin >> k;getchar();
	getline(cin,input);
	char pre = '#';
	input+= pre;
	for(int i = 0; i < input.size();i++)
	{
		if(input[i] == pre)
			times[input[i]]++;
		else
			times[input[i]] = 1;
		pre = input[i];
	}
	for(int i = 0; i < input.size();i++)
	{
		if( times[input[i]] % k == 0  && times[input[i]] != 0 )
		{
			stucked[input[i]] = 1;
		}
	}
	for(int i = 0; i < input.size();i++)
	{
		if(stucked[input[i]]==1  )
		{
			cout << input[i];
			stucked[input[i]] = -1;
		}
	}
	cout << endl;
	for(int i = 0; i < input.size() ;i++)
	{
		if(input[i] == '#')
		break;
		if( stucked[input[i]]==-1)
		{
			cout << input[i];
			i += k-1;
			continue;
		}
		else
			cout << input[i];
	}
}
