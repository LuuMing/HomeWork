class Solution {
public:
    string reverseVowels(string s) {
        int lo = 0, hi = s.size() - 1;
        unordered_set<char> vowelSet;
        vowelSet.insert('a');
        vowelSet.insert('e');
        vowelSet.insert('i');
        vowelSet.insert('o');
        vowelSet.insert('u');
        vowelSet.insert('A');
        vowelSet.insert('E');
        vowelSet.insert('I');
        vowelSet.insert('O');
        vowelSet.insert('U');
        while( lo < hi )
        {
            while( !vowelSet.count(s[hi]) && lo < hi )   hi--;
            while( !vowelSet.count(s[lo]) && lo < hi )  lo++;
            swap(s[lo],s[hi]);
            hi--,lo++;
        }
        return s;
    }
};
