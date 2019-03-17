class Solution {
public:
    vector<string> board;
    vector<vector<string>> ret;
    vector<bool> colum,cross_left,cross_right;
    int N;
    void dfs (int row)
    {
        if(row == N)
        {
            ret.push_back(board);
            return;
        }
        else
        {
            for(int i = 0; i < N; i++)
            {
                if( !colum[i] && !cross_left[ i - row + N]  && !cross_right[ i + row ] )
                {
                    board[row][i] = 'Q';
                    colum[i] = true;
                    cross_left [ i - row + N] = true;
                    cross_right [i + row] = true;
                    dfs(row + 1);
                    board[row][i] = '.';
                    colum[i] = false;
                    cross_left[ i - row + N ] = false;
                    cross_right [i + row] = false;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n,string(n,'.'));
        colum.resize(n,false);
        cross_left.resize( 2 * n ,false);
        cross_right.resize(2 * n ,false);
        N = n;
        dfs(0);
        return ret;
    }
};
