#include<iostream>
using namespace std;
int convert(int ,int );
bool check(char i);
char n[500];

int main()
{
cin.getline(n,500); 
for(int i=0,s,e;i<500;i++)
{
if(i==0&&check(n[i]))                         //特殊情况，判断第一个单词 
{
	s=0;
	for (int t=i;t<500;t++)
	{
	if(check(n[t])&&check(n[t+1])==0)
	{
	e=t;
	convert(s,e);
	i=e+1;
	break;
	}
	}
}

if(check(n[i])&&check(n[i-1])==0)
s=i;
if(check(n[i])&&check(n[i+1])==0)
{
	e=i;
	convert(s,e);	
}

}

for (int i=0;n[i]!='\0';i++)
cout<<n[i];
}







int convert(int start,int end) //翻转函数，使用递归 
{
	char temp;
	temp=n[start];
	n[start]=n[end];
	n[end]=temp;
	
	if(start>=end||start+1==end)
	return 0;
	else 
	convert(start+1,end-1);
	
}

bool check(char i)
{
	if((i>=65&&i<=90)||(i>=97&&i<=122)||i==',')
	return 1;
	else return 0;
}




