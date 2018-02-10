#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	int a, b;
	cin >> a >>b;
	string sum = to_string(a+b);
	stack<char> s;
	for(int i = sum.size()-1,t = 0;i != -1 ;i--,t++)
	{
		if(t % 3 == 0 && t!=0 && sum[i]>='0'&&sum[i]<='9')
		{
			s.push(',');
			s.push(sum[i]);
		}
		else
		{
			s.push(sum[i]);
		}
	}
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}
