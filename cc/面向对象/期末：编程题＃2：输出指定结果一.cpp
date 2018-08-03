#include <iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n): num(n) {
    }
// 在此处补充你的代码
	Number operator + (Number &t)
	{
		num = num+t.num ; 
		return *this;
	}
	int& value()
	{
		return num;
	} //主义引用在这里的作用，使得a.value() = 8成立 
};
int main() {
    Number a(2);
    Number b = a;
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a+b;
    cout << a.value() << endl;
    return 0;
}
