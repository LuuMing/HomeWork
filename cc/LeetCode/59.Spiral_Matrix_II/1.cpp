class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n,vector(n,0));
        int rowS = 0;
        int rowE = n - 1;
        int colS = 0;
        int colE = n - 1;
        int cnt = 1;
        while(rowS <= rowE && colS <= colE)
        {
            if(rowS <= rowE)
                for(int col = colS; col <= colE; col++ )
                    spiral[rowS][col] = cnt++;
            rowS++;
            
            if(colS <= colE)
                for(int row = rowS; row <= rowE; row++ )
                    spiral[row][colE] = cnt ++;
            colE--;
            
            if(rowS <= rowE)
                for(int col = colE; col >= colS; col-- )  
                    spiral[rowE][col] = cnt++;
            rowE--;
            
            if(colS <= colE)
                for(int row = rowE; row >= rowS; row-- )
                    spiral[row][colS] = cnt++;
            colS++;
        }
        return spiral;
    }
};
