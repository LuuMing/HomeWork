#include<stdio.h>

int main()
{
int a,b,yu,d;
scanf("%d/%d",&a,&b);
yu=a*10/b;
printf("0.");
for(int i=0;i<200&&yu!=0;i++)
{
	printf("%d",(a*10)/b);
	yu=a*10-((a*10)/b)*b;
	a=yu;
}printf("\n");

}
