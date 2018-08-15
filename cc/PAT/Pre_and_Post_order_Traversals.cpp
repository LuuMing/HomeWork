/*****************
	@author: LuMing
	@date:	18/8/15 09:40~11:30
******************/
#include<iostream>
#include<vector>
using namespace std;
#define MAX 31
int preorder[MAX];
int postorder[MAX];
int N;
bool unique = true;
vector<int> v;
void build(int preStart, int preEnd, int postStart, int postEnd)
{	
	if(preStart == preEnd)
	{
		v.push_back(preorder[preStart]);	
		return ;
	}
	if(preorder[preStart] == postorder[postEnd])
	{
		int i = preStart + 1;
		for(; i < preEnd && preorder[i] != postorder[postEnd-1]; i++); // find the root of right child in preorder sequence
		if(i - preStart > 1)
			build(preStart + 1,i-1,postStart,postStart+(i - preStart-1) - 1);
		else
			unique = false;
		v.push_back(preorder[preStart]);
		build(i,preEnd,postStart + (i - preStart-1),postEnd - 1);
	}
}
int main()
{
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		scanf("%d",preorder+i);
	}
	for(int i = 0; i < N;i++)
	{	
		scanf("%d",postorder+i);
	}
	build(0,N-1,0,N-1);
	printf(unique?"Yes\n":"No\n");
	for(int i = 0; i < v.size(); i++)
	{
		printf("%d", v[i]);
		if(i != v.size() - 1)
			printf(" ");
	}
	printf("\n");
	return 0;
}
