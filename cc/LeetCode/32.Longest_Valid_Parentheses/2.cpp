class Solution {
public:
    int longestValidParentheses(string s) {
        
        // dp[i] here could stand for
         // the maxmium length we could get
          // at positon i.
        vector<int> dp(s.size(),0);
        
        int MAX = 0;
        for(int i = 1; i < s.size(); i++)
        {
            if( s[i] == ')') 
            {
                if(s[i - 1] == '(')               
                    dp[i] = dp[ i - 2 ] + 2;    // i - 2 means adds last time's match length
                else                            // nest Parentheses
                {
                    if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(' )
                    {
                        if(i - dp[i - 1] - 2 >= 0)  			// if have last time's match length
                            dp[i] = dp[i-1] + dp[i - dp[i - 1] - 2] + 2; // we add it
                        else
                            dp[i] = dp[i - 1] + 2;
                    }
                        
                } 
                MAX = max(MAX,dp[i]);
            }
        }

        return MAX;
    } 
};
