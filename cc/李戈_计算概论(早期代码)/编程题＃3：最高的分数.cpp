#include <iostream>
using namespace std;
int main() {
   int n[100]={0};
   int s;
   cin>>s;
   for(int q=0;q<s;q++ )
{
	cin>>n[q];
	
}
    
 int t;
for(int z=0;z<s;z++){
 	if(n[z+1]>n[z]){
	
		t=n[z+1];
		
    }
    else{
    	n[z+1]=n[z];
    	t=n[z+1];
	}
	
	}
 	cout<<t<<endl;

    return 0;
}
