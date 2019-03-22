class Solution {
public:
    unordered_map<char,int> m;
    string frequencySort(string s) {
        string ret = "";
        vector<string> bucket(s.size() + 1 , "");
        for(auto & c :s)
            m[c] ++;
        for(auto & it: m)
        {
            bucket[it.second].append(it.second,it.first);
        }
        for(int i = bucket.size() - 1; i >= 0 ; --i)
        {
            if( !bucket[i].empty() )
                ret.append(bucket[i]);
        } 
        return ret;
    }
};
