class Solution {
public:
    vector<vector<bool>> visit;
    int rowSize;
    int columSize;
    void dfs( int x, int y,vector<vector<char>> & grid)
    {
        visit[x][y] = true;
        if( grid[x][y] =='0' )
            return;
        int dx[] ={1,-1,0,0};
        int dy[] = {0,0,1,-1};
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && yy >= 0 && xx < rowSize && yy < columSize && !visit[xx][yy] )
                dfs(xx,yy,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        rowSize = grid.size();
        if(rowSize > 0)
        {
            columSize = grid[0].size();
            visit.resize(grid.size(),vector<bool>(grid[0].size(),false));
        }
            
        for(int x = 0; x < grid.size(); x++)
        {
            for( int y = 0; y < grid[x].size(); y++)
            {
                if(grid[x][y] == '1' &&!visit[x][y])
                {
                    dfs(x,y,grid);
                    num ++;
                }
            }
        }
        return num;
    }
};
