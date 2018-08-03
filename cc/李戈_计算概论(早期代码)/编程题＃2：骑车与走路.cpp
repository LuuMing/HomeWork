#include<iostream>
using namespace std;
int main(){
int n;cin>>n;
int a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
}
for(int i=0;i<n;i++){
	if(a[i]<100)cout<<"Walk"<<endl;
	else if(a[i]>100) cout<<"Bike"<<endl;
	else cout<<"All"<<endl;
}
return 0;
}
