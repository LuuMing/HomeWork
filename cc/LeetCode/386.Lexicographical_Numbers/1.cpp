class Solution {
public:
    static bool cmp(const int & i1, const int & i2)
    {
        return to_string(i1) < to_string(i2);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        for(int i = 0; i < n;i++)
            ret[i] = i + 1;
        sort(ret.begin(), ret.end(), cmp);
        return ret;
    }
};
