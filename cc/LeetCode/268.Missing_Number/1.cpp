class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size() + 1;
        int sum = 0;
        for(auto &n: nums)
            sum += n;
        return ( N * ( N -1 ) )/2 - sum;
    }
};
