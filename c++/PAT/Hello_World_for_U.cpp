#include<iostream>
using namespace std;
string s;
char output[100][100];
int main()
{
	cin >> s;
	int N2 = 0;
	int N1 = 0;
	for(int k = 0; k < s.size();k++)
	{
		int n2 = s.size()+2-2*k;
		if(n2 >= k && n2>=3 && n2 <= s.size())
		{
			N1 = k;
		}
	}
	N2 = s.size() +2 - 2 * N1;
	int r = 0;
	int c = 0;
	int p = 0;
	for(r = 0; r < N1;r++,p++)
	{
		output[r][0] = s[p];
	}
	for(c = 1; c < N2;c++,p++)
	{
		output[N1-1][c] = s[p];
	}
	for(r = N1-2; r>=0;r--,p++)
	{
		output[r][N2-1] = s[p];
	}
	for(int i = 0; i < N1;i++)
	{
		for(int j = 0; j < N2;j++)
			if(output[i][j] ==0)
				cout << ' ';
			else cout <<output[i][j];
		cout << endl;
	}	
}
