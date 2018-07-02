#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include <string.h>
#include<cstdio>
using namespace std;
unordered_map<string,int> s2i;
unordered_map<int,string> i2s;

int main()
{
	char mars[][5] ={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	for(int i = 0; i < 26; i++)
	{
		s2i[mars[i]]= i;
		i2s[i] = mars[i];
	}
	int N; cin >> N; char c;scanf("%c",&c);
	for(int i = 0; i < N; i++)
	{
		string s; getline(cin,s);
		if(s[0]>='0'&& s[0] <= '9')
		{
			bool flag = true;
			int c = stoi(s);
			if(c ==0)
			{
				cout << "tret"; 
			}
			if(c/13 != 0)
			{
				flag = false;
				cout << i2s[c/13+12];
				c -= (c/13)*13;
			}
			if(c != 0)
			{	if(flag)
				cout <<i2s[c%13];
				else
				cout << " "<<i2s[c%13];
			}
		}
		else
		{	int c = 0;
			 char * p = strtok((char *)s.c_str(), " ");
    			while(p){
        			c += (s2i[p] >= 13)?(s2i[p]-12)*13:s2i[p];
        			p = strtok(NULL," ");
   			 }
			cout << c ;
		}
		if( i != N-1)
			cout << endl;
	}	 
}