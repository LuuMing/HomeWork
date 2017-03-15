#include <iostream>
using namespace std;
int main() {
	int j=0,o=100;    int n=0,m=0;
    for(int i=0;i<6;i++){
	
		cin>>n;
		m=n%2;
	    switch (m){
	    	case 0 : if(n<o){o=n;
				}else{
				}
			 ; break;
			case 1:if(n>j){j=n
				;}else{
				;};break;
		} }
		if(j-o>0){cout<<j-o;
		}else{cout<<o-j;
		}
		
		 return 0;


}
