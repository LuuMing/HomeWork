/*
	小明在课上学习了进制转化。现在他有q个询问，每次询问想问你在[l,r]区间内，k进制表示中，k-1的数量最多的数是哪个数。比如当k=2时，9的二进制就是1001，那么他就有2个1。

输入
测试用例包含多组

第一行一个q，表示有q组询问。

接下来q行，每行三个整数k, l, r, 分别表示进制数 , 以及查询的范围。

满足1<=q<=100000,2<=k<=16,1<=l<=r<=10^16

输出
对于每组询问，输出答案。如果有多个答案，请输出最小的。


样例输入
1
8 1 100
样例输出
63

*/
// 29 %
#include<iostream>
using namespace std;
int M = 0;
int result;
void how(int k , int i)
{
	int orig = i;
	int cnt = 0;
	while(i)
	{
		if( i % k == k - 1)
		{
			cnt++;
		}
			i /= k;
	}
	if(cnt > M )
	{
		M = cnt;
		result = orig;
	}
}
int main()
{
	int N; cin >> N;
	for(int i = 0; i < N;i++)
	{
		int k; cin >> k;
		int l,r; cin >> l >> r;
		for(;l <= r; l++)
		{
			how(k,l);
		}
		cout << result << endl;
	}
}
