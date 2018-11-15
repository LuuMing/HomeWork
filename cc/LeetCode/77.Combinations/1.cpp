class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> result;
    int N;
    int K;
    void dfs(vector<int> tmp,int n)
    {
        tmp.push_back(n);
        if(tmp.size() == K)
        {
            result.push_back(tmp);
            return;
        }
        for(int i = n + 1; i <= N; i++)
        {
            dfs(tmp,i);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        N = n;
        K = k;
        vector<int> tmp;
        for(int i = 1; i <= n;i++)
            dfs(tmp,i);
        return result;
    }
};
