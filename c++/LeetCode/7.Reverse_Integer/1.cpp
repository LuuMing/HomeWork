class Solution {
public:
    int reverse(int x) {
    long int result = 0;
	bool neg = false;
	if(x < 0)
	{
		x = -x;
		neg =true;
	}
	while(x)
	{
		int gewei = x % 10;
        result = result * 10 + gewei;
		x = x / 10;
	}   
    if(result >= 2147483647 || result <= -2147483648)
            return 0;
	if(neg)
		return -result;
	else
		return result; 
    }
};

