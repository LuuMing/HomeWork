class Solution {
public:
    unordered_set<string> strSet;
    bool wordBreak(string s, vector<string>& wordDict) {
       for(auto &i:wordDict)
           strSet.insert(i);
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        int i = 0;
        for( i = 1; i <= s.size(); i++)
        {
            for( int j = 0; j < i; j++ )
            {
                if( dp[j] && strSet.count(s.substr(j,i-j)) )
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return  dp[i-1];
    }
};