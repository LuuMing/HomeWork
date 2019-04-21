class Solution {
public:
    vector<int> perfect;
    int Min = INT_MAX;
    void search(int idx, int res, int step)
    {
        if(res == 0)
        {
            Min = min(Min, step);
            return;
        }
        if(res < 0 || idx < 0)
            return;
        int cnt = 1;
        while((cnt + 1 ) * perfect[idx] <= res)
            cnt++;
        if(cnt * perfect[idx] <= res)
            search(idx - 1, res - cnt * perfect[idx],step + cnt);
        search(idx - 1 , res,step );
    }
    int numSquares(int n) {
        int i = 1;
        while( i * i <= n){
            perfect.push_back(i*i); 
            i++;
        }
        search(perfect.size() - 1, n, 0);
        return Min;
    }
};
