#include<iostream>
using namespace std;
int sum(int *,int,int);
int main()
{
int  n[100][100],a,b,c,r[100],*p1;
cin>>a;

for (int i=0;i<a;i++)
{
	cin>>b>>c;
	if(b==1||c==1)
	{
	int tem[100];
	for(int j=0;j<b*c;j++)
	{
		cin>>tem[j];
	}	
	int s=0;
	for(int k=0;k<b*c;k++)
	s=s+tem[k];
	r[i]=s;
	}
	else
	{
	p1=n[0];
	for(int j=0;j<b;j++)
	{
		for(int k=0;k<c;k++)
		{
			cin>>n[j][k];
		}
	}	
	r[i]=sum(p1,b,c);
	}
	cout<<r[i]<<endl;
}



}


int sum(int *p1,int b,int c)
{	int s;
	for(int i=0;i<b;i++)
	{	
	    s=s+*p1;
		p1++;	
	}
	p1--;
	
	for(int i=0;i<c-1;i++)
	{	p1=p1+100;
		s=s+*p1;
	}
	for(int i=0;i<b-1;i++)
	{
		p1=p1-1;
		s=s+*p1;
	}
	for(int i=0;i<c-2;i++)
	{
		p1=p1-100;
		s=s+*p1;
	}
	return s;
}
