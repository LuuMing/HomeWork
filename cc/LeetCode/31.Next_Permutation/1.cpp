class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 2 ;i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                int j = 0;
                int val = nums[i];
                for(j = i + 1; j < nums.size(); j++)
                {
                    if(nums[j] <= val)
                    {
                        break;
                    }
                }
                swap(nums[i],nums[j-1]);
                reverse(nums.begin() + i + 1,nums.end());
                return ;
            }
        }
        reverse(nums.begin(),nums.end());
    }
};
