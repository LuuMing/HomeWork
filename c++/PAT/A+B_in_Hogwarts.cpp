#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	int d,e,f;
	scanf("%d.%d.%d",&a,&b,&c);	
	scanf("%d.%d.%d",&d,&e,&f);
	printf("%d.%d.%d", a+d+(b+e+(c+f)/29)/17  ,( b+e+(c+f)/29)%17 ,(c+f)%29);

}
