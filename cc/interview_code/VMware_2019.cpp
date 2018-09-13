/*
小明要搬家，他家里面有许多物品要搬，所以令他非常苦恼。

不过他可以叫工人来帮他搬家，每一个工人可以搬走一些物品，但是要求物品的重量之和不超过W才行。

现在问题来了，小明最少要叫多少个工人，才能搬走所有物品呢？
*/
/*
第一行两个整数，N,W，分别表示物品数量和工人最大搬运重量和。

第二行到第n+1行，每行各一个整数C[i]，表示第i个物品的重量。

满足1<=N<=18，1<=C[i]<=W<=100000000
*/
#include<iostream>
#include<algorithm>
using namespace std;
int c[20];
bool cmp(const int & i1 ,const int & i2)
{
    return i1 > i2;
}
int main()
{
    
    int N,W;
    cin >> N >> W;
    for(int i = 0; i < N; i++)
    {
        cin >> c[i];
    }
    sort(c,c+N,cmp);
    int idx = 0;
    int R = W;
    int cnt = 0;
  int l = 0, r = N - 1; 
	while(l < r)
	{
		R = W;
		cnt ++;
		while(true)
		{
			if(c[l] <= R)
			{
				R -= c[l];
				l++;
			}
			if(R == 0 || c[l] > R)
				break;
		}
		while(true)
		{
			if(c[r] <= R)
			{
				R -= c[r];
				r--;
			}
			if(R== 0 || c[r] > R)
				break;	
		}

		
	}
	cout << cnt;
}
