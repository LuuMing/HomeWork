#include <iostream> 
#include <iterator> 
#include <set> 
//样例输入
//
//无
// 
//
//样例输出
//
//1 2 6 7 8 9
using namespace std;
int main() { 
    int a[] = {8,7,8,9,6,2,1}; 
    set<int> v(a, a+7);

    ostream_iterator<int> o(cout," ");
    copy( v.begin(),v.end(),o); 
    return 0;
}
