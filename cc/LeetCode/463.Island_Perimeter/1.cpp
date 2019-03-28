class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total = 0;
        if(grid.empty())
            return 0;
        for(int y = 0; y < grid.size(); y++ ){
            for(int x = 0; x < grid[y].size(); x++ ){
                if( grid[y][x] == 0 ){
                    total += (x-1 >= 0)? grid[y][x-1] == 1 : 0;    
                    total += (x+1 < grid[y].size())? grid[y][x+1] == 1 : 0;
                    total += (y-1 >= 0)? grid[y-1][x] == 1 : 0;
                    total += (y+1 < grid.size())? grid[y+1][x] == 1 : 0;
                }else{
                        total +=  (x == 0)? 1 :0;
                        total +=  (x == grid[y].size() - 1)? 1 :0;
                        total +=  (y == 0)? 1 :0;
                        total +=  (y == grid.size() - 1)? 1:0;
                }
            }
        }
        return total;
    }
};
