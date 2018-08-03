#include<iostream>
#include<cstdio>
using namespace std;
string input;
char to_itoc(int n)
{
	if(n <=9 )
		return n+'0';
	else 
	{
		return 	n-10+'A';
	}
}
int main()
{
	cout <<'#';
	for(int i = 0; i < 3;i++)
	{
		int c;
		cin >> c;
	
		printf("%c%c",to_itoc(c/13),to_itoc(c%13));
	}
}

