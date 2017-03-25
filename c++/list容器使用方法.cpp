#include<list>
#include<iostream>
#include<algorithm>
using namespace std;
class A
{
	
	private:
		int n;
	public:
		A(int n_)
		{
			n=n_;
		} 
	friend bool operator <(const A& a1,const A & a2);
	friend bool operator ==(const A& a1,const A&a2);
	friend ostream &operator<<(ostream &o,const A&a);	
}; 
bool operator <(const A& a1,const A& a2)
{
	return a1.n<a2.n;
}
bool operator ==(const A& a1,const A& a2)
{
	return a1.n==a2.n;
}
ostream &operator <<(ostream &o,const A &a)
{
	o<<a.n;
	return o;
}

template <class T>
void PrintList(const list<T>&lst)
{
	int tmp=lst.size();
	if(tmp>0)
	{
		typename list<T>::const_iterator i;
		i=lst.begin();
		for(i=lst.begin();i!=lst.end();i++)
			cout<<*i<<",";
	}
}
int main()
{
	list<A>lst1,lst2;
	lst1.push_back(1);
	lst1.push_back(3);
	lst1.push_back(2);
	lst1.push_back(4);
	lst1.push_back(2);
	lst2.push_back(10);
	lst2.push_front(20);
	lst2.push_back(30);
	lst2.push_back(30);
	lst2.push_front(40);
	lst2.push_back(40);
	cout<<"1)";
	PrintList(lst1);
	cout<<endl;
	cout<<"2)";
	PrintList(lst2);
	cout<<endl;
	lst2.sort();
	cout<<"3)";
	PrintList(lst2);
	cout<<endl; 
	lst2.pop_front() ;
	cout<<"4)";
	PrintList(lst2);
	cout<<endl;
	lst1.remove(2);
	cout<<"5)";
	PrintList(lst1);
	cout<<endl;
	lst2.unique();
	cout<<"6)";
	PrintList(lst2);
	cout<<endl;
	lst1.merge(lst2);
	cout<<"7)";
	PrintList(lst1);
	cout<<endl;
	cout<<"8)";
	PrintList(lst2);
	cout<<endl;
	lst1.reverse() ;
	cout<<"9)";
	PrintList(lst1);
	cout<<endl;     
	lst2.push_back(100);
	lst2.push_back(200);
	lst2.push_back(300);
	lst2.push_back(400);
	list<A>::iterator p1,p2,p3;
	p1=find(lst1.begin() ,lst1.end() ,3);
	
	p1=find(lst1.begin() ,lst1.end(),200);
	
	p1=find(lst1.begin() ,lst1.end(),400);
	lst1.splice(p1,lst2,p2,p3);
	//将[p2,p3)插入p1之前，并从lst2中删除[p2,p3)
	cout<<"11)";
	PrintList(lst1);
	cout<<endl;  
	
	PrintList(lst2);
	cout<<endl;        
}
