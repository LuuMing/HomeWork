class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low = 0, hi = nums.size() - 1, idx = 0;
        while(low < hi&& idx <= hi)
        {
            if(nums[idx] == 2)
            {
                swap(nums[hi--],nums[idx]);
            }
            else if(nums[idx] ==0)
            {
                swap(nums[low++],nums[idx++]);
            }
            else
                idx++;
        }
    }
};
