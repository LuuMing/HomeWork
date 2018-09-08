class Solution {
    set<set<int>> ss;
    vector<vector<int>> result;
    void find_2(int num,int idx, vector<int> & nums)
    {
        unordered_set<int> s;
        vector<int> v;
        v.push_back(num);
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == idx)
                continue;
            if( s.count(-num - nums[i]))
            {
                set<int> s;
                s.insert(num);
                s.insert(nums[i]);
                s.insert(-num-nums[i]);
                if(ss.count(s))
                    continue;
                ss.insert(s);
                vector<int> vv = v;
                vv.push_back(nums[i]);
                vv.push_back(-num - nums[i]);
                for(int j = 0; j < vv.size(); j++)
                {
                    cout << vv[j] <<' ';
                }
                cout << endl;
                result.push_back(vv);
            }
            else
            {
                s.insert(nums[i]);
            }
        }
         
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            find_2(nums[i],i,nums);
        return result;
    }
};

