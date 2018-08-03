#include<stdio.h> 
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d=",n);

	for(;n/2.0!=1.0&&n/3.0!=1.0&&n/5.0!=1.0;)
	{
		if(n%2!=0&&n%3!=0&&n%5!=0)
		{
		printf("%d",n);
		break;		
		}
		if(n%2==0){
		printf("2x");
		n=n/2;
		continue;
		}
		if(n%3==0)
		{
		printf("3x");
		n=n/3;	
		continue;
		}
		if(n%5==0){
		printf("5x");
		n=n/5;
		continue;
		}
	}
	if(n/2==1||n/3==1||n/5==1)
	printf("%d",n);
	
}
