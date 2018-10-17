class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int result = 1;
        int i = 0;
        while( i < n )
        {
            if(nums[i] >= 0 && nums[i] <= n)
            {
                int pos = nums[i] - 1;
                if( nums[i] != nums[pos] )
                {    
                    swap(nums[i], nums[pos]);
                    i--;
                }
            }
            i++;
        }
        for(int i = 0; i < n;i ++,result++)
        {
            if(nums[i] != result)
                break;
        }
        return result;
        
    }
};
