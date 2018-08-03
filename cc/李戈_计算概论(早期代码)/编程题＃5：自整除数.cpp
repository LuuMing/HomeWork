#include<iostream>
using namespace std;
int main(){
int n=0;cin>>n;int t=0,t1=0;
for(int i=10;i<n;i++)
{
	t1=i%10;t=i/10;
	if(i%(t1+t)==0){cout<<i<<endl;
	}
}
return 0;
}
