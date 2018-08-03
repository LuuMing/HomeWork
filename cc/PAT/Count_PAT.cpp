#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long n_P = 0, n_A = 0, n_T = 0;
	long n = 0;
	char c = 0;
	while(c != '\n')
	{
		scanf("%c",&c);
		switch(c){
		case 'P':
			n_P++;
			break;
		case 'A':
			n_A = n_A + n_P;
			break;
		case 'T':
			n = n + n_A;
                        break;
		}
	}
	cout << n%1000000007;
}
