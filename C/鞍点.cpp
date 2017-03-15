#include<stdio.h>
int n;
int mat[100][100];
int  min(int i,int j);
int  max(int i,int j);


int main()
{
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		scanf("%d",&mat[i][j]);
	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
	{
		if(max(i,j)&&min(i,j))
		{
		printf("%d %d",i,j);
	flag=1;
	}
	}
	}
	if(flag==0)
	{
			printf("NO");
	}
} 
int  max(int i,int j)
{
	for(int ti=0;ti<n;ti++)
	{
		if(mat[i][j]<mat[i][ti])
		return 0;
	}
	return 1;
}
int  min(int i,int j)
{
	for(int ti=0;ti<n;ti++)
	{
		if(mat[i][j]>mat[ti][j])
		return 0;
	}
	return 1;
}

