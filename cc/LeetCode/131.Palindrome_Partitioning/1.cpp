class Solution {
public:
    vector<vector<string>> result;
    vector<string> tmp;
    bool valid(string s)
    {
        int i = 0, j = s.size() - 1;
        for(; i < j; i++,j--)
            if(s[i]!=s[j])
                return false;
        return true;
    }
    void dfs(int idx,string & s)
    { 
        if(idx == s.size())
        {
            result.push_back(tmp);
        }
        for(int l = 1; l <= s.size() - idx; l++)
        {
            string t = s.substr(idx,l);
            if(valid(t))
            {
                tmp.push_back(t);
                dfs(idx+l,s);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(0,s);
        return result;
    }
};
