class Solution {
public:
    vector<vector<int> > result;
    void dfs(vector<int> & nums, int idx,vector<int> tmp,int s, int target)
    {
        if(idx > nums.size() || tmp.size() > 4)
            return;
        s += nums[idx];
        tmp.push_back(nums[idx]);
        if(tmp.size() == 4 && s ==target)
        {
           result.push_back(tmp);
            return;
        }
        idx++;
        while(idx < nums.size())
        {
            dfs(nums,idx++,tmp,s,target);
            while(nums[idx] == nums[idx - 1]) idx++;
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > zero;
        if(nums.size() == 0)
            return zero;
        vector<int> tmp;
        sort(nums.begin(),nums.end());       
        //for(auto ii:nums)
         //   cout << ii <<' ';
        //cout << endl;
        
        dfs(nums,0,tmp,0,target);
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] ==  nums[i-1])
                continue;
                         dfs(nums,i,tmp,0,target);
           
        }
        return result;
    }
};
