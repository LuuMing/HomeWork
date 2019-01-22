class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int lo = 0, hi = 0;
        int sum = 0;
        int minDist = INT_MAX;
        while(hi < nums.size())
        {
            while(sum < s && hi < nums.size()) sum += nums[hi++];
            if( sum >= s)
                minDist = min(minDist,hi - lo);
            while(sum >= s && lo <= hi) sum -= nums[lo++];
            if( sum + nums[lo - 1] >= s)
                minDist = min(minDist,hi - lo+1);
        }
        return minDist == INT_MAX?0:minDist;
    }
};
