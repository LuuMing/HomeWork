class Solution {
    vector<vector<int> > result;
    void dfs(int idx , vector<int>  nums)
    {
        if( idx == nums.size() - 1)
        {
            result.push_back(nums);
            return ;
        }
        for(int i = idx ; i < nums.size(); i++)
        {
            if( i != idx && nums[i] == nums[idx])
                continue;
                swap(nums[idx] , nums[i] );
                dfs(idx + 1,nums);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,nums);
        return result;
    }
};
