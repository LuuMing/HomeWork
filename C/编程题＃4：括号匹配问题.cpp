#include<iostream>
using namespace std;
char n[110];
int m[110]={0};
int change(int);
int main()
{
	
	while (cin.getline(n,110))
	 { 
     
    
	
	for (int i=99;i>=0;i--)
	{
		if(n[i]=='(')
		{
			if(change(i+1))
			m[i]=1;
		}
	}        //找出左半边括号的位置  调用函数,若成功匹配则在m相应位置标记1 
	
	
	for(int i=0;n[i]!='\0';i++)
	cout<<n[i];
	cout<<endl;	
	for(int i=0;n[i]!='\0';i++)
	{

		if(n[i]=='('&&m[i]==0)
		{
			cout<<'$';
			continue;
		}

		else if(n[i]==')'&&m[i]==0)
		{
			cout<<'?';
			continue;
		}
		cout<<' ';

	}
	cout<<endl;
	for (int i=0;i<110;i++)
	m[i]=0;
}
}


int change(int i)
{
	if(n[i]==')'&&m[i]!=1)
	{
	m[i]=1;
	}
	else if(i==99)
	{
		return 0;
	}
	else change(i+1);
}
