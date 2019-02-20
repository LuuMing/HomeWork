class NumArray {
public:
    vector<vector<int>> dp;
    NumArray(vector<int> nums) {
        dp.resize(nums.size(),vector<int>(nums.size()));
        for(int i = 0; i < nums.size();i++)
        {
            dp[i][i] = nums[i];
            for(int j = i + 1; j < nums.size(); j++)
            {
                dp[i][j] = dp[i][j-1] + nums[j];
            }
        }
    }
    
    int sumRange(int i, int j) {
        return dp[i][j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
