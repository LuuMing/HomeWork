#include <iostream>
#include<iomanip>
#include<math.h>
using namespace	 std;
int main(){
int n;cin>>n;float a[100000][2];double x,y,z,q,m=0;
for(int i=1;i<n+1;i++){
cin>>a[i][1];
cin>>a[i][2];
}

for(int i=1;i<n+1;i++){
	for(int j=1;j<n+1;j++){
		x=a[i][1];y=a[j][1];z=a[i][2];q=a[j][2];
		if(sqrt((x-y)*(x-y)+(z-q)*(z-q))>m){
		m=sqrt((x-y)*(x-y)+(z-q)*(z-q));
		}
	}	
}
cout << fixed << setprecision(4) << m<< endl;
return 0;
}
