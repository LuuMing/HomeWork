class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
        flag[0] = true;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 1; j <= nums[i];j++)
            {
                if(i + j < nums.size())
                    flag[i+j] = true;
            }
        }
        for(int i = 0; i < nums.size(); i++)
            cout << flag[i] <<' ';
        for(int i = 0; i < nums.size(); i++)
        {
            if(!flag[i])
                return false;
        }
        return true;
    }
};
