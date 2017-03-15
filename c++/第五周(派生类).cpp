//写一个MyString 类，使得下面程序的输出结果是：
//
//1. abcd-efgh-abcd-
//
//2. abcd-
//
//3.
//
//4. abcd-efgh-
//
//5. efgh-
//
//6. c
//
//7. abcd-
//
//8. ijAl-
//
//9. ijAl-mnop
//
//10. qrst-abcd-
//
//11. abcd-qrst-abcd- uvw xyz
//
//about
//
//big
//
//me
//
//take
//
//abcd
//
//qrst-abcd-
//
//要 求：MyString类必须是从C++的标准类string类派生而来。提示1：如果将程序中所有 "MyString" 用"string" 替换，那么题目的程序中除了最后两条语句编译无法通过外，其他语句都没有问题，而且输出和前面给的结果吻合。也就是说，MyString类对 string类的功能扩充只体现在最后两条语句上面。提示2: string类有一个成员函数 string substr(int start,int length); 能够求从 start位置开始，长度为length的子串
//
//程序：
//
//    #include <iostream>
//    #include <cstring>
//    #include <cstdlib>
//    using namespace std;
//
//// 在此处补充你的代码
//
//    int CompareString( const void * e1, const void * e2) {
//        MyString * s1 = (MyString * ) e1;
//        MyString * s2 = (MyString * ) e2;
//        if( *s1 < *s2 )     return -1;
//        else if( *s1 == *s2 ) return 0;
//        else if( *s1 > *s2 ) return 1;
//    }
//    int main() {
//        MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
//        MyString SArray[4] = {"big","me","about","take"};
//        cout << "1. " << s1 << s2 << s3<< s4<< endl;
//        s4 = s3;    s3 = s1 + s3;
//        cout << "2. " << s1 << endl;
//        cout << "3. " << s2 << endl;
//        cout << "4. " << s3 << endl;
//        cout << "5. " << s4 << endl;
//        cout << "6. " << s1[2] << endl;
//        s2 = s1;    s1 = "ijkl-";
//        s1[2] = ‘A‘ ;
//        cout << "7. " << s2 << endl;
//        cout << "8. " << s1 << endl;
//        s1 += "mnop";
//        cout << "9. " << s1 << endl;
//        s4 = "qrst-" + s2;
//        cout << "10. " << s4 << endl;
//        s1 = s2 + s4 + " uvw " + "xyz";
//        cout << "11. " << s1 << endl;
//        qsort(SArray,4,sizeof(MyString), CompareString);
//        for( int i = 0;i < 4;++i )
//            cout << SArray[i] << endl;
//        //输出s1从下标0开始长度为4的子串
//        cout << s1(0,4) << endl;
//        //输出s1从下标为5开始长度为10的子串
//        cout << s1(5,10) << endl;
//        return 0;
//    }
//思路：
//
//好了这题已经成功恶心我了一整天，明天还有个魔兽的题，今晚写完了放松会儿，明天继续接受挑战。。
//
//作为一道“继承和派生”单元的作业编程题，的确是把这块知识玩到极致了，就拿这个题来说，非常全面综合的考察了对string类继承的方方面面
//
//有些部分的思路在代码中已经做了注释，还有些没说的单独拿出来说一下：
//
//关于operator+的运算符重载，首先在C++官方文档上获取到operator+的3个可能会被这题用到的重载函数
//
//string operator+ (const string& lhs, const string& rhs);//a
//string operator+ (const string& lhs, const char*   rhs);//b
//string operator+ (const char*   lhs, const string& rhs);//c
//然后我们再来看这题中出现过+的地方
//
//（1）
//
//s3 = s1 + s3;
//先不说‘=’，单看+操作符，完全可以调用父类中的a方法实现
//
//（2）
//
//s4 = "qrst-" + s2;
//同样不看‘=’，这条语句+的操作可以通过父类中c方法实现
//
//（3）
//
//s1 = s2 + s4 + " uvw " + "xyz";
//该语句可以通过b方法实现
//
//OK，既然三个操作在父类中都有相应的成员函数可以实现，我们为什么还要自己折腾去重写呢？就是因为它的返回值！在这个程序的（1）（2）（3）这三条语句中，每一个在进行完加法操作后并没有结束，而是接着进行了赋值的操作——这就是关键点，接受他们+返回值的是一个MyString类的对象，也就是一个子类，而如果我们通过父类的已有operator+去调用他们的结果，返回值是一个父类即string类的对象，而父类的对象是无法赋值到子类上去的。因此我们要重写父类中的这三个operator+，其实也只需要将他们的返回值做出相应的改变就好。
//
// 
//
//然后再说一下string类中的c_str()函数，先看下C++Reference中对它的定义
//
//const char* c_str() const noexcept;
//The pointer returned points to the internal array currently used by the string object to store the characters that conform its value.
//
//说白了就是把string中存储的内容给放到一个char数组中，然后返回这个数组的首地址，const char* 类型
//
//这里由于我们重写operator+的返回值要求是MyString类型的，所以在return的时候要构建MyString类的对象，而它的有参构造函数就只能接受const char*类型的参数，所以我们有必要做出这么一步转换。
//
// 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class MyString : public string
{
public:
    MyString() {};
    //1.0继承类继承父类所有的成员变量和成员函数，但不继承构造函数和析构函数 
    //1.1继承类的无参构造函数，会隐式调用父类的无参构造函数 
    MyString(const char * st) :string(st) {};
    //1.2继承类的有参构造函数，如果父类也有有参构造函数，则必须显示调用它 
    //2.0这里的参数根据reference有两种选择，此处必须用const char*,"xxx"的类型是const char* 
    MyString(const MyString& s):string(s){}
    //1.3继承类的复制构造函数必须要显示的调用父类的复制构造函数，不然就会默认调用父类的无参构造函数 
    MyString operator +(MyString & op2)
    {
        string s1 = *this;
        string s2 = op2;
        string s = s1 + s2;
        return *new MyString(s.c_str());
    }
    MyString & operator +(const char * cs2)
    {
        string str1 = *this;
        string s = str1 + cs2;
        return *new MyString(s.c_str());
    }
    
    MyString & operator()(int s, int l)
    {
        string str = substr(s, l);
        return *new MyString(str.c_str());
    }
};

MyString operator+(const char * op1, MyString & op2)
{
    string st2 = op2;
    string s = op1 + st2;
    return *new MyString(s.c_str());
}

int CompareString(const void * e1, const void * e2)
{
    MyString * s1 = (MyString *)e1;
    MyString * s2 = (MyString *)e2;
    if (*s1 < *s2) return -1;
    else if (*s1 == *s2) return 0;
    else if (*s1 > *s2) return 1;
}
int main()
{
    MyString s1("abcd-"), s2, s3("efgh-");
    MyString s4(s1);
    //Q1：复制构造函数是不被继承的，为什么程序里可以不写子类的复制构造函数而会默认用父类的复制构造函数？ 
    MyString SArray[4] = { "big","me","about","take" };
    //Q2：对MyString的初始化为什么必须是const char*而非const string& 
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    //3.0 operator=可以直接用string类里面的 
    s3 = s1 + s3;
    s1+s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = ‘A‘;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; ++i)
        cout << SArray[i] << endl;
    cout << s1(0, 4) << endl;
    cout << s1(5, 10) << endl;
    return 0;
}
