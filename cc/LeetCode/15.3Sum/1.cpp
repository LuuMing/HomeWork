class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
  	sort(nums.begin(),nums.end());
	vector<vector<int>> result;
	for(int i = 0; i < nums.size(); i++)
	{	
        if (i >= 1) {
            while (nums[i] == nums[i-1]) {
                i++;
                continue;
            }
        }

		int s = i + 1, e = nums.size() - 1;
		while( s < e)
		{
			if(nums[s] + nums[e] < -nums[i])
			{
				s++;
			}
			else if( nums[s] + nums[e] > -nums[i])
			{	
				e--;
			}
			else
			{
				vector<int>tmp = {nums[i],nums[s],nums[e]};
				result.push_back(tmp);
				while(s < e && nums[s] == nums[s+1])
					s++;
				while(s < e && nums[s] == nums[s+1])
					e--;
				s++,e--;
			}
		}
	}   
	return result;
    }
};
