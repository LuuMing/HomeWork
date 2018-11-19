int N;
int M;
int len;
int * visit;
bool dfs(int x, int y, int idx,char * word, char ** board)
{
    visit[x*M+y] = 1;
    if(idx == len - 1)
        return true;
    else
    {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        for(int i = 0; i < 4;i++)
        {
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if( (n_x >= 0 ) && (n_x < N )&& (n_y >= 0) && (n_y < M) )
            {
                if(visit[n_x* M + n_y] == 0 && word[idx + 1] == board[n_x][n_y])
                {
                 if( dfs(n_x,n_y,idx+1,word,board) )
                    return true;
                    visit[n_x*M+n_y] = 0;
                }
            }
        }
    }
    return false; 
}
bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
     N = boardRowSize;
     M = boardColSize;
    len = strlen(word);
    visit = (int *)malloc(sizeof(int) * N * M);
    for(int i = 0; i < N;i ++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == word[0])
            {
                    memset(visit,0,sizeof(int) * N * M);
                    if(dfs(i,j,0,word,board))
                        return true;
            }
        }
    }
    return false;
}
