struct cmp{
        bool operator()(const  pair <int,int> &p1,const pair <int,int>& p2)const {
            if(p1.second != p2.second)
                return p1.second > p2.second;
            else
                return p1.first < p2.first;
        }
    };
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        set<pair<int,int>, cmp> s;
        map<int,int> m;
        vector<int> ret;
        for(auto & n : nums){
            s.erase(make_pair(n,m[n]));
            s.insert(make_pair(n,++m[n]));
        }
        int cnt = 0;
        for(auto it = s.begin(); it != s.end() && cnt < k  ;it++,cnt++)
            ret.push_back(it->first);
        return ret;
    }
};
