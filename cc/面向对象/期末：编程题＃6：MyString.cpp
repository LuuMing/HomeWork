#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
class MyString  :public string
{
	public :
		MyString ( const char * e1 ): string (e1)
		{
			//cout<<"构造函数1"<<endl;
		};
		MyString ():string()
		{		
			//cout<<"构造函数2"<<endl;
		}; 
		MyString ( MyString & str ): string (str)
		{
	//		cout<<"构造函数3"<<endl;	
		};//拷贝构造函数 
		MyString ( const string & str) : string(str)
		{
	//	cout<<"构造函数4"<<endl;
		};//类型转换构造函数 
		MyString operator ()(int a, int b)
		{
			return this->substr(a, b); 
		};
		// /*
    /*我们发现在派生类的拷贝构造函数中的初始化列表中，基类拷贝构造函数的参数是派生类，但是
    这样子是没有关系的，编译系统会自动将派生类缩减成基类规模（这是我的个人理解，进行缩减的
    只是派生类的临时对象，不会对参数进行修改），然后传入给基类的拷贝构造函数，然后在派生类
    的拷贝构造函数当中再将派生类比基类多出的成员变量进行拷贝。   
    */ 
};
//ostream & operator << ( ostream & out, MyString &str )
//{
//	out << str;
//	return out;
//} //不用重载<< 否则string 的<<将无法使用 

int CompareString( const void * e1, const void * e2)
{
        MyString * s1 = (MyString * ) e1;
        MyString * s2 = (MyString * ) e2;
        if( * s1 < *s2 )
                 return -1;
        else if( *s1 == *s2)
                 return 0;
        else if( *s1 > *s2 )
                 return 1;
}
int main()
{
        MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
        MyString SArray[4] = {"big","me","about","take"};
        cout << "1. " << s1 << s2 << s3<< s4<< endl;
        s4 = s3;
        s3 = s1 + s3;
        cout << "2. " << s1 << endl;
        cout << "3. " << s2 << endl;
        cout << "4. " << s3 << endl;
        cout << "5. " << s4 << endl;
        cout << "6. " << s1[2] << endl;
        s2 = s1;
        s1 = "ijkl-";
        s1[2] = 'A' ;
        cout << "7. " << s2 << endl;
        cout << "8. " << s1 << endl;
        s1 += "mnop";
        cout << "9. " << s1 << endl;
        s4 = "qrst-" + s2;
        cout << "10. " << s4 << endl;
        s1 = s2 + s4 + " uvw " + "xyz";
        cout << "11. " << s1 << endl;
        qsort(SArray,4,sizeof(MyString),CompareString);
        for( int i = 0;i < 4;i ++ )
        cout << SArray[i] << endl;
        //s1的从下标0开始长度为4的子串
        cout << s1(0,4) << endl;
        //s1的从下标5开始长度为10的子串
        cout << s1(5,10) << endl;
        return 0;
}
