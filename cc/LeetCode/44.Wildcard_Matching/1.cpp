class Solution {
public:
    bool isMatch(string s, string p) {
        int idxS = 0, idxP = 0, start = -1, ss = 0;
        while( idxS < s.size() )
        {
            if( s[idxS] == p[idxP] || p[idxP] == '?')
            {
                idxS++,idxP++;
                continue;
            }
            if( p[idxP] == '*' )
            {
                start = idxP++;
                ss = idxS;
                continue;
            }
            if( start != -1)
            {
                idxP = start;
                idxS = ++ss;
                continue;
            }
            cout << idxP << ' ' << idxS << endl;
            if(s[idxS] != p[idxP] )
            {
                return false;
            }
        }
        while( p[idxP] == '*') idxP++;
        return idxP == p.size();
    }
};
