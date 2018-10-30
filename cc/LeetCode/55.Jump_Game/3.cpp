class Solution {
public:
    int N;
    bool flag = false;
    vector<int> * p;
    void dfs(int current)
    {
        if(flag)
            return;
        if(current >= N)
        {
            flag = true;
            return;
        }
        else
        {
            for(int i = p->at(current); i > 0; i--)
                dfs(current + i);
        }
    }
    bool canJump(vector<int>& nums) {
        N = nums.size() - 1;
        p = &nums;
        dfs(0);
        return flag;
    }
};
