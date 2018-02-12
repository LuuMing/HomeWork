#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>
using namespace std;
vector<int> chain;
vector<int> length;     //Dynamic programming
int get_length(int i )
{
	if(length[i]!=-1)         //if length[i] be caculated, return it.
	{
		return length[i];
	}	
	if(chain[i]==-1)          //if root, length will be zero.
	{
		length[i] = 0;
		return length[i];
	}
	else                     
	{
		length[i] = get_length(chain[i]) + 1;
		return length[i];
	}
}
int main()
{
	int N = 0;
	double init_price = 0;           //use double, it will store longer than float.
	double rate = 0;               
	int max = 0;
	int count = 0;
	cin >> N >> init_price >> rate;
	chain.resize(N);
	length.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> chain[i];
		length[i] = -1;
	}
	for(int i = 0; i < N; i++)
	{
		if(get_length(i)>max)
		{
			max = get_length(i);
		}	
	}
	for(int i = 0; i < N;i++)
	{
		if(length[i]== max)
		{
			count++;
		}
	}
	cout<<fixed<<setprecision(2)<< init_price*pow((1.0+(rate/100.0)),max)<<' ';
	cout<<count;
}


