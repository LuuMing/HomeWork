class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        bool flag = true;
        for(int i = s.size() - 1; i >= 0 ; i--)
        {
            if( s[i] == ' ' )
            {
                if( flag )
                    continue;
                else
                    break;
            }
            else
            {
                l++;
                flag = false;
            }
        }
        return l;
        
    }
};
