#include <iostream>
#include<iomanip>
#include<math.h>
using namespace	 std;
int main(){
int a;int b;char c;
cin>>a>>b>>c;
if(c=='+'){cout<<a+b;
}
if(c=='-'){cout<<a-b;
}
if(c=='*'){cout<<a*b;
}
if(c=='/'&&b==0){cout<<"Divided by zero!";
}
if(c=='/'&&b!=0){cout<<a/b;
}
if(c!='+'&&c!='-'&&c!='*'&&c!='/'){cout<<"Invalid operator!";
}

return 0;
}
