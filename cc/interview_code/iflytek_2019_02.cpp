#include<iostream>
#include<vector>
using namespace std;
vector<int> current,Next;
int main()
{
	int cnt = 0;
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int t;
		scanf("%d",&t);
		current.push_back(t);
	}
	bool flag = false;
	while(!flag)
	{
		flag = true;
		for(int i = 0; i < current.size(); i++)
		{
			if(i == 0 && current.size() > 2 && current[0] > current[1])
			{
				Next.push_back(current[0]);
				continue;
			}
			if( current[i] > current[i - 1])
			{
				Next.push_back(current[i]);
			}
			else
			{
				flag = false;
			}
		}
	//	for(int i = 0; i < current.size(); i++)
	//		cout << current[i] << ' ';
		cout << endl;
		current = Next;
		Next.clear();
		cnt ++;
	}
	cout << cnt- 1;
}
