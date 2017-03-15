#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
Complex operator=(string A)
{
	char a,b;
	int c,d;
	for(int i=0;i<10 ;i++)
	{
		if(A[i+1]=='+')
		{
			a=A[i];
			break;
		}
	}
	
	for(int i=0;i<10 ;i++)
	{
		if(A[i+1]=='i')
		{
			b=A[i];
			break;
		}
	}
	c=a-'0';
	d=b-'0';
	this->r=c;
	this->i=d;
	return *this;
}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
