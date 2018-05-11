class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> times;
        for(auto&i:nums)
        {
            times.insert(pair<int,int>(i,0));          //use map to store frequency
        }
        for(auto&i:nums)
        {
            times[i]++;                                //count frequence
        }
        vector<pair<int,int>> sort_vector;             //used for sort by map's value
        for(auto&i:times)
        {
            sort_vector.push_back(make_pair(i.first,i.second));
        }
        sort(sort_vector.begin(),sort_vector.end(),cmp);  //sort
        int max_number_times = sort_vector.front().second;  //record max char's frequency
        int min_l = 99999;
        for(auto&i:times)
        {
            if(max_number_times == i.second) 
            {
                int l = length(i.first,nums);           
                if(l < min_l)
                {
                    min_l = l;
                }
            }
        }
        return min_l;
    }
   static bool cmp( const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.second > b.second;
    }
    static int length(int max_number,vector<int> & nums)              //find first appear position. And last appear position. Two subtraction.
    {
        auto s = find(nums.begin(),nums.end(),max_number);            //Will get the shortest subarray of max degree.
        vector<int>::iterator e = vector<int>::iterator(find(nums.rbegin(),nums.rend(),max_number).base());
        int l = distance(s,e);
        return l;
    }
};
