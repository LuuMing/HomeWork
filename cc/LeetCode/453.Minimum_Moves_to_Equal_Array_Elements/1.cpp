class Solution {
public:
    int minMoves(vector<int>& nums) {
        long int sum = 0;
        int minNum = INT_MAX;
        for(auto & n : nums)
        {
            sum += n;
            minNum = min(n,minNum);
        }
        return sum - (nums.size() * minNum );
    }
};
