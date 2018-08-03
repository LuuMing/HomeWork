#include<iostream>
#include <string>
#include<stdio.h>
using namespace std;

int main()
{
	int a,b,c=0;
	char n[6];
	cin>>a>>b;
    sprintf(n, "%d", a);
	if(a%19==0)
	{ 
		for(int i=0;i<6;i++)
		{
			if((n[i]-'0')==3)
			c++;
		}
		if(c==b)
		cout<<"YES"<<endl;
		else 
		cout<<"NO"<<endl;
	}
	else
	cout<<"NO"<<endl;
	
}
