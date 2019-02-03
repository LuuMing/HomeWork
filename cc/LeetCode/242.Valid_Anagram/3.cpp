class Solution {
    int m[128];
public:
    bool isAnagram(string s, string t) {
        int cnt = 0;
        for(auto &c:s)
        {
            if( m[c] == 0)
                cnt++;
            m[c]++;
        }
        for(auto &c:t)
        {
            m[c]--;
            if( m[c] == 0)
                cnt--;
            else if( m[c] < 0)
                return false;
        }
        return cnt== 0;
    }
};