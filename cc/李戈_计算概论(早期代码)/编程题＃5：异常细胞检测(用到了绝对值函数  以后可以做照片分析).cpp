#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;
int main(){
int n;cin>>n;
int a[100][100];
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cin>>a[i][j];
	}
}
int m=0;
for(int i=1;i<n;i++){
	for (int j=1;j<n;j++){
		if(abs(a[i][j]-a[i-1][j])>=50&&abs(a[i][j]-a[i+1][j])>=50&&abs(a[i][j]-a[i][j-1])>=50&&abs(a[i][j]-a[i][j+1])>=50){
			m++;
		}
	}
}
   
   cout<<m;
   
    return 0;
}
