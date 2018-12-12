class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        int Min = INT_MAX;
        for(int i = 0; i < triangle.size(); i++)
        {
            dp.push_back(0);
            for(int j = dp.size() - 1; j >= 0;j--)
            {
                if(j == 0)
                {
                    dp[j] += triangle[i][0];
                }
                else if(j == dp.size() - 1)
                {
                    dp[j] = triangle[i][j] + dp[j-1];
                }
                else
                {
                    dp[j] =  min(dp[j],dp[j-1]) + triangle[i][j];
                }
                if(i == triangle.size() - 1 && dp[j] < Min)
                {
                    Min = dp[j];                    
                }
            }
        }
        return Min;
    }
};
