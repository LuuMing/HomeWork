class Solution {
public:
    int strStr(string haystack, string needle) {
	if(needle.size() == 0) return 0;
    int idx = -1;
  	for(int i = 0; i < haystack.size(); i++ )
	{
		if(haystack[i] == needle[0])
		{
			idx = i;
			bool flag = true;
			for(int j = 1,ii = i+1; j < needle.size(); j++,ii++)
			{
				if(needle[j] != haystack[ii] )
				{
					flag = false;
					break;
				}
			}
			if(flag)
				return idx;
		}
	}
	return -1;    
    }
};
