#include <iostream>
using namespace	 std;
int recursive(int i){
	int sum=0;
	if(i==0)return 1;
	else 
	sum=i*recursive(i-1);
	return sum;
}


int main(){
int i;
cin>>i;
cout<<recursive(i);
return 0;
}
