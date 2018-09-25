/*
	输出二进制一的个数亦或原数
*/
#include<iostream>
using namespace std;
int NumOfTrees(int n)
{
	int orig = n;
	int cnt = 0;
	while(n)
	{
		if(n % 2 == 1)
			cnt ++;
		n /= 2;
	}

	return  cnt ^ orig;
}
int main()
{
	int n; cin >> n;
	cout << NumOfTrees(n);
}
