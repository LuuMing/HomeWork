class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> base= {1};
        for(int i = 1; i <= numRows; i++ )
        {
            result.push_back(base);
            base.push_back(0);
            for(int j = base.size() - 1; j >= 1; j--)
            {
                base[j] += base[j-1];
            }
        }
        return result;
    }
};
