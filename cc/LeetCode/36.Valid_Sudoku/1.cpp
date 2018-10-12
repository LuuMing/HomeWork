class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> block[3][3];
        unordered_set<char> colum[9];
        for(int i = 0; i < 9; i++)
        {
            unordered_set<char> row;
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                if( (row.count(board[i][j]) || colum[j].count( board[i][j] ) || block[i/3][j/3].count(board[i][j]) ))
                {   
                    return false; 
                }
                else    
                {
                    row.insert(board[i][j]);
                    colum[j].insert(board[i][j]);
                    block[i / 3][j / 3].insert(board[i][j]);
                    
                }
            }
        }
        return true;
    }
};
