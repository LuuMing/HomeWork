#include<iostream>
#include<vector>
#include<set>
#include<math.h>
using namespace std;
#define MAX 101
int N;
int type[MAX];
set<int>  w,h;
int main()
{
	cin >> N;
	int cnt = 0;
	for(int i = 1; i <= N ;i++)
	{
		int t; cin >> t;
		if(t > 0)
		h.insert(t);
		else
		w.insert(-t);
	}
	if(w.size() == 2)
	for(set<int>::iterator ii = w.begin(); ii != w.end(); ii++)
		cout << *ii <<' ';
	else
		cout << "No Solution";
			return 0;
}
  