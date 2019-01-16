class Solution {
public:
    struct map
    {
        char to = 0;
        bool used = false;
    };
    map m[128];
    bool isIsomorphic(string s, string t) {
        for(int i = 0; i < s.size(); i++)
        {
            if(!m[s[i]].to)
            {
                if(m[t[i]].used)
                    return false;
                else  
                {
                    m[s[i]].to = t[i];
                    m[t[i]].used = true;
                }
            }
            else
            {
                if(m[s[i]].to != t[i])
                    return false;
            }
        }
        return true;
    }
};