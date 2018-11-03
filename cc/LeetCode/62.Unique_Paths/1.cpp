class Solution {
public:
    int map[101][101];
    int uniquePaths(int m, int n) {
        map[0][0] = 1;
        for(int i = 0 ;i < m;i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j != 0)
                    map[i][j] += map[i][j-1];
                else if( j == 0 && i != 0)
                    map[i][j] += map[i-1][j] ;
                else if( i == 0 && j == 0)
                    continue;
                else 
                    map[i][j] = map[i-1][j]+map[i][j-1] ;
            }
        }

        return map[m-1][n-1];
    }
};
