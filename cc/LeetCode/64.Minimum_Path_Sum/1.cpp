class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i,j;
        for( i = 0; i < grid.size(); i++)
        {
            for( j = 0; j < grid[i].size();j++)
            {
                if( i == 0 && j == 0)
                    continue;
                if( j == 0 )
                {
                    grid[i][j] += grid[i-1][j];
                    continue;
                }
                if( i == 0)
                {
                    grid[i][j] += grid[i][j-1];
                    continue;
                }
                grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[i-1][j-1];
    }
};
