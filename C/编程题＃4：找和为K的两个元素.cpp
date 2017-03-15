#include<iostream>
using namespace std;
int main(){
int n=0;cin>>n;int k=0;
int a[n];cin>>k;
for(int i=0;i<n;i++){
	cin>>a[i];
}
int b=0,c=0;
for(;c<n;c++){
	int t=0;t=a[c];
	for(;b<n+1;b++){
		if (a[b]+t==k){ break;}
	}
	if (a[b]+t==k){ cout<<"yes"<<endl;break;}
	
	b=0;
}
if (c==n){cout<<"no"<<endl;
}

return 0;
}
