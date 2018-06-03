#include<iostream>
using namespace std;
#define lowbit(i) ((i) & (-i))
#define MAX 1000
int tree[MAX];
void update(int idx,int val)  // add num to cnt[k]
{
	while(idx<=MAX)
	{
		tree[idx] += val;
		idx += idx &-idx;
	}
}
int read(int idx) // sum of tree[1] ~ tree[k]
{
	int sum = 0;
	while(idx)
	{
		sum += tree[idx];
		idx -= idx&-idx;
	}
	return sum;
}

int main()
{
	string q;
	cin >> q;
	while(q!="-1")
	{
		if(q == "add")
		{
			int a,b;
			cin >> a >> b;;
			update(a,b);
			cout << "add " << b <<" to cnt["<<a<<']'<<endl;
		}
		else if(q == "get")
		{
			int t;
			cin >> t;
			cout << "The sum of cnt[1~"<<t<<"] is " << read(t)<<endl;
		}
		cin >> q;		
	}
}
