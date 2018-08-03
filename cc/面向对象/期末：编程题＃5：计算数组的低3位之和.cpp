#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class CMy_add
{
	int & num; // num 在这里为引用 
	public :
	CMy_add ( int & n):num(n){};// my_sum叫做 n , n 叫做 m;  
	void operator ()(int t)
	{
		num = num + t % 8;
	}
};
int main(int argc, char* argv[]) {
        int v, my_sum=0;
        vector<int> vec;
        cin>>v;
        while ( v ) {
                vec.push_back(v);
                cin>>v;
        }
        for_each(vec.begin(), vec.end(), CMy_add(my_sum));//CMy_add(my_sum)为一个对象 
        cout<<my_sum<<endl;
        return 0;
}
