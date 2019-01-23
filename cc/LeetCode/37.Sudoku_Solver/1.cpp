class Solution {
public:
    unordered_set<char> row[9];
    unordered_set<char> col[9];
    unordered_set<char> block[3][3];
    bool find = false;
    bool valid(int i, int j, char c)
    {
        return !(
            row[i].count(c) ||
            col[j].count(c) || 
            block[i/3][j/3].count(c)
        );
    }
    void dfs( int i, int j, vector<vector<char>> & board)
    {
        if(i == 9 && j == 0)
        {
            find = true;
            return;
        }
        if(find)
            return;
        if(board[i][j] == '.')
        {
            for(char c = '1'; c <= '9'; c++)
            {
                if(valid(i,j,c))
                {
                    board[i][j] = c;
                    row[i].insert(c);
                    col[j].insert(c);
                    block[i/3][j/3].insert(c);
                    if(j == 8)
                        dfs(i+1,0,board);
                    else
                        dfs(i,j + 1,board);
                    if(!find)
                    {
                        row[i].erase(c);
                        col[j].erase(c);
                        block[i/3][j/3].erase(c);
                        board[i][j] = '.';
                    }
                    else
                        return;
                }
            }
        }
        else
        {
            if(j == 8)
                dfs(i+1,0,board);
            else
                dfs(i,j + 1,board);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    char value = board[i][j];
                    row[i].insert(value);
                    col[j].insert(value);
                    block[i/3][j/3].insert(value);
                }
            }
        }
        dfs(0,0,board);
    }
};
