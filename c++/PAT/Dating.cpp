#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
char input[4][60];

void get_date(int & d,int & h,int & min)
{
	int i;
	for(i = 0;(input[0][i] >'G' || input[0][i] <'A') || input[0][i] != input[1][i];i++);
		d = input[0][i] - 'A';
	for(i++; ((input[0][i] >'N'|| input[0][i] <'A') && (input[0][i] >'9' && input[0][i] <'0')) || input[0][i] != input[1][i];i++);
	if(isdigit(input[0][i]))
		h = input[0][i] - '0';
	else
		h = input[0][i] - 'A' + 10;
	for(i = 0; input[2][i]!=input[3][i] || !isalpha(input[2][i]);i++);
	min = i;
}
int main()
{
	char date[][10] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	for(int i = 0; i < 4;i++)
	{
		scanf("%s",input[i]);
	}
	int d,h,min;
	get_date(d,h,min);
	printf("%s %02d:%02d",date[d],h,min);
}
