#include<iostream>
using namespace std;
int main(){
	int first=0,last=0,n=0,t=0,tt=0,tf=0,tl=0;
	char a[500];char b[500];
	cin.getline(b,500,'.') ; 
	for(int i=0;i<500;i++){ a[i+1]=b[i];a[0]=' ';}
for(int i=0;a[i]!=0;i++){
	if(a[i]!=' '&&a[i-1]==' '){
		first=i;
	}
	if((a[i]!=' '&&a[i+1]==' ')||a[i+1]==0){
		last=i;}
		tt=last-first+1;
	if(tt>t){
		t=tt;
		tf=first;
		tl=last;
	}
}
for(;tf<tl+1;tf++){
if (a[1]!=0&&a[2]!=0)	{
cout<<a[tf];}
}
if (a[1]!=0&&a[2]==0){cout<<a[1];
}

return 0;
}
