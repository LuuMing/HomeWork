#include<stdio.h>
#include<stdlib.h>
void swap(int * a,int * b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void bubble_sort(int A[], int N)
{
	for(int i = N-1; i > 0; i--)
	{
		int flag = 1;
		for(int j = 0; j < i; j++)
		{
			if(A[j+1] < A[j])
			{
				swap(&A[j+1],&A[j]);
				flag = 0;
			}
		}
		if(flag)
			break;
	}
}
void insertion_sort(int A[],int N)
{
	int i,j;
	for( i = 1; i < N; i++)
	{
		int tmp = A[i];
		for( j = i; j > 0 && A[j-1] > tmp; j--)
			A[j] = A[j-1];
		A[j] = tmp;
	}
}
void selection_sort(int A[], int N)
{
	for(int i = 0; i < N; i++)
	{
		int MinPosition = -1;
		int Min = 2147483647;
		for(int j = i; j < N;j++)
		{
			if(A[j] < Min )
			{
				Min = A[j];
				MinPosition = j;
			}
		}
		if(MinPosition != -1)
		swap(&A[i],&A[MinPosition]);
	}
}
void heap_sort(int A[],int N)
{

}
int main()
{
	int N;
	scanf("%d",&N);
	int *data =(int*) malloc(N*sizeof(int));
	for(int i = 0; i < N; i++)
	{
		scanf("%d",data+i);
	}
	//bubble_sort(data,N);
	//insertion_sort(data,N);
	selection_sort(data,N);
	for(int i = 0; i < N;i++)
		if(i == N-1)
			printf("%d",data[i]);
		else
			printf("%d ",data[i]);
}
