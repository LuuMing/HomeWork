class Solution {
public:
    int hammingDistance(int x, int y) {
    int count = 0, n = x ^ y;
        while(0 < n)
        {
            n &= (n--);
            count++;
        }
        return count;
    }
};
