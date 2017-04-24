#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
class A
{	public:
	int age;
	string name = "A";

		A (int a):age(a)
		{
		};
		A (int a , string str):age(a), name(str)
		{
		};
	}; 
	class B:public A
	{
		public:B (int a):A(a,"B"){};
	};
	struct Comp
	{
	  bool operator()(const A *p1, const A *p2)const
	  {
	  	return (p1->age < p2->age);
	  }
	};//自定义比较方法 
	void Print(A *p)
	{
		cout << p->name <<' ' << p->age << endl;
	}
int main()
{

        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)	{
                        char c; int k;
                        cin >> c >> k;

                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}
