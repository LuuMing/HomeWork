#include<iostream>
using namespace std;
int main()
{
	int x[101],y[101];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>x[i]>>y[i];
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(x[i]>max)
		max=x[i];
	}
	
	for(int i=0;i<101;i++)
	{
		int t=-1;
		int j=0;
		for(;j<n;j++)
		{	
			if(x[j]==i)
			{	
				if(y[j]>t)
				t=y[j];
			}
		}
		if(t==-1)
		{
			continue;
		}
		else if(i==max)
		{
			cout<<'('<<i<<','<<t<<')';
		}
		else 
		{
			cout<<'('<<i<<','<<t<<')'<<',';
		}
	}
}
