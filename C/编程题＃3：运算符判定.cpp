#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	char d;
	cin>>a>>d>>b>>d>>c;
	if(a+b==c)
	cout<<'+';
	else if(a-b==c)
	cout<<'-';
	else if(a*b==c)
	cout<<'*';
	else if(a/b==c)
	cout<<'/';
	else if(a%b==c)
	cout<<'%';
	else 
	cout<<"error"; 
}
