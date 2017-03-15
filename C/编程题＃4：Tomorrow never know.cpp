#include <iostream>
using namespace std;
int jud(int);
int main(){
int y,m,d;char a,b;
cin>>y;cin>>a;cin>>m;cin>>b;cin>>d;
if(jud(y)==1){
if(m==12&&d==31){y++;m=1;d=1;}
else if((m==1||m==3||m==5||m==7||m==8||m==10)&&d==31){m++;d=1;}
else if(m==2&&d==29){m++;d=1;}
else if((m==4||m==6||m==9||m==11)&&d==30){m++;d=1;}
else{d++;}}
if(jud(y)==0){
if(m==12&&d==31){y++;m=1;d=1;}
else if((m==1||m==3||m==5||m==7||m==8||m==10)&&d==31){m++;d=1;}
else if(m==2&&d==28){m++;d=1;}
else if((m==4||m==6||m==9||m==11)&&d==30){m++;d=1;}
else{d++;}}
cout<<y<<"-";
if(m<10){cout<<"0"<<m;
}else{cout<<m;}cout<<"-";
if(d<10){cout<<"0"<<d;
}else{cout<<d;}

return 0;
}

int jud(int n){

int m=1;
if(n%4==0){
	if(((n%100==0)&&(n%400!=0))||(n%3200==0)){m=1;
	}else{m=0;}
}
if(m==1){return 0;
}else return 1;
}
