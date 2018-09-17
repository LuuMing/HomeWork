/*
圈地运动
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
圈地运动，就是用很多木棍摆在地上组成一个面积大于0的多边形～

小明喜欢圈地运动，于是他需要去小红店里面买一些木棍，期望圈出一块地来。小红想挑战一下小明，所以给小明设置了一些障碍。障碍分别是：

1.如果小明要买第i块木棍的话，他就必须把前i-1块木棍都买下来。

2.买了的木棍都必须用在圈地运动中。

那么请问小明最少买多少根木棍，才能使得木棍围成的图形是个面积大于0多边形呢？*/
// 18%
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int v[100001];
int main()
{
	int N; cin >> N;
	if( N <= 2)
	{
		cout << -1;
		return 0;
	}
	int cnt = 99999;
	int sum = 0;
	cin >> v[0];
	sum  += v[0];
	for(int i = 1; i < N;i ++)
	{
		cin >> v[i];
		if(i >= 2)
		{
			sort(v,v+i-1);
			if( sum > v[i])
			{
				if( i < cnt)
					cnt = i;
			}
		}	
		sum += v[i];
	}
	if(cnt != 99999)
		cout << cnt+1;
	else
		cout << "-1";
}
