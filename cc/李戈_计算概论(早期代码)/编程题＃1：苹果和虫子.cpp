#include <iostream>
using namespace std;
int main() {
    int x,y,n;
    cin>>n>>x>>y;
   if(y%x==0) {
   n=n-y/x;}
   else{n=n-y/x-1;
   }
    if(n<0){
    	cout<<0<<endl;
	}
	else{
	cout<<n<<endl;}
    return 0;
}
