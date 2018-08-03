#include <iostream>
using namespace std;
int main() {
    int i,a,b,c,d;
    cin>>i;
    a=i%10;
    b=(i%100-a)/10;
    c=i/100;
    cout<<c<<endl<<b<<endl<<a<<endl;
    return 0;
}
