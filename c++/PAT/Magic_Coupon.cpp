#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 100001
using namespace std;
long a[MAX];
long b[MAX];
long sum;
int main()
{
	int n1,n2;cin >> n1;
	int b1,b2;
	for(int i = 0; i < n1;i++)
	{
		scanf("%ld",&a[i]);
	}
	sort(a,a+n1);
	cin >> n2;
	for(int i = 0;i < n2;i++)
		scanf("%ld",&b[i]);
	sort(b,b+n2);
	for(b1 = 0;b1 <n1;b1++)
		if(a[b1]>0) break;
	for(b2 = 0; b2 < n2;b2++)
		if(b[b2] >0) break;
	for(int i = n1-1,j=n2-1; i>=b1 && j >=b2;i--,j--)
		sum += a[i] * b[j];
	for(int i = 0,j=0; i <b1 && j<b2;i++,j++)
		sum += a[i] * b[j];
	printf("%ld",sum);
}
