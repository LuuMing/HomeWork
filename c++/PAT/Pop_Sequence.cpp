#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int Max;
	int N;
	int K;
	cin >> Max >> N >> K;
	for(int i = 0; i < K;i++)
	{
		int num = 1;
		stack<int> s;
		bool flag = true;
		for(int j = 0; j < N;j++)
		{
			int t;
			cin >> t;
			for(; num <= t;num++)
				s.push(num);
			int top = s.top();
			if(t != top || s.size() > Max )
			{
				flag = false;
			}
			s.pop();
		}
		if(flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}

