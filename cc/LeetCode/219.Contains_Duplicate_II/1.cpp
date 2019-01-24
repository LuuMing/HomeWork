class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        if( k == 0 )
            return false;
        for(int i = 0; i <= k && i < nums.size(); i++)
        {
            if( s.count(nums[i]) )
                return true;
            else
                s.insert(nums[i]);
        }
        int lo = 0,hi = k;
        while(lo < nums.size() && hi < nums.size())
        {
            s.erase(nums[lo++]);
            if( ++hi < nums.size())
            {
                if(s.count(nums[hi]))
                    return true;
                else
                    s.insert(nums[hi]);
            }
        }
        return false;
    }
};
