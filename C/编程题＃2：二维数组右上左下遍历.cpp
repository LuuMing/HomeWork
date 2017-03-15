#include<iostream>
using namespace std;
int main()
{
	int n[100][100],*p,r,c,t[1000];
	cin>>r>>c;
for(int i=0;i<r*c;i++)
cin>>t[i];

for(int i=0;i<r*c;i++)
{	int tem;
	for(int j=0;j<r*c;j++)
	{
		if(t[j]>t[i])
		{
			tem=t[i];
			t[i]=t[j];
			t[j]=tem;
		}
	}
}

int x=0;
	for(int i=0;i<c;i++)
	{
		p=n[0]+i;
		for(int j=0;j<i+1;j++)
		{
			if(j>=r)
			{
				continue;
			}
			*p=t[x];
			p=p+99;
			x++;
		}
	}
		

	
			for(int i=1;i<r;i++)
			{
				p=n[i]+c-1;
				if(c>r||c==r)
				{
				for(int j=0;j<r-i;j++)
				{
					*p=t[x];
					p=p+99;
					x++;
				}
				}
				else
				{
					for(int j=0;j<r-i;j++)
				{
					if(j>c||j==c)
					{
					continue;
					}
					*p=t[x];
					p=p+99;
					x++;
				}	
					
				}
			}
		
	
	
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
		cout<<n[i][j]<<' ';
		}
		cout<<endl;
	}
	
}
