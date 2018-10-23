class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string >> result;
        vector<string> t_strs = strs;
        unordered_map<string,vector<int> > m;
        for(auto &i:t_strs)
        {
           sort(i.begin(),i.end());    
        }
        for(int i = 0; i < t_strs.size(); i++)
        {
                m[t_strs[i]].push_back(i);
        }
        for(auto i:m)
        {
            vector<string> t;
            for(auto j:i.second)
            {
                t.push_back(strs[j]);
            }
            result.push_back(t);
        }
        return result;
    }
};
