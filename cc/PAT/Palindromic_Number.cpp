#include<iostream>
#include<algorithm>
using namespace std;

string string_add(string a,string b)
{
	string result;
	int sum = 0;
	int remain = 0;
	int carry = 0;
	for(int i = a.size()-1,j = b.size()-1; i >=0 || j>= 0; i--,j--)
	{
		 sum = ((i>=0?a[i]:'0') - '0') + ((j>=0?b[j]:'0')-'0') + carry;
		 remain = sum%10;
		 carry = sum /10;
		result += to_string(remain);
	}
	if(carry !=0)
	result += to_string(carry);
	reverse(result.begin(),result.end());
	return result;
}
int main()
{
	string origin;
	int N;
	int times = 0;
	cin >> origin >> N;
	string reversed = origin;
	reverse(reversed.begin(),reversed.end());
	while(origin != reversed && times < N)
	{
		origin = string_add(origin,reversed);
		reversed = origin;
		reverse(reversed.begin(),reversed.end());
		times++;
	}
	cout << origin <<endl<<times;
}

