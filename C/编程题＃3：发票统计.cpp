#include <iostream>
#include <iomanip>
using namespace std;
int moneycount(int);
int main() {
int id=0;int n=0;char t;float m[4]={0,0,0,0};float at=0,bt=0,ct=0;
for(int i=0;i<3;i++){
cin>>id;
cin>>n;float a=0,b=0,c=0;
for(int i=0;i<n;i++){
	float tem=0; cin>>t;cin>>tem;
	if(t=='A'){ a=a+tem;}
	if(t=='B'){ b=b+tem;}
	if(t=='C'){ c=c+tem;}
	m[id]=m[id]+tem;
}
at=at+a;bt=bt+b;ct=ct+c;
}
cout<<"1 "; cout<<setiosflags(ios::fixed)<<setprecision(2)<<m[1]<<endl;
cout<<"2 ";cout<<setiosflags(ios::fixed)<<setprecision(2) <<m[2]<<endl;
cout<<"3 ";cout<<setiosflags(ios::fixed)<<setprecision(2) <<m[3]<<endl;
cout<<"A ";cout<<setiosflags(ios::fixed)<<setprecision(2) <<at<<endl;
cout<<"B ";cout<<setiosflags(ios::fixed)<<setprecision(2)<<bt<<endl;
cout<<"C ";cout<<setiosflags(ios::fixed)<<setprecision(2) <<ct<<endl;

    return 0;
}


