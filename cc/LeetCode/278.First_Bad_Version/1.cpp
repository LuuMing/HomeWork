// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long  l = 1;
        while(l < n)
        {
            long  mid = (l + n) / 2;
            if( !isBadVersion(mid) )
            {
                l = mid + 1;
            }
            else
            {
                n = mid ;
            }
        }
        return l;
    }
};
