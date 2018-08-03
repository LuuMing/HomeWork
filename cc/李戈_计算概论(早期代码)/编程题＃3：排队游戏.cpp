#include<iostream>
using namespace std;
char n[100];
int match(int i);
int main()
{
		cin.getline(n,100);
	for(int i=0;i<100;i++)
	{
		if(n[i]!=n[0]&&n[i]!=0)
		{
		match(i);	
		cout<<' '<<i<<endl;
		}
	}
}

int match(int i)
{
	
		if(i-1==0)
		{
		cout<<0;
		return 0;
		}
else if(n[i-1]==n[0])
{
cout<<i-1;
n[i-1]=0;
}
else 
match(i-1);		
}
