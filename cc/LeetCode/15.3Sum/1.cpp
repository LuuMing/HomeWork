class Solution {
	vector<int>  tmp;
	vector<vector<int>> result;
	int sum = 0;
	void dfs(vector<int> & nums,int idx)
	{
		tmp.push_back(nums[idx]);
		sum += nums[idx];
		if(sum == 0 && tmp.size() == 3)
		{
			result.push_back(tmp);
		}
		if(tmp.size() < 3&& idx + 1 < nums.size())
		{
			dfs(nums,idx+1);
		}
		else
		{
			result.pop_back();
			if(idx  <nums.size())
				dfs(nums,idx+1);
		}
		
	}
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			dfs(nums,0);
			return result;
    }
};
