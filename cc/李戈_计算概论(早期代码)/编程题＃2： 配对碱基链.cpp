#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	char m,r[1000][256];
	cin>>n;
	char c;
	c=getchar();
	for(int i=0;i<n;i++)
	{
		int j=0;
		m=getchar();
		while(m!='\n')
		{
			if(m=='A')
			r[i][j]='T';
			else if(m=='T')
			r[i][j]='A';
			else if(m=='C')
			r[i][j]='G';
			else if(m=='G')
			r[i][j]='C';
			j++;
			m=getchar();
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<r[i]<<endl;
	}
}
