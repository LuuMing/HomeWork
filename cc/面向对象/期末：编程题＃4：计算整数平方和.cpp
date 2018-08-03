#include <iostream>
using namespace std;
class CType
{
	private:
		int num;
	public:
		CType ( int n ): num(n){};
		CType (){};
		void setvalue( int n )
		{ 
			num = n;
		}
		friend	ostream & operator << ( ostream & out , const CType & n);
		CType & operator ++ (int)
		{
			static CType tem = *this;
			num *= num;
			return tem;
		}
}; 
ostream & operator << ( ostream & out , const CType & n)
{
	out << n.num;
	return out;
} 

int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<< obj ++ <<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}
