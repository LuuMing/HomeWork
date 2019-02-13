class Solution {
public:
    int findMin(vector<int>& nums) {
        if( nums.size() == 1)
            return nums[0];
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi)
        {
            int mid = ( lo + hi ) / 2;
            if( nums[lo] > nums[hi] )
            {
                if(nums[mid] > nums[lo])
                    lo = mid;
                else
                    hi = mid;
            }
            else
                return nums[lo];
        }
        return nums[lo+1];
    }
};
