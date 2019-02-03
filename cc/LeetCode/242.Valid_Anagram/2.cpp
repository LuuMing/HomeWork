class Solution {
    unordered_map<char,int> m;
public:
    bool isAnagram(string s, string t) {
        for(auto &c:s)
            m[c]++;
        for(auto &c:t)
        {
            m[c]--;
            if( m[c] == 0)
                m.erase(c);
            else if( m[c] < 0)
                return false;
        }
        return m.empty();
    }
};