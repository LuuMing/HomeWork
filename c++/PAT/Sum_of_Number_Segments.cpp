#include<cstdio>
using namespace std;
int main()
{
	double sum = 0;
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N;i++)
	{
		double d;
		scanf("%lf",&d);
		sum += d*(i+1)*(N-i);
	}
	printf("%.2lf",sum);

	
}
