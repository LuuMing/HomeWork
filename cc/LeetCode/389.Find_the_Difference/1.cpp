class Solution {
public:
    char findTheDifference(string s, string t) {
        char XOR = 0;
        for(auto & c: s)
            XOR ^= c;
        for(auto & c: t)
            XOR ^= c;
        return XOR;
    }
};
