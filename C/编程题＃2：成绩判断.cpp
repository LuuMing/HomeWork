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
int q=0,g=0;
for(;q==k;){
	for(int p=0;p<10;p++){
		if(a[p]<a[g]){q++
		;};g++;
	}
	
}
  cout<<a[g];
  
  return 0;
}
