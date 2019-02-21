class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int lo1 = 0, lo2 = 0;
        while( lo1 < ransomNote.size() && lo2 < magazine.size())
        {
            if(magazine[lo2] < ransomNote[lo1] )
                lo2++;
            else if(magazine[lo2] > ransomNote[lo1])
                return false;
            else
            {   
                lo1++;
                lo2++;
            }
        }
        return lo1 == ransomNote.size();
    }
};
