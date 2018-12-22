class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long sum = 0;
        long sumDistinct = 0;
        set<int> s;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(!s.count(nums[i]))
            {
                s.insert(nums[i]);
                sumDistinct += nums[i];
            }
        }
        return ( 3 * sumDistinct - sum ) / 2;
    }
};
