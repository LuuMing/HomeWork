class Solution {
    unordered_map<string,int> m;
    vector<string> result;
public:
    
    vector<string> findRepeatedDnaSequences(string s) {
        if( s.size() < 10 )
            return{};
        string roll = s.substr(0,10);
        m[roll]++;
        int lo = 1;
        while( lo < s.size() - 9 )
        {
            string substr = s.substr(lo,10);
            if( ++m[substr] == 2)
            {
                result.push_back(substr);
            }
            lo++;
        }
        return result;
    }
};
