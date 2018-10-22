class Solution {
public:
    vector<vector<int>> result;
    vector<bool> visit;
    int N;
    void dfs(vector<int> & nums, int s, vector<int> v)
    {
      if(s == 0)   // 若集合为空
      {
          result.push_back(v);
          return;
      }
      else
      {
          for(int i = 0; i < N; i++)
          {
            if(!visit[i])
            {
                visit[i] = true;
                v.push_back(nums[i]);
                dfs(nums,s - 1,v);
                v.pop_back();
                visit[i] = false;
            }
          }
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        visit.resize(N, false);
        dfs(nums,N,{});
        return result;
    }
};

