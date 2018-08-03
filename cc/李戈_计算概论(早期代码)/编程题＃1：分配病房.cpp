#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	int a;float b;
	cin>>a>>b;
	char n[50][3];
	float m[50];
	for(int i=0;i<a;i++)
	{

	cin>>n[i][0]>>n[i][1]>>n[i][2];
	cin>>m[i];
	}
	int t[50]={-1},j=0;int count=0;
	for(int i=0;i<a;i++)
	{
		if(m[i]>=b)
		{
			t[j]=i;
			j++;
			count++;
		}
	}
	
	for(int i=0;i<count;i++)
	{	int tem;
		for(int j=0;j<count;j++)
		{
		if(m[t[i]]>m[t[j]])
			{
			tem=t[i];
			t[i]=t[j];
			t[j]=tem;	
			}
		}
	}
	if(t[0]==-1)
	{
		cout<<"None."<<endl;
	}
	else
	for(int i=0;i<count;i++)
	{
		cout<<n[t[i]][0]<<n[t[i]][1]<<n[t[i]][2]<<' '<<fixed<< setprecision(1 )<<m[t[i]]<<endl;
	}
	
}
