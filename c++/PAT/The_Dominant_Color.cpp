#include<iostream>
#include<map>
using namespace std;

int main()
{
	int M;
	int N;
	cin >> M >> N;
	int* num = new int[M*N];
	map<int,int> database;
	for(int i = 0; i < M*N; i++)
	{
		cin >> num[i];
		database.insert(pair<int,int>(num[i],0));       //init database
	}
	for(int i = 0; i < M*N;i++)
	{
		database.at(num[i]) = database.at(num[i]) + 1;  //count objects
	}
	map<int,int>::iterator it = database.begin();
	for(auto i = database.begin(); i!=database.end();i++)
	{
		if(i->second > it->second)
		{
			it = i;					//find max
		}
	}
	cout << it->first;
}
