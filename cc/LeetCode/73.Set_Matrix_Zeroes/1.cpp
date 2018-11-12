class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> r,c;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(!matrix[i][j])
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        vector<int> zero(matrix[0].size(),0);
        for(auto & i:r)
        {
            matrix[i] = zero;
        }
        for(auto & cc:c)
        {
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][cc] = 0;
        }
    }
};
