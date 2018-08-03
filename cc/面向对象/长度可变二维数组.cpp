#include <iostream>
#include <cstring>
using namespace std;
class Array2{
	private:
	int hang,lie;
	int **p=NULL;	
	public:
	Array2(int a,int b)
	{
		hang=a;
		lie=b;
	int **array=new int*[a];
	for(int i=0;i<b;i++)
	{
		array[i]=new int [b];
	}
	p=array;
	
	}
	Array2()
	{
	hang=0;lie=0;
	}
	
	int *operator[](int i)
	{
		return p[i];		
	}
	int &operator ()(int i,int j)
	{
		return p[i][j];
	}
	Array2 operator =(const Array2 &A)
	{
		
		hang=A.hang;
		lie=A.lie;
	
	 p=new int*[hang];
	for(int i=0;i<lie;i++)
	{
		p[i]=new int [lie];
	}
	for(int i=0;i<hang;i++)
	{
		for (int j=0;j<lie;j++)
		{
			p[i][j]=A.p[i][j];
		}
	}
	return *this;
	}
	
	};
int main() {
    Array2 a(3,4);
    int i,j;
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
	
	 b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    
    return 0;
}
