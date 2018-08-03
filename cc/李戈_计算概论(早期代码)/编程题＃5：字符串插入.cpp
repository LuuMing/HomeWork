#include <iostream>

using namespace	 std;
int main(){
char a[10]={" "},b[3];char d[1];
while(cin.getline(a,10,' '), 
cin.getline(b,4)) {

int n=0;for(int i=0;a[i]!=0;i++){n++;
}

char q=0;int z=0;
for(int i=0;i<n;i++){
	if(a[i]>q){
		q=a[i];z=i;
	}
}
int zz;zz=n;
for(;z+1<n;n--){a[n+2]=a[n-1];
	
}a[z+1]=b[0];
a[z+2]=b[1];
a[z+3]=b[2];

for(int i=0;i<zz+3;i++){cout<<a[i];
}cout<<endl;

}
return 0;
}
