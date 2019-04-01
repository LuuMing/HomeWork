class Solution {
public:
    string reverseWords(string s) {
        int idx = 0;
        int preIdx = 0;
        while( idx < s.size())
        {
            while(s[idx] != ' ' && idx < s.size()) idx++;
            for(int i = preIdx,j = idx - 1; i < j; i++,j--)
            {
                swap(s[i], s[j]);
            }
            preIdx = idx + 1;
            idx++;
        }
        return s;
    }
};
