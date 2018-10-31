class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = i; j >= 0; j--)
            {
                dp[i] = (dp[i] || (dp[i-j] && nums[i-j] >= j));
                if(dp[i]) // 减枝
                    break;
            }
        }
        return dp[nums.size() - 1] == 1;
    }
};
