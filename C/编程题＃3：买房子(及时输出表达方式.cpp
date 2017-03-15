#include<iostream>
using namespace std;
int main(){
double A,K;int p=0; double N;
while(cin>>N>>K){
	int p=0,W=200;
 for(;p<20;p++){
 	 A=N*(p+1);
 	 if (A>W){;cout<<p+1<<endl;break;}
	 W=W*(1+K/100);}
	 

 	if(p==20)cout<<"Impossible"<<endl;
 } 


return 0;
}
