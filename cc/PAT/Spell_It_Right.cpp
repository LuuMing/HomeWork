#include<iostream>
#include<vector>
#include<algorithm>
#include<string> 
using namespace std;
class BigNumber
{
	private:
		string n;
	public:
		BigNumber(char c)
		{
			n = "";
			n.push_back(c);
		}
		BigNumber(int i)
		{
			n = "";
			n += std::to_string(i);
		}
		BigNumber(string s)
		{
			n = "";
			n = s;
		}
		BigNumber operator=(BigNumber  r)
		{
			n = "";
			n += r.n;
		}
		int at(int i)
		{
			return n.at(i)-'0';
		}
		int end()
		{
			return n.at(n.length()-1)-'0';
		}
		int length()
		{
			return n.length();
		}
		BigNumber operator+=(BigNumber r)
		{
			string result;
			int sum = 0;
			int carry = 0;
			int remain = 0;
			reverse(n.begin(),n.end());
			reverse(r.n.begin(),r.n.end());
			for(int i = 0; i < (*this).n.length() || i<r.n.length() ;i++)
			{
				sum =  ( (i < n.length()?n.at(i):'0') - '0') + ( (i < r.n.length()?r.n.at(i):'0') - '0') + carry;
				remain = sum % 10;
				carry = sum / 10;
				result += (remain+'0');				
			}
			if(carry!=0)
			{
				result += (carry+'0');
			}
			reverse(n.begin(),n.end());
			reverse(r.n.begin(),r.n.end());
			reverse(result.begin(),result.end());
			n = result;
			return BigNumber(result);
		}
		void output()
		{
			cout<<n;
		}
};
class String:public string
{
	public:
		BigNumber sum()
		{
			BigNumber s(0); 
			for(int i = 0; i< string::length(); i++)
			{
				BigNumber t(string::at(i));
				s += t;
			}
			return s;
		}
};

int main()
{
	char data[][6] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	String input;
	cin>>input;
	for(int i = 0; i<input.sum().length()-1;i++)
	{
		cout<<data[input.sum().at(i)]<<" ";
	}
	cout<<data[input.sum().end()];
	    return 0; 
}
