class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    void dfs(int n,int idx,vector<int> & candidates)
    {
        n -= candidates[idx];
        tmp.push_back(candidates[idx]);
        if(n == 0)
        {
            result.push_back(tmp);
            tmp.pop_back();
            return ;
        }
        else if( n < 0)
        {
            tmp.pop_back();
            return ;
        }
        else
        {
            for(int i = idx; i < candidates.size(); i++)
            {
                dfs(n,i,candidates);
                
            }
        }
        tmp.pop_back();
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i = 0; i < candidates.size(); i++)
        {
            tmp.clear();
            dfs(target,i,candidates);
        }
        return result;
    }
};
