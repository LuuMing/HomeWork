class Solution {
public:
    vector<bool> colum,cross_left,cross_right;
    int N;
    int cnt = 0;
    void dfs(int row)
    {
        if( row == N)
            cnt ++;
        else
        {
            for(int i = 0; i < N; i++)
            {
                if( !colum[i] && !cross_left[ i - row + N]  && !cross_right[ i + row ] )
                {
                    colum[i] = true;
                    cross_left [ i - row + N] = true;
                    cross_right [i + row] = true;
                    dfs(row + 1);
                    colum[i] = false;
                    cross_left[ i - row + N ] = false;
                    cross_right [i + row] = false;
                }
            }
        }
            
    }
    int totalNQueens(int n) {
        colum.resize(n,false);
        cross_left.resize( 2 * n ,false);
        cross_right.resize(2 * n ,false);
        N = n;
        dfs(0);
        return cnt;
    }
};
