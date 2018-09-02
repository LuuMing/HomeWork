class Solution {
public:
    bool isPalindrome(int x) {
 	if(x < 0)      return false;
	int ori = x;
	int ans = 0;
	while(x)
	{
		int tmp = x % 10;
		x /= 10;
		ans = ans * 10  + tmp; 
	}	 
	return ori == ans;
    }
};
