class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for( int idxOfNum1 = 0; idxOfNum1 < nums.size(); idxOfNum1++)
        {
            if( idxOfNum1 >= 1)
                while(nums[idxOfNum1] == nums[idxOfNum1-1])idxOfNum1++;
            for(int idxOfNum4 = nums.size()-1; idxOfNum4 > idxOfNum1; idxOfNum4--)
            {
                if( idxOfNum4 < nums.size() - 1)
                while(nums[idxOfNum4] == nums[idxOfNum4+1])idxOfNum4--;

                int twoSum = nums[idxOfNum1] + nums[idxOfNum4];
                int lo = idxOfNum1 + 1;
                int hi = idxOfNum4 - 1;
                while(lo < hi)
                {
                    if(nums[lo] + nums[hi] + twoSum > target)
                        hi--;
                    else if(nums[lo] + nums[hi] + twoSum < target)
                        lo++;
                    else
                    {
                        result.push_back({nums[idxOfNum4],nums[idxOfNum1],nums[lo],nums[hi]});
                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo ++, hi--;
                    }
                }
            }
        }
        return result;
    }
};