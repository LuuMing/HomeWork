#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<string> s;
int M,N,S;
int main()
{
	cin >> M >> N >> S;
	int start = 0;
	int next = S;
	bool flag = true;
	for(int i = 0; i < M; i++)
	{
		string tmp;
		cin >> tmp;
		if(++start < S)
		{
			continue;
		}
		else
		{
			if( s.count(tmp) )
			{
				start--;
			}
			else
			{
				if(start == next)
				{
					cout << tmp << endl;
					next += N;
					s.insert(tmp);
					flag = false;
				}
			}
		}
	}		
	if(flag)
		cout << "Keep going...";
}
