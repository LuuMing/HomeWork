class Solution {
public:
    map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},
                                 {'C',100},{'D',500},{'M',1000}};
    int romanToInt(string s) {
        if(s.empty())
            return 0;
        if(s.size() == 1)
            return m[s[0]];
        else 
        {
            if( m[s[1]] > m[s[0]] )
            {
                return -m[s[0]] + romanToInt(s.substr(1));
            }
            else
            {
                return m[s[0]] + romanToInt(s.substr(1));
            }
        }
    }
};