#include<iostream>
using namespace std;
int main()
{
	string D; int N;
	cin >> D >> N;
	while(N-1)
	{
		string result;
		char c = D[0];
		int cnt = 0;
		for(int i = 0; i < D.size(); i++)
		{
			if(D[i] == c)
				cnt++;
			else
			{
				result.push_back(c);
				result += to_string(cnt);
				cnt = 1;
				c = D[i];
			}
		}
		if(cnt > 0)
		{
			result.push_back(c);
			result += to_string(cnt);
		}
		D = result;
		N--;
	}
	cout << D;
}
