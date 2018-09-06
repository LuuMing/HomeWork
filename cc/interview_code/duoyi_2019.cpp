/*
	多益 2019 内推 笔试编程题
	m个数字中随机选择n个数字，要求复杂度为o(n) [WA]
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int main()
{
	int m,n,r,cnt,s;
	cin >> m >> n;
	srand(time(0));
	vector<int> data;
	vector<int> book;
	data.resize(m);
	book.resize(m,0);
	r = rand() ;
	cout << "r =   "<< r << endl;
	cnt = 0;
	for(int i = 0; i < m; i++)
	{
		cin >> data[i];
		int p = (r + data[i] )% m;
		//cout << "p =  "<<p;
		for(s = 0; s < m; s++)
		{
			if(!book[ (p + s) % m])
			{
				book[(p+s) % m] = 1;
				break;
			}
		}
		if(book[i] && cnt < n)
		{
			cout << data[i] << ' ' ;
			cnt++;
		}
		
	}
	cout << "";
}
