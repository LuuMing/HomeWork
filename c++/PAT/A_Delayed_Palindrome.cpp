#include<iostream>
using namespace std;
int reverse_number(int number)//ÇóÄæÐòÊý 
{
	int num = 0;
	while(number != 0)
	{
		num = num * 10;
		int yu = number % 10;
		number = number / 10;
		num = num + yu;		
	}
	return num;
} 

int main()
{
	int num = 0;
	int sum = 0;
	cin >> num;
	for(int i = 0 ; i < 10; i++ )
	{
		if(num == reverse_number(num))
		{
			cout<<num<<" is a palindromic number.";
			return 0;
		}
		sum = num + reverse_number(num);
		cout<<num<<" + "<<reverse_number(num)<<" = "<<sum<<endl;
		num = sum;	
	}
	cout<<"Not found in 10 iterations";
	return 0;
}

