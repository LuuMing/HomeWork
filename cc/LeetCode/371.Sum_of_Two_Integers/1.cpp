class Solution {
public:
    int getSum(int a, int b) {
       int ret = 0;
        int carry = 0;
        int mask = 0x00000001;
        for(int i = 0; i < 31; i++)
        {
            ret |= mask & ( a ^ b ^ carry );
            carry = mask & ( (a & b) | (b & carry) | (a & carry));
            mask <<= 1;
            carry <<= 1;
        }
        ret |= mask & ( a ^ b ^ carry );
        return ret;
    }
};
