class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0)
            return "";
        int n = s.size();
        int dp[n][n] = {0};
        string result;
        int max_l = 0;
        for(int i = 0; i < s.size();i ++)   
        {
            dp[i][i] = 1;
            if(i == s.size() - 1)
                break;
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1; 
            }
            
        }
        
        for(int i = n - 3; i >= 0; i--)
        {
            for(int j = i + 2; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                    dp[i][j] = 0;
            }    
        }
        for(int i = 0; i < n;i++)
        {
            for(int j = i; j < n; j++)
            {
                if( dp[i][j] == 1 && j - i + 1 > max_l)
                {
                    max_l = j - i + 1;
                    result = s.substr(i,j-i+1);
                }
            }
        }
        return result;
    }
};
