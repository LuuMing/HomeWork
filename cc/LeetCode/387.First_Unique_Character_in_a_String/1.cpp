class Solution {
public:
    int m[26] = {0};
    int firstUniqChar(string s) {
        for(auto & c: s)
            m[c-'a']++;
        for(int idx = 0; idx < s.size(); idx++)
            if(m[s[idx]-'a'] == 1)
                return idx;
        return -1;
    }
};
