#include<iostream>
#include<unordered_set>
using namespace std;
int chartimes[256];
int main()
{
	string 	origin,typeout;
	cin >> origin >> typeout;
	int i = 0, j = 0;
	while(i < origin.size() && j <typeout.size())
	{
		if(origin[i] != typeout[j])
		{
			char c = toupper(origin[i]);
			chartimes[c]++;
			if(chartimes[c] == 1)
				cout << c;
			i++;
		}
		else
		{
			i++,j++;
		}
	}
	for(;i < origin.size(); i++)
	{
		char c = toupper(origin[i]);
		chartimes[c]++;
		if(chartimes[c] == 1)
				cout << c;
	}
}