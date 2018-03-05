#include<iostream>
#include<iomanip>
#include<sstream>
#include<math.h>
#include<map>
using namespace std;
stringstream ss;
map<int,double> poly1,poly2,result;
int main()
{
	int a,b;
	cin >> a;
	for(int i = 0; i < a;i++)
	{
		int t;
		cin>>t;
		cin >> poly1[t];
	}
	cin >> b;
	for(int i = 0; i < b;i++)
	{
		int t;
		cin >> t;
		cin >> poly2[t];
	}
	for(auto &i:poly1)
	{
		for(auto &j:poly2)
		{
			result[i.first+j.first] += i.second*j.second;
		}
	}
	for(auto i = result.begin();i!=result.end();i++)
	{
		if(fabs(i->second) < 0.0001)
		{
			result.erase(i);
		}
	}
	ss << result.size()<<' ';
	for(auto i = result.rbegin();i!=result.rend();i++)
	{	
		if(i->second != 0.0)
		{
			ss << i->first<<' ';
			ss<<setiosflags(ios::fixed)<<setprecision(1) << i->second <<' ';		}
	}
	string s = ss.str();
	if(s[s.size()-1] == ' ')	
	s.erase(s.size()-1);
	cout << s;
}
