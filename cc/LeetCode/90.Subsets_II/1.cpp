class Solution {
public:
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
            while(nums[i+1] == nums[i])i++;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        N = nums.size();
        dfs({},0,nums);
        return result;
    }
};
