class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroLast = 0;
        int idx = 0;
        for(; idx < nums.size(); idx++)
        {
            if(nums[idx] != 0){
                swap(nums[nonZeroLast++], nums[idx]);
            }
        }
    }
};
