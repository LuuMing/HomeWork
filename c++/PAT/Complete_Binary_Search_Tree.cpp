#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> input,result(1001,-1);
int N;
int pos = 0;
void build(int root)
{
	if(root > N)
		return ;
	build(root*2);
	result[root] = input[pos];
	pos++;
	build(root*2+1);
	
}
int main()
{
	cin >> N;
	input.resize(N);
	for(int i = 0; i < N;i++)
	{
		cin >> input[i];
	}
	sort(input.begin(),input.end());
	build(1);
	int time = 0;
	int i = 0;
	while(time != N)
	{
		if(result[i]!=-1)
		{
			if(time != N-1)
				cout << result[i]<<' ';
			else
				cout << result[i];
			time ++;
		}
		i++;
	}
}
