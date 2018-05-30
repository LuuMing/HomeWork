#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<int> s;
int N;
int M;
int v1 = 99999;
int main()
{
	cin >> N;	
	cin >> M;
	bool flag = true;
	for(int i = 0; i < N; i++)
	{
		int t; scanf("%d",&t);
		if(s.count(M-t))
		{
			flag = false;
			if(min(t,M-t) < v1)
			{
				v1 = min(t,M-t);
			}
		}
		else
		{
			s.insert(t);
		}
	}
	if(flag)
	{
		cout << "No Solution";
	}
	else
	{
		cout << v1<<' ' << M-v1;
	}

}
