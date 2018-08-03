#include<set>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	multiset<int> set;
	multiset<int> op;
	int num, n, m, i = 0;
	string str;
	int del;
	int add;
	int ask;
	cin >> n;
	while ( n-- )
	{
		cin >> str;
		if ( str == "add")
		{
			cin >> add;
			op.insert( add );
			set.insert( add );
			m = set.count( add );
			cout << m << endl;   
		}
		else if ( str == "del")
		{
			cin >> del;
			m = set.count( del );
			set.erase( del );
			cout << m <<endl;  
		}
		else if (str == "ask")
		{
			cin >> ask;
			if( op.find( ask ) != op.end())
			{
				m = 1;
			}
			else 
				m = 0;
			if ( m == 1)
			{
				cout<< "1" <<" " << set.count(ask) <<endl; 
			}
			else if( m== 0)
			{
				cout<< "0" <<" " << set.count(ask) <<endl; 
			}

		}
	}
	return 0;
}
