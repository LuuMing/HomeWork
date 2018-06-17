#include<iostream>
#include<vector>
#include<cctype>
#include<unordered_map>
using namespace std;
unordered_map<string,int> m;
int main()
{
	string input;
	getline(cin,input);
	int s = 0;
	int e = 0;
	string word;
	while( s < input.size() && e < input.size())
	{
		if( isalpha(input[e]))
		{
			e++;
		}
		else
		{
			bool flag = true;
			for(int i = s; i <= e;i++)
			{
				if( isalpha(input[i]))
				{
					word += tolower(input[i]);		
				}
				else if (isdigit(input[i]))
				{
					word += input[i];
				}
				else
					break;

			}
			if(flag && word !="")
			{
				m[word] += 1;
			}
			word = "";
			s = e = e + 1;
		}			
	}
	m[""] = 0;
	string best = "";
	for(auto s:m)
	{
		if(s.second > m[best])
		{
			best = s.first;
		}
		else if (s.second == m[best])
		{
			if(s.first < best)
				best = s.first;			
		}
	}
	cout << best <<  ' ' << m[best];
}

