class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> dict;
        vector<int> result;
        if(words.empty()||s.empty()) return result;
        int len = words[0].size();
        int size = s.size();
        int num = words.size();
        for(auto str:words)
        {
            if( str.size() == len)
                dict[str]++;
            else
                return result;
        }
        for(int i = 0; i <= size - num * len; i++)
        {
            unordered_map<string,int> seen;
            int j = 0;
            for( j = 0; j < words.size(); j++)
            {
                string tmp = s.substr(i+j*len,len);
                if( dict.count(tmp) )
                {
                    seen[tmp]++;
                    if(seen[tmp] > dict[tmp])
                        break;
                }
                else
                    break;
            }
            if( j == words.size() )
                result.push_back(i);
        }
        return result;
    }
};
