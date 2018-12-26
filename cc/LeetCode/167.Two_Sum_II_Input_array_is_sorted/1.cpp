class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while(numbers[lo] + numbers[hi] != target)
        {
            if(numbers[lo] + numbers[hi] > target)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
        return {lo+1,hi+1};
    }
};
