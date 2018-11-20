class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(auto i = nums.begin() + 2; i < nums.end();)
        {
            bool flag = true;
            while(*i == *(i-1) && *i == *(i-2))
            {
                i = nums.erase(i);
                if(i == nums.end())
                    break;
                flag = false;
            }
            if(flag)
                i++;
        }
        return nums.size();
    }
};
