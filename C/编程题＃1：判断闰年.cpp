#include <iostream>
using namespace std;
int main(){
int n;cin>>n;int m=1;
if(n%4==0){
	if(((n%100==0)&&(n%400!=0))||(n%3200==0)){m=1;
	}else{m=0;}
}
if(m==1){cout<<'N';
}else cout<<'Y';
return 0;
}
