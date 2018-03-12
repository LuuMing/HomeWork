#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n)
{
	if(n < 2)
	{
		return false;
	}
	for(int i = 2;i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int reverse(int num,int radix)
{
	int sum = num % radix;
	num = num / radix;
	int rem;
	while(num)
	{
		rem = num % radix;
		num = num / radix;
		sum = (sum * radix)+rem;
	}
	return sum;
}
int main()
{
	int N;
	int radix;
	cin >> N;
	while(N >= 0)
	{
		cin >> radix;
		if(isPrime(N)&&isPrime(reverse(N,radix)))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		cin >> N;
	}
}
