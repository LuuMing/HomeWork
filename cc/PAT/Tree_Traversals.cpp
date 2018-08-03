#include<iostream>
#include<vector>
using namespace std;
vector<int> post;
vector<int> inorder;
vector<int> result(10000,-1);
void visit(int root,int start,int end,int index)
{							//give the index of the tree, then, left child's index is index*2, right child's index is index*2+1
	if(start > end) return;
	result[index] = post[root];			//store the date to vector by its index
	int i = start;					//find root i in in-order
	while( i < end && inorder[i] != post[root])
		i++;
	visit( root -(end - i + 1),start,i-1,2*index); 	//the root's position of left tree is current root's position minius the number of right child.
							//start from 0, end from i-1
	visit(root-1,i+1,end,2*index+1);		//the root's position of right tree is current root's position minus 1
							//start from i+1, end from end
}
int main()
{
	int N;
	int t;
	cin >> N;
	for(int i = 0; i < N;i++)
	{
		cin >> t;
		post.push_back(t);	
	}
	for(int i = 0;i < N; i++)
	{
		cin >> t;
		inorder.push_back(t);
	}
	visit(N-1,0,N-1,1);
	int num = 0;
	for(int i = 0; i < 100000 && num < N;i++)
	{
		if(result[i]!=-1)
		{
			if(num == N-1)
			{
				cout << result[i];
			}
			else
			{
				cout << result[i] <<' ';
			}
			num++;
		}
	}
}
