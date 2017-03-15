#include<iostream>
#include<iomanip>
using namespace std;
int main(){
int n=0;double c=0,d=0,e=0,f=0;
cin>>n;
int a[n];
for (int i=0;i<n;i++){
	cin>>a[i];
	if (a[i]>=60){c++;
	}else if(a[i]>=36){d++;}

      else if(a[i]>=19){e++;}		else if(a[i]>=1){f++;}
}
 double g=0,h=0,i=0,j=0;
  g=double (f)*100/n, h=double (e)*100/n, i=double (d)*100/n,j=double (c)*100/n;
  cout << fixed << setprecision(2);
   cout<<"1-18: "<<g<<"%"<<endl;
   cout<<"19-35: "<<h<<"%"<<endl;
   cout<<"36-60: "<<i<<"%"<<endl;
   cout<<"60-: "<<j<<"%"<<endl;
   
    return 0;
}
