#include<iostream>
#include<list>
using namespace std;
class Mstring:public string
{
	public:
		bool operator < (string &s)
		{
			return *this+s < s+*this;
		}
};
int main()
{
	list<Mstring> input;
	int N;
	cin >> N;
	for(int i = 0; i< N; i++)
	{
		Mstring t;
		cin >> t;
		input.push_back(t);
	}
	input.sort();
	string output = "";
	for(auto &i:input)
	{
		output += i;
	}
	int num = 0;
	for(;num < output.size()-1;num++)
	{
		if(output.at(num)!='0')
			break;
	}
	cout<<output.substr(num);
}
