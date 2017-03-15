#include<iostream>

using namespace std;
int main(){
int n=0,k=0;
cin>>n;
cin>>k;
int a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
}
int x=0,y=0,z=0;
for (;;){
	for(int v=0;v<n;v++)
	{if(a[z]>a[v])
	{x=x+1;}

	}if(x==n-k){
		break;
	}else {x=0;}z=z+1;
}
  cout<<a[z];
 
  return 0;
}
