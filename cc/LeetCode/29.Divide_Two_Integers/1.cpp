class Solution {
public:
    int divide(int dividend, int divisor) {
        if( dividend == divisor )
            return 1;
        int cnt = 0;
        for( int i = divisor; i>= 2; i >>= 2)
            cnt ++;
        double tmpDividend = dividend >> cnt;
        double temDivisor = (double)divisor / (1 << cnt);
        long tmp_res = tmpDividend / temDivisor;
        if( tmp_res > INT_MAX) 
            return INT_MAX;
        else if( tmp_res < INT_MIN)
            return INT_MIN;
        else 
            return tmp_res;
        }
};