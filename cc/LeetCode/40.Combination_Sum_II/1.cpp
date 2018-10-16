class Solution {
    vector<vector<int> > result;
    unordered_set<string> dict;
    vector<int> tmp;
    void dfs(int n,int idx,vector<int>& candidates)
    {
        tmp.push_back(candidates[idx]);
        n -= candidates[idx];
        if(n == 0)
        {
            string s;
            for(auto i:tmp)
                s.push_back(i);
            if(!dict.count(s))
            {
                result.push_back(tmp);
                dict.insert(s);
            }
            tmp.pop_back();
            return;
        }
        else if( n  < 0)
        {
            tmp.pop_back();
            return;
        }
        else
        {
            for(int i = idx + 1; i < candidates.size() ;i++)
            {
                    dfs(n,i,candidates);
            }
        }
        tmp.pop_back();
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        for(int i = 0; i < candidates.size(); ++i )
        {    
            dfs(target, i, candidates);
        }
         return result;
    }
};
