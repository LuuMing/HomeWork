#include<iostream>


using namespace std;
int main(){
int n=0;int c[15000];	int m0=0,m1=0,m2=0,m3=0;int p=0;
for (int u=0;cin>>n,n!=0;u++){


	int a[15000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]>a[j]){m1++;}
		}	if(m1==(n-1)/2){m2=a[i];}
		m1=0;
		for(int j=0;j<n;j++){
			if(a[i]<a[j]){m0++;
			}
		}	if(m0==(n-1)/2){m3=a[i];}
		m1=0;
		m0=0;  	}
		
		c[u]=(m2+m3)/2;
		p++;
		}
for(int a=0;a<p;a++){
			cout<<c[a]<<endl;}
    return 0;}
