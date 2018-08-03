#include<iostream>

using namespace std;
int main(){

int n;
cin>>n;
int b=0;b=n/100;


int w1=0;
w1=n-b*100;
int w=0;
w=w1/50;



int e1=0;
e1=w1-50*w;
int e=0;
e=e1/20;



int y1=0;
y1=e1-e*20;
int y=0;
y=y1/10;

int z1=0;
z1=y1-y*10;
int z=0;z=z1/5;

int a1=0;
a1=z1-z*5;

cout<<b<<endl;
cout<<w<<endl;
cout<<e<<endl;cout<<y<<endl;cout<<z<<endl;cout<<a1<<endl;
  return 0;
}
