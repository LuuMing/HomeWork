#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string reverse_number(string & number)//求逆序数 
{
	string r(number);
	reverse(r.begin(),r.end());
	return r;
}
string add (string n1, string n2)
{
	char carry = '0';
	char remain = '0';
	int sum = 0;
	string result = "";	
	reverse(n1.begin(),n1.end());
	reverse(n2.begin(),n2.end());
	for(int i = 0; i < n1.length() || i < n2.length(); i++)
	{

		sum = ((i<n1.length()?n1[i]:'0')-'0') + ((i<n2.length()?n2[i]:'0')-'0') + (carry - '0');
		//sum用来表示每一位的和，如果处理未对齐的数字，则用0代替 
		carry = (sum / 10) + '0';
		remain = sum % 10 + '0';
		result.insert(result.begin(),remain);
	}	
	if(carry!='0')
	{
		result.insert(result.begin(),carry);
	}
	return result;
}
int main()
{
	string num = "";
	string sum = "";
	cin >> num;
	for(int i = 0 ; i < 10; i++ )
	{
		if(num == reverse_number(num))
		{
			cout<<num<<" is a palindromic number.";
			return 0;
		}
		sum = add(num,reverse_number(num));
		cout<<num<<" + "<<reverse_number(num)<<" = "<<sum<<endl;
		num = sum;	
	}
	cout<<"Not found in 10 iterations.";
	return 0;
}

