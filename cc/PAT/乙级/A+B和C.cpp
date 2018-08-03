#include<iostream>
#include<algorithm>
using namespace std;
long a,b,c;
int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		cin >> a >> b >> c;
		cout << "Case #"<<i+1<<':';
		if(a+b > c)
		{
			cout <<" true" << endl;
		}
		else
		{
			cout << " false" << endl;
		}
	}
}
