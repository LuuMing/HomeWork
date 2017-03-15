#include<iostream>
using namespace std;
int main(){
char a[80];
cin.getline(a,80);int n=0,n1=0,n2=0,n3=0,n4=0;
for(int i=0;i<80;i++){
		if(a[i]=='a'){n++;}
		if(a[i]=='e'){n1++;}
		if(a[i]=='i'){n2++;}
		if(a[i]=='o'){n3++;}
		if(a[i]=='u'){n4++;}
}
cout<<n<<" "<<n1<<" "<<n2<<" "<<n3<<" "<<n4;

return 0;
}
