class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 2;
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(++m[nums[i]] > threshold)
                return nums[i];
        }
        
    }
};
