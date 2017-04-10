#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
using namespace std;
//样例输入 
//16
//new 1
//new 2
//add 1 1
//add 1 2
//add 1 3
//add 2 1
//add 2 2
//add 2 3
//add 2 4
//out 1
//out 2
//merge 1 2
//out 1
//out 2
//unique 1
//out 1
//样例输出 
//1 2 3 
//1 2 3 4
//1 1 2 2 3 3 4
//
//1 2 3 4
int main()
{
	int n;
	cin>>n;
	map<int,list<int> > mp;
	while(n--)
	{
		string cmd;
		cin>>cmd;
		if(cmd=="new")
		{
			int id;
			cin>>id;
			mp[id]=list<int>();
		}
		if(cmd=="add")
		{
			int id;
			int num;
			cin>>id>>num;
			mp[id].push_back(num);
		}
		if(cmd=="merge")
		{
			int id1;
			int id2;
			cin>>id1>>id2;
			mp[id1].merge(mp[id2]);
		} 
		if(cmd=="unique")
		{
			int id;
			cin>>id;
			mp[id].sort();
			mp[id].unique();
		}
		if(cmd=="out")
		{
			int id;
			cin>>id;
			mp[id].sort();
			list<int>::iterator i;
			for(i=mp[id].begin() ;i!=mp[id].end() ;i++)
				cout<<*i<<" ";
			cout<<endl;
		}
	}
	return 0;
}
