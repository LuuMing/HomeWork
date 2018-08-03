class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result;
	unordered_map<int,int>m;
	for(int i = 0; i < nums.size();i++)
	{
		if(m.count(target-nums[i]))
		{
			result.push_back(i);
			result.push_back(m[target-nums[i]]);
			return result;
		}
		else
		{
			m.insert(make_pair(nums[i],i));
		}
	}
    }
};
