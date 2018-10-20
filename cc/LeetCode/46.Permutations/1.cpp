class Solution {
public:
    vector<vector<int>> result;
    void dfs(int idx,vector<int> & nums)
    {
        if( idx == nums.size() - 1)
        result.push_back(nums);
        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx],nums[i]);
            dfs(idx + 1,nums);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0,nums);
        return result;
    }
};
