class Solution {
public:
    int bound(vector<int> & nums,int target, bool left)
    {
        int lo = 0, hi = nums.size();
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] > target || (left && target == nums[mid]))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return { -1, -1 };
        int left = bound(nums,target,true);
        if( left == nums.size()  || nums[left] != target)
        {
            return {-1,-1};
        }
        return {left,bound(nums,target,false) - 1};
    }
};
