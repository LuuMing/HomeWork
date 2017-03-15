#include <iostream>
using namespace std;
template <class T>class CArray3D
{
T ***p=NULL;
public:
CArray3D( int A,int B,int C)
{
	const int a=A,b=B,c=C;
	T***p1=(T***)new T[a];    //三维数组初始化方式 
	for(int i=0;i<a;i++)
	{
		p1[i]=(T**)new T[b];
		for(int j=0;j<c;j++)
		{
			p1[i][j]=new T[c];
		}
	}
	p=p1;	
	
}
T** operator [](int i)
{
	return p[i]; 				//重载【】运算符，重要！！！ 
}


};


int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
