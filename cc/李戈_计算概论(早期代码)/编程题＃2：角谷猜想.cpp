#include<iostream>
using namespace std;
int jiaogu(int );
int main()
{
	int n;
	cin>>n;
	jiaogu(n);
} 


int jiaogu(int n)
{
	if (n%2==0)
	{
	cout<<n<<'/'<<2<<'='<<n/2<<endl;
	return jiaogu(n/2);
	}
	if(n%2!=0&&n!=1)
	{
	cout<<n<<'*'<<3<<'+'<<1<<'='<<n*3+1<<endl;
	return jiaogu(n*3+1);
	}
	if(n==1)
	{
	cout<<"End";
	return 0;	
	}
}

