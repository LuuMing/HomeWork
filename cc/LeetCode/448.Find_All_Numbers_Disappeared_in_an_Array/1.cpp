class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> appear(nums.size(),false);
        for(int i = 0; i < nums.size(); i++)
        {
            appear[nums[i] - 1] = true;
        }
        vector<int> ret;
        for(int i = 0; i < appear.size(); i++)
        {
            if(!appear[i])
                ret.push_back(i+1);
        }
        return ret;
    }
};