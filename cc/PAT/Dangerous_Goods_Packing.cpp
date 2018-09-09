#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
using namespace std;
#define MAX 100009
unordered_set<int> s[MAX];
int T[10001];
int N,M;
int main()
{
	cin >> N >> M;
	for(int i = 0; i< N;i++)
	{
		int a,b ; scanf("%d%d",&a,&b);
		s[a].insert(b); s[b].insert(a);
	}

	for(int i = 0; i < M;i ++)
	{
		unordered_set<int> cant;
		int t; cin >> t;
		bool flag = true;
		for(int j = 0; j < t; j++){
			scanf("%d",T+j);
			if(cant.count(T[j]))
				flag = false;
			if(flag)
			for(auto j:s[T[j]])
			{
				cant.insert(j);
			}
		}
		if(flag)
			cout << "Yes";
			else
			cout << "No";
		if(i != M - 1)
		cout << endl;
	}
}