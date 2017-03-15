#include<iostream>
#include<iomanip>

using namespace std;
int main(){
int n,m;cin>>n>>m;int a[1000];
for(int i=0;i<n;i++){
	cin>>a[i];
}
a[n]=0;
for(int i=0;i<m;i++){
	for(int j=n;0<j;j--){
		a[j]=a[j-1];
	}
	a[0]=a[n];
}


for (int i=0;i<n;i++){
	cout<<a[i]<<' ';
}
    return 0;
}
