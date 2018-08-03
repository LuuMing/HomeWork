#include<iostream>
#include<unordered_map>
#include<math.h>
#include<cstdio>
using namespace std;
unordered_map<int,string> m;
int check[10001];
bool prime(int n)
{
	if( n == 1) return false;
	if( n == 2) return true;
	for(int i = 2; i <= sqrt(n); i++)
	{
		if( n % i ==0)
			return false;
	}
	return true;
}
int main()
{
	int N;
	cin >> N ;
	int id;
	cin >> id;
	m[id] ="Mystery Award";	
	for(int i = 2; i <= N;i++)
	{
		cin >> id;
		if(prime(i))
		{
			m[id] = "Minion";	
		}
		else
		{
			m[id] = "Chocolate";
		}
	}
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		cin >>  id;
		printf("%04d: ",id);
		if(m.count(id))
		{
		
			if(!check[id])
			{
				cout << m[id];
				check[id] = 1;
			}
			else
			{
				cout << "Checked";	
			}
		}
		else
		{
			cout << "Are you kidding?";			
		}			
		if( i != N -1)
			cout << endl;
	}
}