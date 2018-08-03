class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int i =0, j = 0;
	int maxLen = 0;
	set<char> ss;
	while(i < s.size() && j < s.size()) 
	{
		if(!ss.count(s[j]))
		{
			ss.insert(s[j]);
			maxLen = max(maxLen,j-i+1);
			j++;
		}
		else
		{
			ss.erase(s[i]);
			i++;
		}
	}
	return maxLen;
    }
};
