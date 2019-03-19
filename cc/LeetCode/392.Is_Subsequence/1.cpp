class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx1 = 0, idx2 = 0;
        while(idx1 < s.size() && idx2 < t.size())
        {
            if( t[idx2] == s[idx1] )
            {
                idx1++;
            }
            idx2++;
        }
        return idx1 == s.size();
    }
};
