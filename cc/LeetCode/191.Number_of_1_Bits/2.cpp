class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bit32(n);
        return bit32.count();
    }
};
