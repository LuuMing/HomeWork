class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for(int x = 0; x < N; x++)
        {
            for( int y = x + 1; y < N; y++)
                swap(matrix[x][y],matrix[y][x]);
        }
        for( auto & row:matrix)
            reverse(row.begin(),row.end());
    }
};
