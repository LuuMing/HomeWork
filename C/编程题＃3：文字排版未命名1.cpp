#include<iostream>
using namespace std;
int main()
{
	int a;
	char n[1000][40];
	cin>>a;
	int i=0;
	char c;
	c=getchar();
	while(a>=0)
	{
	    cin.getline(*(n+i),40,' '); 
	    
		if(**(n+i)==0||**(n+i)=='\n')
		{
		
		continue;
		}
		a--;
		i++;
		c=getchar();
	}
	
	
}
