class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mark = 0;
        while( m != n )
        {
            m >>= 1;
            n >>= 1;
            mark++;
        }
        return (m << mark);
    }
};