class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
  		sort(nums.begin(),nums.end());
		int result_min = 9999;
		int result;
		for(int i = 0; i < nums.size(); i++) 
		{
            int s = i + 1, e = nums.size() - 1;
			while(s < e)
			{
                if(abs(target- (nums[i] + nums[s]+ nums[e])) < result_min & s != e)
				{
					result_min = abs(target-(nums[i] + nums[s] + nums[e]));
					result = nums[i] + nums[s] +  nums[e];
				}
				if( nums[i] + nums[s] + nums[e] > target)
				{
					e--;
				}
				else if(nums[i] + nums[s] + nums[e] < target)
				{
					s++;
				}
                else
                {
                    s++,e--;
                }
			}
		} 
		return result; 	 
    }
};
