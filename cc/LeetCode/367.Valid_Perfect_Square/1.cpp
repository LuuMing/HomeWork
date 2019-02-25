class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        int lo = 0, hi = num / 2 + 1;
        while(lo <= hi)
        {
            long long mid = (lo + hi) / 2;
            long long cmp = mid * mid;
            if(cmp > num )
            {
                hi = mid - 1;
            }
            else if( cmp < num )
            {
                lo = mid + 1;
            }
            else
                return true;
        }
        return false;
    }
};
