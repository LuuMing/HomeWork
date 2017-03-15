#include <iostream>
using namespace std;
int main(){
int n;cin>>n;	double a[100][2],b[100][2];
for(int i=0;i<n;i++){
	double c=0,d=0;
	cin>>a[i][0]>>c>>d;
	a[i][1]=(d-c)/c;
}
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		if(a[i][1]>a[j][1]){
			b[i][0]=a[i][0];
			b[i][1]=a[i][1];
			a[i][0]=a[j][0];
			a[i][1]=a[j][1];
			a[j][0]=b[i][0];
			a[j][1]=b[i][1];
			
		}
	}
	
}
int q=0;
for(;;q++){
if(a[0][1]-a[q][1]<a[q][1]-a[q+1][1] && a[q+1][1]-a[n][1]<a[q][1]-a[q+1][1]){
	break;
}	
}
cout<<q+1<<endl;
int t;t=q;


for(;t>=0;t--){
	cout<<a[t][0]<<endl;
}
cout<<n-q-1<<endl;


for(;n-1-q>0;){
	cout<<a[n-1][0]<<endl;
	n=n-1;
}

return 0;
}
