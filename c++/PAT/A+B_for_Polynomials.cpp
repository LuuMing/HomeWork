#include<iostream>
#include<sstream>
#include<iomanip>
#include<map>
using namespace std;
int main()
{
	int K = 0;
	int N;
	double an;
	stringstream ss;
	map<int,double> poly_A;
	map<int,double> poly_B;
	cin >> K;
	for(int i = 0; i < K;i++)
	{
		cin >> N >> an;
		poly_A.insert(make_pair(N,an));
	}
	cin >>K;
	for(int i = 0; i < K;i++)
	{
		cin >> N >> an;
		poly_B.insert(make_pair(N,an));
	}
	for(auto&i:poly_A)                       
	{
		try
		{
			poly_B.at(i.first) += i.second;
		}
		catch(out_of_range)
		{
			poly_B.insert(i);
		}
	}
	for(auto i = poly_B.begin(); i!=poly_B.end();i++)
	{
		if((*i).second == 0)
		{
			poly_B.erase(i);
		}
	}
	ss << poly_B.size() <<' ';
	for(auto i = poly_B.rbegin();i!=poly_B.rend();i++)
	{
		ss <<(*i).first<<' ';
		ss<<fixed<<setprecision(1)<<(*i).second<<' '; 
	}
	string s = ss.str();
	s.erase(s.size()-1);                            //erase extra space
	cout << s;
}
