#include <iostream>

using namespace	 std;
int main(){
int n;cin>>n;int a[10000];
for(int i=0;i<n;i++){
	cin>>a[i];
}
for (int i=0;i<n;i++){
	if(i==a[i]){cout<<a[i];break;
	}
	if(i==n-1){cout<<"N";
	}
}

return 0;
}
