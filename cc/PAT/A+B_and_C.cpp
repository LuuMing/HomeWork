#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
bool compare(long long int a,long long int b,long long int c)
{
	if(a > 0 && b > 0 && a > LLONG_MAX - b) return true;
	if( a < 0 && b < 0 && a < LLONG_MIN - b) return false;
	return (a+b > c);
}
int main()
{
	int N;
	cin >> N;
	long long a,b,c;
	for(int i = 0; i < N ;i++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("Case #%d: ",i+1);
		if(compare(a,b,c))
		{
			printf("true\n");
		}
		else
			printf("false\n");
	}
}
