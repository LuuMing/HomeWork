#include<cstdio>
#include<iostream>
#include<unordered_set>
using namespace std;
char A[10001];
unordered_set<char> B;
int main()
{
	cin.getline(A,10001);
	char t;
	scanf("%c",&t);
	B.insert(t);
	while(t!='\n')
	{
		scanf("%c",&t);
		B.insert(t);
	}
	for(int i = 0;A[i] != 0;i++)
	{
		if(!B.count(A[i]))
		printf("%c",A[i]);
	}
}
