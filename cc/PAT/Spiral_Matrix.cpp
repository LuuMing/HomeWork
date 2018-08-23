/**************
	@date:18/8/23 13:36~15:08
	@author: LuMing
*****************/
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 10001
int num[MAX];
int result[MAX][MAX];
bool cmp(const int & i1,const int & i2)
{
	return i1>i2;
}
int main()
{
	int i,j,m = 0,n = 0,tmp_n = 0,dist = 9999;
	int x,x_min,x_max,y,y_min,y_max;
	int N; cin >> N;
	for(i = 0; i < N;i++)
		scanf("%d",num+i);
	sort(num,num+N,cmp);
	for(i = N; i > 0;i--)
	{
		if(N / i * i == N )
		{
			tmp_n = N / i;
			if(   i -tmp_n < dist && i >=tmp_n)
			{
				dist = i - tmp_n;
				m = i;
				n = tmp_n;
			}
		}
	}
	x_min = 0;
	y_min = 0;
	x_max = m-1;
	y_max = n-1;
	i = 0;
	while(true)
	{
		for(x = x_min,y = y_min; y <= y_max; y++)
		{
			result[x][y] = num[i++];
		}
		if(x_min++ > x_max)
			break;
		for(y = y_max,x = x_min; x <= x_max; x++)
		{
			result[x][y] = num[i++];
		}
		if(y_max-- <= y_min)
			break;
		for(x = x_max,y = y_max; y >= y_min; y--)
		{
			result[x][y] = num[i++];
		}
		if(x_max-- < x_min)
			break;
		for(y = y_min,x = x_max; x >= x_min; x--)
		{
			result[x][y] = num[i++];
		}
		if(y_min++ > y_max)
			break;
	}
	for(i = 0; i < m;i++)
	{
		for(j = 0; j < n;j++)
		{
			cout << result[i][j];
			if(j != n - 1)
				cout << ' ';
		}
		if(i != m- 1)
			cout << endl;
	}
}