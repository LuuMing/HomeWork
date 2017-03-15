#include<iostream>
using namespace std;
int main(){
	//一张饼切 n 刀，最多可以得到几块饼？ 
	int n,s=0;
	cout<<"请输入切几刀" ;
	cin>>n;
	s=(1+n)*n/2+1;
	cout<<"可以切成";
		cout<<s;
			cout<<"块饼"<<endl;
	cout<<"请按任意键退出";
	return 0;
}

