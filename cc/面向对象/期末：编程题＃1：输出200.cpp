//编程题＃1：输出200
//

#include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
	Number operator * (Number &n)
	{
		return num*n.num ;
	} 
	 operator int()//类型转换重载 
	{
		return num;
	}//
};

int main() {
    Number n1(10), n2(20);
    Number n3;n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
