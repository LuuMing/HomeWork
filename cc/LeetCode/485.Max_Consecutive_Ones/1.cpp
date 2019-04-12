class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int runningAccu = 0;
        int Max = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                runningAccu += 1;
            else
                runningAccu = 0;
            Max = max(Max,runningAccu);
        }
        return Max;
    }
};