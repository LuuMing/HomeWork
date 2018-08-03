#include<iostream>
#include<string.h>
using namespace std;
class student
{
	private:
		char name[10];
		int age;
		char num[10];
		int A;
		int B;
		int C;
		int D;
	public:
		void setname(char *p)
		{
			strcpy(name,p);
		}
		void setage(int x)
		{
		age=x;	
		}
		void setnum(char *p)
		{
			strcpy(num,p);
		}
		void set(int a,int b,int c,int d)
		{
			A=a;
			B=b;
			C=c;
			D=d;
		}
		int aver()
		{
			return (A+B+C+D)/4;
		}
		void putname()
		{
			cout<<name;
		}
		void putage()
		{
			cout<<age;
		}
		void putnum()
		{
			cout<<num;
		}

};
int main()
{
char name[10],num[10];int age,a,b,c,d;
char tem;
cin.getline(name,10,',');
cin>>age>>tem;
cin.getline(num,10,',');
cin>>a>>tem>>b>>tem>>c>>tem>>d;
  
student A;
A.setname(name);
A.setnum(num);  
A.setage(age); 
A.set(a,b,c,d);
A.putname();cout<<',';A.putage();cout<<',';A.putnum() ;cout<<','<<A.aver() ; 
	
}
