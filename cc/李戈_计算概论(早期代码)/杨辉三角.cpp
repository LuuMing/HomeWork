// ×÷ÒµÎå.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<cstring>
#include<math.h>
#include<iomanip>
using namespace std;

void paint(int n)
{
	unsigned int i,j,k;
	unsigned int b,c;
	for(i=0;i<n;i++)
	{
		for(j=n;j>i;j--)
			cout<<" ";
		for(j=0;j<=i;j++)
		{
			b=c=1;
			if(j>=1)
			{
				for(k=i-j+1;k<=i;k++)
					b*=k;
				for(k=1;k<=j;k++)
					c*=k;
			}
			cout<<b/c<<" ";
		}
		cout<<endl;
	}
}
int main(int argc, char* argv[])
{
	int n;
	cin>>n;
	paint(n);
	return 0;
}
