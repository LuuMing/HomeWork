class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
  	string result;
	int idx = 0;
        bool flag = true;
        if(strs.size() == 0) return result;
        if(strs.size() == 1) return strs[0];
	while(flag)
	{
		
		for(int i = 1; i < strs.size(); i++)
		{
			if(idx < strs[i].size() && strs[i][idx] == strs[0][idx])			{
			}
			else
			{
				flag = false;
			}
		}
		if(flag)
			result.push_back(strs[0][idx]);
		else
			break;
		idx++;
	}
	cout << result;
	return result;
    }
};
