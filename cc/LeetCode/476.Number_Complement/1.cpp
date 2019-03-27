class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        for(int tmp = num; tmp; tmp >>= 1)
        {
            num ^= mask;
            mask <<= 1;
        }
        return num;
    }
};
