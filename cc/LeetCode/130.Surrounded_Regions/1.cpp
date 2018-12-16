class Solution {
public:
    int r;
    int c;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    vector<vector<char>> mark;
    vector<vector<char>> * pBoard;
    void book(int x,int y)
    {
        if(x >= 0 && x < r && y >=0 && y < c && mark[x][y] == 0 && (*pBoard)[x][y] == 'O')
        {
            mark[x][y] = 1;
            for(int i = 0; i < 4; i++)
            {
                book(x+dx[i],y+dy[i]);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        r = board.size();
        c = board[0].size();
        pBoard = &board;
        mark.resize(r,vector<char>(c,0));
        for(int i = 0; i < r; i++) 
        {    
            if(board[i][0]=='O')  { book(i,0);}
            if(board[i][c-1]=='O')  { book(i,c-1);}    
        }
        for(int i = 0; i < c; i++) 
        {    
            if(board[0][i]=='O')  { book(0,i);}
            if(board[r-1][i]=='O')  { book(r-1,i);}    
        }
        for(int i = 0; i < r;i++)
            for(int j = 0; j < c; j++)
                board[i][j] = ( mark[i][j] == 0 )?'X':'O';
    }
};
