class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> base= {1};
        for(int i = 0; i < rowIndex; i++ )
        {
            base.push_back(0);
            for(int j = base.size() - 1; j >= 1; j--)
            {
                base[j] += base[j-1];
            }
        }
        return base;
    }
};
