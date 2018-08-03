class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result;
	unordered_map<int,int>m;
	for(int i = 0; i < nums.size();i++)
	{
		m.insert(make_pair(nums[i],i));
	}
	for(int i = 0; i < nums.size(); i++)
	{
		if(m.count(target-nums[i])&&m[target-nums[i]]!=i)
		{
			result.push_back(i);
			result.push_back(m[target-nums[i]]);
			return result;
		}
	}
	return 	  	result; 
    }
};
