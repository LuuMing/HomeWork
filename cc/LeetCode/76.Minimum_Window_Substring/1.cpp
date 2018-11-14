class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tmp_set,total_set;
        string result;
        int length = INT_MAX;
        for(auto & ii: t) total_set[ii]++;
        int current = 0;
        int left = 0, right = 0;
        int begin=0,end=0;
        while( right < s.size() )
        {
            while(current< t.size() && right < s.size())
            {
                if(total_set.count(s[right]))
                {
                    if( tmp_set[s[right]]++ < total_set[s[right]])
                        current++;
                }
                   right++;
            }
            while(current == t.size())
            {
                if(right - left < length && tmp_set.size() == total_set.size())
                {
                    length = right - left;
                    begin = left;
                    end = right;
                }
                if(tmp_set.count(s[left]))
                {
                    if(--tmp_set[s[left]] < total_set[s[left]])
                        current--;
                }
                left++;
            }
        }
        result = s.substr(begin,end-begin);
        return result;
    }
};
