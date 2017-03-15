#include<stdio.h>
char Mi[101]={'\0'};

int printFirst()
{int x=100;
for(;x>=0;x--)
{
	if(Mi[x]!='\0'&&Mi[x]!=0)
	{
		if(x==1)
		{
			if(Mi[x]>=0)
			{
				printf("x%d",Mi[x]);
			}
			if(Mi[x]<0&&Mi[x]!=-1)
			{
				printf("-x%d",-Mi[x]);
			}
			if(Mi[x]==-1)
			{
				printf("-x",-Mi[x]);
			}
		}
		if(x==0)
		{
			if(Mi[x]>=0)
			{
				printf("%d",Mi[x]);
			}
			if(Mi[x]<0)
			{
				printf("%d",Mi[x]);
			}
		}
		if(x!=1&&x!=0)
		{
			if(Mi[x]==1)
			{
				printf("x%d",x);
			}
				
			if(Mi[x]>=0&&Mi[x]!=1)
			{
				printf("%dx%d",Mi[x],x);
			}
			if(Mi[x]<0&&Mi[x]!=-1)
			{
				printf("%dx%d",Mi[x],x);
			}
			if(Mi[x]==-1)
			{
				printf("-x%d",x);
			}
			
		}
		break;
	}
}
	return x;
}
int main()
{
	
	int a=1,xishu;

	while(a!=0)
	{
		scanf("%d%d",&a,&xishu);
		Mi[a]=xishu;
	}
a=1;
	while(a!=0)
	{
			scanf("%d%d",&a,&xishu);
		if(Mi[a]=='\0')
		Mi[a]=xishu;
		else
		Mi[a]=Mi[a]+xishu;
	} 
	int x=printFirst()-1;
	for(;x>=0;x--)
	{
	if(Mi[x]!='\0'&&Mi[x]!=0)
	{
		if(x==1)
		{
			if(Mi[x]>=0)
			{
				printf("+%dx",Mi[x]);
			}
			if(Mi[x]<0&&Mi[x]!=-1)
			{
				printf("-x%d",-Mi[x]);
			}
			if(Mi[x]==-1)
			{
				printf("-x",-Mi[x]);
			}
		}
		if(x==0)
		{
			if(Mi[x]>=0)
			{
				printf("+%d",Mi[x]);
			}
			if(Mi[x]<0)
			{
				printf("%d",Mi[x]);
			}
		}
		if(x!=1&&x!=0)
		{
			if(Mi[x]==1)
			{
				printf("+x%d",x);
			}
				
			if(Mi[x]>=0&&Mi[x]!=1)
			{
				printf("+%dx%d",Mi[x],x);
			}
			if(Mi[x]<0&&Mi[x]!=-1)
			{
				printf("%dx%d",Mi[x],x);
			}
			if(Mi[x]==-1)
			{
				printf("-x%d",x);
			}
			
		}

	}
	}

} 
