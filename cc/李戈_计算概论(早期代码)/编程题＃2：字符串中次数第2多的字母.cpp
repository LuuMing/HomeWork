#include<iostream>
using namespace std;
bool check(char n);
int count[26]={0};
bool sort(char n);
int ctn(char n);
int main()
{
	char n[500]={0},db1[26],db2[26];int count2[26]={0};
	for(int i=0;i<26;i++)
	{
		db1[i]='a'+i;
		db2[i]='A'+i;
	}
	
	cin.getline(n,500);
	for(int i=0;i<500;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(n[i]==db1[j]||n[i]==db2[j])
			count[j]++;
		}
	}
	for(int i=0, x=0;i<26;i++)
	{	int t=0;
		for(int j=0;j<26;j++)
		{
			if(count[i]>=count[j])
			t++;
		}
		
		if(t==26)
		{
		count2[x]=i;
		x++;
		}
	}
	for(int i=0;i<26;i++)
	{
		count[count2[i]]=0;
	}
	
	
int r;
	for(int i=0;i<500;i++)
	{
		if(check(n[i]))
		{
			if(sort(n[i])){
			
			r=ctn(n[i]);
			break;
			}				
		}
	}

	cout<<db2[r]<<'+'<<db1[r]<<':'<<count[r];
}


bool check(char n)

{
	if(n>='a'&&n<='z'||n>='A'&&n<='Z')
	return 1;
}


bool sort(char n)
{	int t=0;
	for(int i=0;i<26;i++)
	{
		
		if(count[ctn(n)]>=count[i])
		{
		t++;
		}
		if(t==26)
		{
		return 1;
		}
		
	}
	return 0;
}

int ctn(char n)
{
	if(n>='a'&&n<='z')
	return n-'a';
	if(n>='A'&&n<='Z')
	return n-'A';
}
