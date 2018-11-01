class Solution {
public:
    int fact[10];
    void init_lookup_table(int n)
    {
        fact[0] = 1;
        for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    }
    string getPermutation(int n, int k) {
        k--;
        init_lookup_table(n);
        for(int i = 0; i <= 9; i++)
            cout << fact[i] <<' ';
        string nums,result;
        for(int i = 1; i <= n;i++)
            nums.push_back( i + '0');
        for(int i = n - 1; i >= 1; i--)
        {
            int idx = k / fact[i];
            k = k % fact[i];
            result.push_back(nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        result.push_back(nums[0]);
        return result;
    }
};
