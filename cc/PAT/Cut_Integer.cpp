#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<string> inputs(N);
	for(int i =0; i < N;i++)
	{
		cin >> inputs[i];
	}
	for(auto &input:inputs)
	{
		long long int a = stoll(input.substr(0,input.size()/2));
		long long int b = stoll(input.substr(input.size()/2));
		long long int c = stoll(input);
		if(a*b*c==0)
		{
			cout << "No" <<endl;
			continue;
		} 
		if(c%(a*b)==0)
		{
			cout << "Yes"<<endl;
		}
		else
		{
			cout << "No"<<endl;
		}
	}
}
