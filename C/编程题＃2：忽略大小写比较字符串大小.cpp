#include<iostream>
using namespace std;
int main(){
char a[80],b[80];
cin.getline(b,80);
cin.getline(a,80); 
int x=0,y=0,p=0,q=0;
for(int i=0;a[i]!=0;i++){
	if(b[i]==a[i]||b[i]+32==a[i]||b[i]-32==a[i]){continue;}
	else
	{
	x=i;p=a[i];break;}
}
for(int i=0;b[i]!=0;i++){
	if(b[i]==a[i]||b[i]+32==a[i]||b[i]-32==a[i]){continue;}
	else
	{
	y=i;q=b[i];break;}
}

if (x>y){
	cout<<">";
}else if(x==y&&p>q){
	cout<<">";
}else if(x==y&&p<q){
	cout<<"<";
}else if(x==y&&p==q){
	cout<<"=";
}
else if (x<y){
cout<<">";}
return 0;
}
