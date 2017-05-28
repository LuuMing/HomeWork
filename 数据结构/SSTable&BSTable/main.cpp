#include <iostream>
#include"SSTable.h"
#include "BSTable.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	cout<<"--------------------------SSTable 测试--------------------------"<<endl; 
	SSTable<int> s1(5);   //类型与大小可变化 
	int target;
	cout << "请输入待查找元素:"; 
	cin >> target;
    s1.Search_Seq(target);	
	cout<< "--------------------------BSTable 测试--------------------------"<<endl;
	BSTable<int> s2(5);    //类型与大小可变化
	cout << "请输入待查找元素:"; 
	cin >> target;
	cout<<"顺序查找："<<endl; 
    s2.Search_Seq( target );  //s2继承父类的 Search_Seq
    cout<<"折半查找："<<endl;
    s2.Search_Bia( target );  
	
	return 0;
}
