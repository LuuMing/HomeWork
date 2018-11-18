class Solution {
vector<vector<int>> result;
    int N;
    void dfs(vector<int> current,int idx,vector<int> & nums)
    {
        result.push_back(current);
        for(int i = idx ; i < N; i++)
        {
            current.push_back(nums[i]);
            dfs(current,i + 1,nums);
            current.pop_back();
        }
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        dfs({},0,nums);
        return result;
    }
};
