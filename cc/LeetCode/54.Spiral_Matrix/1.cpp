class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        vector<int> spiral;
        int rowS = 0;
        int rowE = matrix.size() - 1;
        int colS = 0;
        int colE = matrix[0].size() - 1;
        while(rowS <= rowE && colS <= colE)
        {
            if(rowS <= rowE)
                for(int col = colS; col <= colE; col++ )
                    spiral.push_back( matrix[rowS][col] );
            rowS++;
            
            if(colS <= colE)
                for(int row = rowS; row <= rowE; row++ )
                    spiral.push_back( matrix[row][colE] );
            colE--;
            
            if(rowS <= rowE)
                for(int col = colE; col >= colS; col-- )  
                    spiral.push_back( matrix[rowE][col] );
            rowE--;
            
            if(colS <= colE)
                for(int row = rowE; row >= rowS; row-- )
                    spiral.push_back( matrix[row][colS] );
            colS++;
        }
        return spiral;
    }
};
