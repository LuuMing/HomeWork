ass Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> map = obstacleGrid;
        int i,j;
        map[0][0] = 1;
        for( i = 0; i < map.size(); i++)
        {
            for(j = 0; j < map[i].size(); j++)
            {
                if(obstacleGrid[i][j] == 1)
                    map[i][j] = 0;
                else
                {
                    if( i == 0 && j != 0)
                    {
                        map[i][j] = map[i][j-1];
                    }
                    else if( j == 0 && i != 0)
                    {
                        map[i][j] = map[i-1][j];
                    }
                    else if( i==0 && j == 0)
                        continue;
                    else
                    {
                        map[i][j] = map[i-1][j] + map[i][j-1];
                    }
                }
            }
        }
        return map[i-1][j-1];
    }
};
