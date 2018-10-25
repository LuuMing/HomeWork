class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Max = nums[0];
        int current = nums[0];
        int Min = 0;
        for(int i = 1; i < nums.size(); i++)
        {
           
            if(current < Min )
            {
                Min = current;
            }
            current += nums[i];
            if(current - Min > Max)
            {
                Max = current - Min;
            }
        }
        return Max;
    }
};
