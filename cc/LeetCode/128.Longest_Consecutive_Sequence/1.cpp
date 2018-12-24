class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        sort(nums.begin(),nums.end());
        int L = 0;
        for(auto & i : nums)
        {
            m[i] = m[i - 1] + 1;
            if(m[i] > L)
                L = m[i];
        }
        return L;
    }
};
